#ifndef SZUKAJ_H
#define SZUKAJ_H

#include <QDialog>
#include <QSerialPort>
#include <QDebug>
#include <QList>
#include <QSerialPortInfo>
#include <QDateTime>
#include <sstream>
#include <string>

typedef unsigned char byte;
#define POLYNOMIAL_9 0x0161

namespace Ui {
class Szukaj;
}

class Szukaj : public QDialog {
    Q_OBJECT

public:
    explicit Szukaj(QWidget *parent = nullptr);
    ~Szukaj();

private slots:
    void on_pushButtonSzuk_clicked();
    void on_pushButtonPolacz_clicked();
    void on_pushButtonRozlacz_clicked();
    void addToLogs(QString message);
    void readFromPort();
    void sendMessageToDevice(QString message);
    unsigned int CRC8_SingleByte(unsigned int Data);
    byte CRC8_DataArray(byte *pData);
    bool ParseDataFrame(std::string pDataFrame);

signals:
    void otrzymanieDanych(int x);

private:
    Ui::Szukaj *ui;
    QSerialPort *device;
};

#endif // SZUKAJ_H
