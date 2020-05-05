#ifndef GRACZ_H
#define GRACZ_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>
#include <iostream>
#include <QDebug>
#include "owoc.h"

class Gracz:public QGraphicsItem, public QObject
{
public:
    Gracz(QGraphicsScene *_scena);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void SetX(int kierunek);
    void boom();
    int getPunkty();

private:
    int x, y;
    int predkosc;
    int punkty;
    QGraphicsScene *scena;
    QPixmap obrazek;
    QGraphicsPixmapItem *obiekt;

protected slots:
    void advance(int phase) override;
};

#endif // GRACZ_H
