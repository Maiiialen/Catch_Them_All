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
    * \param[in] *_scena - wskaźnik na scenę, na której ma pojawić się obiekt
    * \param[in] _x - początkowa współrzędna na osi OX
    * \param[in] _y - początkowa współrzędna na osi OY
    */
    ObiektKalibracyjny(QGraphicsScene *_scena, int _x, int _y);
    /*!
    * \brief Tworzy prostokąt ograniczjący obiekt
    *
    * Funkcja inicjalizuje prostokąd ograniczjący obiekt.
    */
    QRectF boundingRect() const override;
    /*!
    * \brief Funkcja rysująca obiekt na ekranie
    *
    * Nieużywana funkcja rysujaca obiekt na ekranie
    */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    /*!
    * \brief Zmienna określająca położenie na osi OX
    *
    * Zmienna określająca położenie na osi OX obiektu
    * który nie zmienia położenia,
    * jednostką jest piksel
    */
    int x;
    /*!
    * \brief Zmienna określająca położenie na osi OY
    *
    * Zmienna określająca położenie na osi OY obiektu
    * który nie zmienia położenia,
    * jednostką jest piksel
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

