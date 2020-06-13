#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
* \file
* \brief Definicja klasy MainWindow
*
* Plik zawiera definicję klasy MainWindow, która
* odpowiada za okno główne aplikacji i jest pochodną
* klasy QMainWindow
*
*/

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>
#include <QObject>
#include <QtCharts>
#include "owoc.h"
#include "obiektkalibracyjny.h"
#include "szukaj.h"
#include "wynik.h"
//#include "gracz.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy
    *
    * Funkcja inicjalizuje zmienne
    */
    MainWindow(QWidget *parent = nullptr);
    /*!
    * \brief Destruktor klasy
    *
    * Destruktor klasy MainwWndow
    */
    ~MainWindow();

private:
    /*!
    * \brief Obiekt ui
    *
    * Wskaźnik na obiekt interfejsu użytkownika
    */
    Ui::MainWindow *ui;
    /*!
    * \brief Obiekt sceny
    *
    * Wskaźnik na scenę, pozwala na umieszczenie na niej obiektów
    */
    QGraphicsScene *Scene;
    /*!
    * \brief Lista wartości odebranych z czujnika
    *
    * Wskaźnik na listę wartości odebranych z czujnika
    */
    QSplineSeries *series;
    /*!
    * \brief Obiekt będący tłem gry
    *
    * Wskaźnik na listę wartości odebranych z czujnika
    */
    ObiektKalibracyjny *tlo;
    /*!
    * \brief Obiekt owoc
    *
    * Wskaźnik na jeden ze spadających obiektów
    */
    Owoc *owoc1;
    /*!
    * \brief Obiekt owoc
    *
    * Wskaźnik na jeden ze spadających obiektów
    */
    Owoc *owoc2;
    /*!
    * \brief Obiekt owoc
    *
    * Wskaźnik na jeden ze spadających obiektów
    */
    Owoc *owoc3;
    /*!
    * \brief Obiekt owoc
    *
    * Wskaźnik na jeden ze spadających obiektów
    */
    Owoc *owoc4;
    /*!
    * \brief Obiekt owoc
    *
    * Wskaźnik na jeden ze spadających obiektów
    */
    Owoc *owoc5;
    /*!
    * \brief Obiekt gracz
    *
    * Wskaźnik na obiekt gracza
    */
    Gracz *gracz;
    /*!
    * \brief Obiekt timer
    *
    * Wskaźnik na jeden ze spadających obiektów
    */
    QTimer *czas;
    QTimer *czas1;
    QTimer *czasGry;
    /*!
    * \brief Wskaźnik na okno
    *
    * Wskaźnik na okno połączenia, w którym
    * połączyć się można z czujnikiem
    */
    Szukaj *Okno;
    /*!
    * \brief Wskaźnik na okno
    *
    * Wskaźnik na okno z wynikiem, które
    * pojawia się na koniec gry
    */
    Wynik *OknoWyniku;
    /*!
    * \brief Ilość zapisanych pomiarów
    *
    * Ilość zapisanych wartości pomiarowych z
    * czujnika, wykorzystywanych do wyświetlenia na wykresie
    */
    int pomiary;
    /*!
    * \brief Zmienna określająca czy gra już się zaczęła
    *
    * Zmienna określająca czy gra już się zaczęła,
    * wykorzystywana do zabezpieczenia przed restartem w trakcie gry,
    * przyjmuje wartości 0 lub 1
    */
    int czyBylStart;
    /*!
    * \brief Zmienna określająca ile trwa już gra
    *
    * Zmienna określająca w sekundach ile trwa już gra
    */
    int obecnyCzasGry;
    /*!
    * \brief Zmienna osi OY na wykresie
    *
    * Wskaźnik na zmienną odpowiadającą za oś OY
    * na wykresie, pozwala na podpisanie osi oraz
    * ustawienie zasięgu wyświetlania
    */
    QValueAxis *osY;
    /*!
    * \brief Zmienna osi OX na wykresie
    *
    * Wskaźnik na zmienną odpowiadającą za oś OX
    * na wykresie, pozwala na podpisanie osi oraz
    * ustawienie zasięgu wyświetlania
    */
    QValueAxis *osX;

public slots:
    /*!
    * \brief Funkcja obsługująca zapisywanie punktów
    *
    * Funkcja odpowiadająca za zwiększanie zapisanej
    * liczby zdobytych punktów
    */
    void aktualizacjaPunktow();
    /*!
    * \brief Funkcja obsługująca zakończenie gry
    *
    * Funkcja usuwająca obiekty ze sceny, wywołująca destruktory
    */
    void koniecGry();
    /*!
    * \brief Funkcja obsługująca wciśnięcie przycisku ,,Szukaj''
    *
    * Funkcja odsługująca wciśnięcie przycisku ,,Szukaj''
    */
    void on_pushButtonSzukaj_clicked();
    /*!
    * \brief Funkcja obsługująca wciśnięcie przycisku ,,Start Gry''
    *
    * Funkcja odsługująca wciśnięcie przycisku ,,Start Gry''
    */
    void on_pushButtonStartGry_clicked();
    /*!
    * \brief Funkcja obsługująca przesyłanie danych pobranych z czunika
    *
    * Funkcja odpowiadająca za przesłanie wartości odebranych z
    * czujnika oraz przekonwertowaie ich na wartości rzeczywiste
    * mozliwe do wyświelenia na wykresie
    * \param[in] x - wartość pobrana z czujnika
    */
    void odebranieDanych(int x);
    /*!
    * \brief Funkcja obsługująca pasek stanu
    *
    * Funkcja odpowiadajaca za pasek stanu ukazujący czy
    * nawiązana jest komunikacja z czujnikiem
    * \param[in] czyWlaczone - wartość 0 lub 1 oznaczająca czy połączenie z czujnikiem jest nawiązane
    */
    void Stan(int czyWlaczone);
};
#endif // MAINWINDOW_H
