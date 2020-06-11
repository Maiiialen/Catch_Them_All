#ifndef GRACZ_H
#define GRACZ_H

/*!
* \file
* \brief Definicja klasy Gracz
*
* Plik zawiera definicję klasy Gracz, która
* odpowiada za obiet gracza i jest pochodną
* klas QObject oraz QGraphicsItem
*
*/

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>

class Gracz:public QObject, public QGraphicsItem {
public:
    /*!
    * \brief Kontruktor klasy
    *
    * Funkcja inicjalizuje zmienne w obiekcie gracza
    */
    Gracz(QGraphicsScene *_scena);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    /*!
    * \brief Funkcja ustawiająca współrzędną OX
    *
    * Funkcja ustawia współrzędną OX na zadaną wartość
    */
    void SetX();
    /*!
    * \brief Funkcja obsługująca zderzenie
    *
    * Funkcja obsługująca zderzenie
    */
    void boom();
    /*!
    * \brief Funkcja zwracająca ilość zdobytych punktów
    *
    * Funkcja zwracająca wartość zmiennej
    * przechowującej ilość zdobytych punktów
    *
    * \return Zwraca ilość zdobytych punktów
    */
    int getPunkty();
    /*!
    * \brief Funkcja obsługująca zapisyzwanie liczby zdobytych punktów
    *
    * Funkcja ustawia wartość zmiennej
    * przechowującej ilość zdobytych punktów
    */
    void setPunkty(int liczba);
    /*!
    * \brief Funkcja ustawiająca wartość chwilowej prędkości
    *
    * Funkcja ustawia wartość obecnej prędkości
    */
    void setPredkosc();
    /*!
    * \brief Funkcja zapisująca ostatnią odczytaną wartość z czujnika
    *
    * Funkcja ustawia wartość zmiennej przechowującej
    * wartość pobraną z czunjnika
    */
    void setAccX(int liczba);
    /*!
    * \brief Funkcja zwracająca ostatnią odczytaną wartość z czujnika
    *
    * Funkcja zwracająca wartość zmiennej
    * przechowującej wartość pobraną z czunjnika
    *
    * \return Zwraca najnowszą wartość pobraną z czunjnika
    */
    int getAccX();

private:
    /*!
    * \brief Współrzędna na osi OX
    *
    * Współrzędna na osi OX
    * Wartość zmieniana przy ruchu obiektu
    */
    int x;
    /*!
    * \brief Współrzędna na osi OY
    *
    * Współrzędna na osi OY
    * Wartość niezmienna
    */
    int y;
    /*!
    * \brief Wartość odchylenia
    *
    * Wartość odchylenia, zczytana
    * z czujnika, wartość wyrażona
    * w jednostkach niemiarowych.
    */
    int AccX;
    /*!
    * \brief Wartość prędkości obiektu
    *
    * Wartość chwilowej prędkości obiektu
    * zmieniana na podstawie odchylenia czujnika
    */
    int predkosc;
    /*!
    * \brief Kierunek ruchu
    *
    * Wartość odzwierciedlająca kierunek ruchu
    * obiektu, zmieniana na podstawie danych z czujnika
    */
    int kierunek;
    /*!
    * \brief Punkty uzyskane w grze
    *
    * Wartość odzwierciedlająca ilość
    * zdobytych punktów
    */
    int punkty;
    /*!
    * \brief Obiekt sceny
    *
    * Wskaźnik na scenę, pozwala na umieszczenie na niej obiektów
    */
    QGraphicsScene *scena;
    /*!
    * \brief Obiekt obrazka
    *
    * Obiekt pozwalający na wczytanie obrazke
    * i przypisanie go tdo obiektu Gracza
    */
    QPixmap obrazek;
    /*!
    * \brief Obiekt gracza
    *
    * Obiekt wczytywany na scenę
    */
    QGraphicsPixmapItem *obiekt;

public slots:
    /*!
    * \brief Funkcja aktualizująca dane w obiekcie
    *
    * Funkcja aktualizująca dane w obiekcie z częstotliwością
    * zmiennej czasowe z którą jest połączona
    */
    void advance(int phase) override;
};

#endif // GRACZ_H
