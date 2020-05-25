#ifndef OWOC_H
#define OWOC_H

#include <cstdlib>
#include "gracz.h"


class Owoc:public QGraphicsItem {
public:
    Owoc(QGraphicsScene *_scena, Gracz *gr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void boom();
    void setZderzony(int zd);
    int getZderzony();

private:
    int x, y, numer, zderzony;
    int predkosc;
    QGraphicsScene *scena;
    QPixmap obrazek;
    QGraphicsPixmapItem *obiekt;
    Gracz *gracz;

protected slots:
    void advance(int phase) override;
};

#endif // OWOC_H
