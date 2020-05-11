#ifndef SZUKAJ_H
#define SZUKAJ_H

#include <QDialog>
#include <QSerialPort>
#include <QDebug>
#include <QList>
#include <QSerialPortInfo>
#include <QDateTime>

namespace Ui {
class Szukaj;
}

class Szukaj : public QDialog
{
    Q_OBJECT

public:
    explicit Szukaj(QWidget *parent = nullptr);
    ~Szukaj();

private slots:
    void on_pushButtonSzuk_clicked();
    void on_pushButtonPolacz_clicked();
    void on_pushButtonRozlacz_clicked();
    void addToLogs(QString message);

private:
    Ui::Szukaj *ui;
    QSerialPort *device;
};

#endif // SZUKAJ_H
