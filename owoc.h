#ifndef OWOC_H
#define OWOC_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <cstdlib>
#include <iostream>
#include <QDebug>

class Owoc:public QGraphicsItem
{
public:
    Owoc(QGraphicsScene *_scena);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    int x, y;
    int predkosc;
    QGraphicsScene *scena;
    QPixmap obrazek;
    QGraphicsPixmapItem *obiekt;

protected slots:
    void advance(int phase) override;
};

#endif // OWOC_H
