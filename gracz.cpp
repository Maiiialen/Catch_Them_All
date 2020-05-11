#include "gracz.h"

Gracz::Gracz(QGraphicsScene *_scena)
{
    scena = _scena;
    punkty = 0;
    x = -100;
    y = 0;
    predkosc = 10;
    obrazek.load(":/image/paws&tlate2.png");
    obiekt = new QGraphicsPixmapItem();
    obiekt->setPixmap(obrazek);
    obiekt->setPos(x, y);
    scena->addItem(obiekt);
}

QRectF Gracz::boundingRect() const
{
    return QRectF(x,y,obrazek.width(),obrazek.height());
}

void Gracz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

void Gracz::SetX(int kierunek){
    if (kierunek==1){
        x+=predkosc;
    } else {
        x-=predkosc;
    }
    obiekt->setX(x);
}

void Gracz::boom(){}

int Gracz::getPunkty()
{
    return punkty;
}

void Gracz::setPunkty(int liczba)
{
    punkty+=liczba;
}


void Gracz::advance(int phase)
{
    if(phase==0){
        return;
    } else {
        obiekt->setX(x);
    }
}






