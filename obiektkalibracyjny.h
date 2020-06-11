#ifndef OBIEKTKALIBRACYJNY_H
#define OBIEKTKALIBRACYJNY_H

/*!
* \file
* \brief Definicja klasy ObiektKalibracyjny
*
* Plik zawiera definicję klasy ObiektKalibracyjny, która
* odpowiada za obraz tła i jest pochodną
* klas QObject oraz QGraphicsItem
*
*/

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <cstdlib>
#include <iostream>


class ObiektKalibracyjny: public QGraphicsItem, public QObject {
public:
    /*!
    * \brief Konstruktor klasy
    *
    * Funkcja inicjalizuje zmienne
    */
    ObiektKalibracyjny(QGraphicsScene *_scena, int _x, int _y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

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
    * \brief Obiekt sceny
    *
    * Wskaźnik na scenę, pozwala na umieszczenie na niej obiektów
    */
    QGraphicsScene *scena;
    /*!
    * \brief Obiekt kalibracyjny
    *
    * Obiekt wczytywany na scenę
    */
    QGraphicsPixmapItem *obiekt;
    /*!
    * \brief Obiekt obrazka
    *
    * Obiekt pozwalający na wczytanie obrazke
    * i przypisanie go do obiektu kalibracyjnego
    */
    QPixmap obrazek;
};

#endif // OBIEKTKALIBRACYJNY_H

