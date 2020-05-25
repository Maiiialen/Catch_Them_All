#ifndef GRACZ_H
#define GRACZ_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>

class Gracz:public QObject, public QGraphicsItem
{
public:
    Gracz(QGraphicsScene *_scena);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void SetX();
    void boom();
    int getPunkty();
    void setPunkty(int liczba);
    void setPredkosc();
    void setAccX(int liczba);
    int getAccX();

private:
    int x, y;
    int AccX;
    int predkosc;
    int kierunek;
    int punkty;
    QGraphicsScene *scena;
    QPixmap obrazek;
    QGraphicsPixmapItem *obiekt;

public slots:
    void advance(int phase) override;
};

#endif // GRACZ_H
