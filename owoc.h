#ifndef OWOC_H
#define OWOC_H

/*!
* \file
* \brief Definicja klasy Owoc
*
* Plik zawiera definicję klasy Owoc, która
* odpowiada za obiekty spadające, których
* łapanie jest podstawą gry i jest pochodną
* klas QObject oraz QGraphicsItem
*
*/

#include <cstdlib>
#include <QThread>
#include "gracz.h"

class Owoc:public QGraphicsItem, public QObject {
public:
    /*!
    * \brief Konstruktor klasy
    *
    * Funkcja inicjalizuje zmienne
    */
    Owoc(QGraphicsScene *_scena, Gracz *gr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    /*!
    * \brief Funkcja obsługująca zderzenie
    *
    * Funkcja obsługująca zderzenie
    */
    void boom();
    /*!
    * \brief Funkcja ustawiajaca zmienną
    *
    * Funkcja ustawiajaca zmienną na nową wartość
    */
    void setZderzony(int zd);
    /*!
    * \brief Funkcja zwracająca informację czy doszło do zdrrzenia
    *
    * Funkcja zwracająca wartość zmiennej
    * przechowującej informację czy doszło do zderzenie
    *
    * \return Informacja czy doszło do zderzenie
    */
    int getZderzony();

private:
    /*!
    * \brief Zmienna określająca położenie na osi OX
    *
    * Zmienna określająca położenie na osi OX obiektu
    * który nie zmienia położenia
    */
    int x;
    /*!
    * \brief Zmienna określająca położenie na osi OY
    *
    * Zmienna określająca położenie na osi OY obiektu
    * który nie zmienia położenia
    */
    int y;
    /*!
    * \brief Zmienna określająca losowy numer owoca
    *
    * Zmienna określająca losowy numer owoca, ma wpływ na
    * wczytywany obraz, określa którym z owoców będzie
    */
    int numer;
    /*!
    * \brief Zmienna określająca czy doszło już do zderzenia
    *
    * Zmienna określająca czy doszło już do zderzenia, jeśli nie
    * naliczan są punkty i zmieniany wygląd, jeśli tak
    * następuje dalsza zmiana wyglądu
    */
    int zderzony;
    /*!
    * \brief Zmienna określająca prędkość obiektu
    *
    * Zmienna określająca preędkość obiektu, która może się zmieniać
    */
    int predkosc;
    /*!
    * \brief Zmienna określająca na jakim etapie jest animacja rozbicia
    *
    * Zmienna określająca na jakim etapie jest animacja rozbicia
    */
    int poziomRozbicia;
    /*!
    * \brief Zmienna zliczająca czas do następnego etapu animacji
    *
    * Zmienna zliczająca czas do następnego etapu animacji
    */
    int sekundy;
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
    * i przypisanie go do obiektu kalibracyjnego
    */
    QPixmap obrazek;
    /*!
    * \brief Obiekt owoc
    *
    * Obiekt wczytywany na scenę
    */
    QGraphicsPixmapItem *obiekt;
    /*!
    * \brief Obiekt gracza
    *
    * Wskaźnik na obiekt gracza wykorzystywany
    * do wykrywaina zderzenia
    */
    Gracz *gracz;

protected slots:
    /*!
    * \brief Funkcja aktualizująca dane w obiekcie
    *
    * Funkcja aktualizująca dane w obiekcie z częstotliwością
    * zmiennej czasowe z którą jest połączona
    */
    void advance(int phase) override;
};

#endif // OWOC_H
