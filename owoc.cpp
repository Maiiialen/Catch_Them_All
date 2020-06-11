#include "owoc.h"

Owoc::Owoc(QGraphicsScene *_scena, Gracz *gr) {
    scena = _scena;
    obiekt = new QGraphicsPixmapItem();
    gracz = gr;

    numer = rand()%5+0;
    zderzony = 0;
    sekundy = 0;
    x = rand()%799-600;
    y = rand()%299-1200;
    predkosc = rand()%11+5;
    poziomRozbicia = 0;

    if(numer==0)
        obrazek.load(":/image/cherry.png");
    else if(numer==1)
        obrazek.load(":/image/apple.png");
    else if(numer==2)
        obrazek.load(":/image/banana.png");
    else if(numer==3)
        obrazek.load(":/image/lime.png");
    else if(numer==4)
        obrazek.load(":/image/orange.png");

    obiekt->setPixmap(obrazek);
    obiekt->setPos(x, y);
    scena->addItem(obiekt);
}

QRectF Owoc::boundingRect() const {
    return QRectF(x,y,obrazek.width(),obrazek.height());
}

void Owoc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

void Owoc::advance(int phase) {
    if(phase==0){
        return;
    } else {
        y += predkosc;

        if(collidesWithItem(gracz)){
            if(zderzony == 0){
                gracz->setPunkty(10);
            }
            boom();
            zderzony = 1;
        }

        if(poziomRozbicia == 1 && sekundy == 5){
            poziomRozbicia = 2;
            if(numer==0)
                obrazek.load(":/image/cherry2.png");
            else if(numer==1)
                obrazek.load(":/image/apple2.png");
            else if(numer==2)
                obrazek.load(":/image/banana2.png");
            else if(numer==3)
                obrazek.load(":/image/lime2.png");
            else if(numer==4)
                obrazek.load(":/image/orange2.png");
            sekundy = 0;
        } else if(poziomRozbicia == 2 && sekundy == 5){
            poziomRozbicia = 3;
            if(numer==0)
                obrazek.load(":/image/cherry3.png");
            else if(numer==1)
                obrazek.load(":/image/apple3.png");
            else if(numer==2)
                obrazek.load(":/image/banana3.png");
            else if(numer==3)
                obrazek.load(":/image/lime3.png");
            else if(numer==4)
                obrazek.load(":/image/orange3.png");
            sekundy = 0;
        } else if(poziomRozbicia == 3 && sekundy == 5){
            poziomRozbicia = 4;
            if(numer==0)
                obrazek.load(":/image/cherry4.png");
            else if(numer==1)
                obrazek.load(":/image/apple4.png");
            else if(numer==2)
                obrazek.load(":/image/banana4.png");
            else if(numer==3)
                obrazek.load(":/image/lime4.png");
            else if(numer==4)
                obrazek.load(":/image/orange4.png");
            sekundy = 0;
        }
        if(y>=1000){
            zderzony = 0;
            numer = rand()%5+0;
            poziomRozbicia = 0;
            if(numer==0)
                obrazek.load(":/image/cherry.png");
            else if(numer==1)
                obrazek.load(":/image/apple.png");
            else if(numer==2)
                obrazek.load(":/image/banana.png");
            else if(numer==3)
                obrazek.load(":/image/lime.png");
            else if(numer==4)
                obrazek.load(":/image/orange.png");
            x = rand()%799-400;
            y = rand()%299-1200;
            predkosc = rand()%11+5;
            obiekt->setPos(x, y);
            sekundy = 0;
        }
        obiekt->setPixmap(obrazek);
        obiekt->setY(y);
    }
}

void Owoc::boom() {
    if(zderzony == 0){
        poziomRozbicia = 1;
        if(numer==0)
            obrazek.load(":/image/cherry1.png");
        else if(numer==1)
            obrazek.load(":/image/apple1.png");
        else if(numer==2)
            obrazek.load(":/image/banana1.png");
        else if(numer==3)
            obrazek.load(":/image/lime1.png");
        else if(numer==4)
            obrazek.load(":/image/orange1.png");
        obiekt->setPixmap(obrazek);
        predkosc = 10;
    }
    sekundy++;
}

void Owoc::setZderzony(int zd) {
    zderzony = zd;
}

int Owoc::getZderzony() {
    return zderzony;
}
