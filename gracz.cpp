#include "gracz.h"

Gracz::Gracz(QGraphicsScene *_scena) {
    scena = _scena;
    punkty = 0;
    x = -100;
    y = 0;
    predkosc = 0;
    kierunek = 1;
    AccX = 0;
    obrazek.load(":/image/paws&tlate2.png");
    obiekt = new QGraphicsPixmapItem();
    obiekt->setPixmap(obrazek);
    obiekt->setPos(x, y);
    scena->addItem(obiekt);
}

QRectF Gracz::boundingRect() const {
    return QRectF(x,y,obrazek.width(),obrazek.height());
}

void Gracz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

void Gracz::SetX() {
    if (kierunek==1){
        //qDebug() << predkosc;
        x+=predkosc;
    } else {
        //qDebug() << predkosc;
        x-=predkosc;
    }
    if(x < -600) {
        x = -600;
    } else if(x > 250) {
        x = 250;
    }
    obiekt->setX(x);
}

void Gracz::boom(){}

int Gracz::getPunkty() {
    return punkty;
}

void Gracz::setPunkty(int liczba) {
    punkty+=liczba;
}

void Gracz::setPredkosc() {
    double wspolczynnik = 1.8;
    if(AccX < 22){
        kierunek = 0;
        predkosc = AccX*wspolczynnik;
    } else {
        kierunek = 1;
        predkosc = (63-AccX)*wspolczynnik;
    }
}

void Gracz::setAccX(int liczba) {
    AccX = liczba;
}

int Gracz::getAccX() {
    return AccX;
}


void Gracz::advance(int phase) {
    if(phase==0){
        return;
    } else {
        setPredkosc();
        //qDebug() << x;
        SetX();
    }
}


