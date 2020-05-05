#include "obiektkalibracyjny.h"

ObiektKalibracyjny::ObiektKalibracyjny(QGraphicsScene *_scena, int _x, int _y)
{
    scena = _scena;
    x = _x;
    y = _y;
    obiekt = new QGraphicsPixmapItem();
    obrazek.load(":/image/cherry.png");
    obiekt->setPixmap(obrazek);
    obiekt->setPos(x, y);
    //obiekt->hide();
    scena->addItem(obiekt);
}

QRectF ObiektKalibracyjny::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void ObiektKalibracyjny::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}
