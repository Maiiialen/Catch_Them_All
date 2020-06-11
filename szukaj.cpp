#include "szukaj.h"
#include "ui_szukaj.h"

Szukaj::Szukaj(QWidget *parent): QDialog(parent), ui(new Ui::Szukaj) {
    ui->setupUi(this);
    this->device = new QSerialPort(this);
}

Szukaj::~Szukaj() {
    delete ui;
}

void Szukaj::addToLogs(QString message) {
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEditLogs->append(currentDateTime + "\t" + message);
}

void Szukaj::on_pushButtonSzuk_clicked() {
    this->addToLogs("Szukam urządzeń...");
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();

    for(int i = 0; i < devices.count(); i++) {
      this->addToLogs("Znalazłem urządzenie: " + devices.at(i).portName() + " " + devices.at(i).description());
      ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
    }
}

void Szukaj::on_pushButtonPolacz_clicked() {
    if(ui->comboBoxDevices->count() == 0) {
      this->addToLogs("Nie wykryto żadnych urządzeń!");
      return;
    }

    QString portName = ui->comboBoxDevices->currentText().split("\t").first();
    this->device->setPortName(portName);

    // OTWÓRZ I SKONFIGURUJ PORT:
    if(!device->isOpen()) {
        if(device->open(QSerialPort::ReadWrite)) {
          this->device->setBaudRate(QSerialPort::Baud9600);
          this->device->setDataBits(QSerialPort::Data8);
          this->device->setParity(QSerialPort::NoParity);
          this->device->setStopBits(QSerialPort::OneStop);
          this->device->setFlowControl(QSerialPort::NoFlowControl);

          this->addToLogs("Otwarto port szeregowy.");
          connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));
          this->stan(1);
        } else {
          this->addToLogs("Otwarcie portu szeregowego się nie powiodło!");
        }
    } else {
      this->addToLogs("Port już jest otwarty!");
      return;
    }
}

void Szukaj::on_pushButtonRozlacz_clicked() {
    if(this->device->isOpen()) {
      this->device->close();
      this->addToLogs("Zamknięto połączenie.");
      this->stan(0);
    } else {
      this->addToLogs("Port nie jest otwarty!");
      return;
    }
}

void Szukaj::readFromPort() {
  while(this->device->canReadLine()) {
    QString line = this->device->readLine();
    //qDebug() << line;

    QString terminator = "\r";
    int pos = line.lastIndexOf(terminator);
    //qDebug() << line.left(pos);

    this->addToLogs(line.left(pos));    //line.left(pos) - użyć do funkcji dalej
    ParseDataFrame(line.left(pos).toStdString());
  }
}

unsigned int Szukaj::CRC8_SingleByte(unsigned int Data) {
    unsigned int Poly = (POLYNOMIAL_9 << 7);
    for(byte Idx=0; Idx<8; ++Idx){
        if((Data & 0x8000) != 0){
            Data ^= Poly;
        }
        Data <<= 1;
    }
    return Data;
}

byte Szukaj::CRC8_DataArray(byte *pData) {
    unsigned int  Data = pData[0] << 8;
    for(unsigned int  Idx=0; Idx<1; ++Idx) {
        Data |= pData[Idx];
        Data = CRC8_SingleByte(Data);
    }
    Data = CRC8_SingleByte(Data);
    return (byte)(Data>>8);
}

bool Szukaj::ParseDataFrame(std::string pDataFrame) {
    int AccX;
    std::istringstream IStrm(pDataFrame);
    char FHeader;
    unsigned int CRC8;
    //byte* pDataFrame1 = <byte*>pDataFrame;
    IStrm >> FHeader >> AccX >> std::hex >> CRC8;
    unsigned char charAccX = char(AccX);
    //unsigned char tablica[1] = {charAccX};
    if(IStrm.fail() || FHeader != 'X'){
        return false;
    }
    //qDebug() << static_cast<byte>(CRC8) << "  " << CRC8_DataArray(static_cast<byte*>(tablica));
    //qDebug() << static_cast<byte>(CRC8) << "  " << CRC8_DataArray(&charAccX);
    if(static_cast<byte>(CRC8) == CRC8_DataArray(&charAccX)) {
        otrzymanieDanych(AccX);
        return 1;
    } else
        return 0;
}
