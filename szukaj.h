#ifndef SZUKAJ_H
#define SZUKAJ_H

/*!
* \file
* \brief Definicja klasy Szukaj
*
* Plik zawiera definicję klasy Szukaj, która
* odpowiada za okno do wyszukiwania urządzeń
* oraz łączenia się z urządzeniami zdalnymi
* i jest pochodną klasy QDialog
*
*/

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
    /*!
    * \brief Konstruktor klasy
    *
    * Funkcja inicjalizuje zmienne
    */
    explicit Szukaj(QWidget *parent = nullptr);
    /*!
    * \brief Destruktor klasy
    *
    * Destruktor klasy
    */
    ~Szukaj();

private slots:
    /*!
    * \brief Funkcja obsługująca wciśnięcie przycisku ,,Szukaj''
    *
    * Funkcja odsługująca wciśnięcie przycisku ,,Szukaj''
    */
    void on_pushButtonSzuk_clicked();
    /*!
    * \brief Funkcja obsługująca wciśnięcie przycisku ,,Połącz''
    *
    * Funkcja odsługująca wciśnięcie przycisku ,,Połącz''
    */
    void on_pushButtonPolacz_clicked();
    /*!
    * \brief Funkcja obsługująca wciśnięcie przycisku ,,Rozłącz''
    *
    * Funkcja odsługująca wciśnięcie przycisku ,,Rozłącz''
    */
    void on_pushButtonRozlacz_clicked();
    /*!
    * \brief Funkcja obsługująca wypisywanie w logu
    *
    * Funkcja odsługująca wypisywanie w logu
    */
    void addToLogs(QString message);
    /*!
    * \brief Funkcja obsługująca zczytywanie danych z portu
    *
    * Funkcja odsługująca zcczytywanie danych z portu
    */
    void readFromPort();

    /*!
    * \brief Funkcja licząca sumę kontrolną
    *
    * Funkcja licząca sumę kontrolną
    */
    unsigned int CRC8_SingleByte(unsigned int Data);
    /*!
    * \brief Funkcja licząca sumę kontrolną
    *
    * Funkcja licząca sumę kontrolną
    */
    byte CRC8_DataArray(byte *pData);
    /*!
    * \brief Funkcja sprawdzająca poprawność sumy kontrolnej
    *
    * Funkcja sprawdzająca poprawność sumy kontrolnej
    */
    bool ParseDataFrame(std::string pDataFrame);

signals:
    /*!
    * \brief Funkcja obsługująca przesyłanie danych pobranych z czunika
    *
    * Funkcja odpowiadająca za przesłanie wartości odebranych z
    * czujnika oraz przekonwertowaie ich na wartości rzeczywiste
    * mozliwe do wyświelenia na wykresie
    */
    void otrzymanieDanych(int x);
    /*!
    * \brief Funkcja obsługująca pasek stanu
    *
    * Funkcja odpowiadajaca za pasek stanu ukazujący czy
    * nawiązana jest komunikacja z czujnikiem
    */
    void stan(int czyWlaczone);

private:
    /*!
    * \brief Obiekt ui
    *
    * Wskaźnik na obiekt interfejsu użytkownika
    */
    Ui::Szukaj *ui;
    /*!
    * \brief Port danych
    *
    * Wskaźnik na port, z którego zczytywane są dane
    */
    QSerialPort *device;
};

#endif // SZUKAJ_H
