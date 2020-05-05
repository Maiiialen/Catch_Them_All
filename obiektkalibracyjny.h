#ifndef OBIEKTKALIBRACYJNY_H
#define OBIEKTKALIBRACYJNY_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <cstdlib>
#include <iostream>


class ObiektKalibracyjny: public QGraphicsItem
{
public:
    ObiektKalibracyjny(QGraphicsScene *_scena, int _x, int _y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    int x, y;
    QGraphicsScene *scena;
    QGraphicsPixmapItem *obiekt;
    QPixmap obrazek;

//protected slots:
//    void advance(int phase) override;
};

#endif // OBIEKTKALIBRACYJNY_H

