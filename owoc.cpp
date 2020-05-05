#include "owoc.h"

Owoc::Owoc(QGraphicsScene *_scena)
{
    scena = _scena;
    obiekt = new QGraphicsPixmapItem();

    numer = rand()%5+0;
    zderzony = 0;
    x = rand()%299-200;
    y = rand()%299-1200;
    predkosc = rand()%11+5;

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

QRectF Owoc::boundingRect() const
{
    return QRectF(x,y,obrazek.width(),obrazek.height());
}

//to nie jest nam potrzebne zaimplementowane
void Owoc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

void Owoc::advance(int phase)
{
    if(phase==0){
        return;
    } else {
        y += predkosc;
        if(y>=1000){
            zderzony = 0;
            numer = rand()%5+0;
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
            x = rand()%399-200;
            y = rand()%499-900;
            predkosc = rand()%11+5;
            obiekt->setPixmap(obrazek);
            obiekt->setPos(x, y);
        }
        obiekt->setY(y);
    }
}

void Owoc::boom()
{
    /*if(numer==0)
        obrazek.load(":/image/cherryboom.png");
    else if(numer==1)
        obrazek.load(":/image/appleboom.png");
    else if(numer==2)
        obrazek.load(":/image/bananaboom.png");
    else if(numer==3)
        obrazek.load(":/image/limeboom.png");
    else if(numer==4)
        obrazek.load(":/image/orangeboom.png");
*/
    if(zderzony==0){
        //zlicz punkty
    }
    obrazek.load(":/image/appleboom.png");
    obiekt->setPixmap(obrazek);
    predkosc = 20;
}

void Owoc::setZderzony(int zd)
{
    zderzony = zd;
}

int Owoc::getZderzony()
{
    return zderzony;
}
