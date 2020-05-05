#include "owoc.h"

Owoc::Owoc(QGraphicsScene *_scena)
{
    int a = 0, bx = 0, by = 0, c = 0;
    scena = _scena;
    obiekt = new QGraphicsPixmapItem();

    a = rand()%5+0;
    bx = rand()%399-200;
    by = rand()%499+900;
    c = rand()%11+5;

    x = bx;
    y = by;
    predkosc = c;
    //std::cout << x << " " << y << " " << c << " " << a << std::endl;

    if(a==0)
        obrazek.load(":/image/cherry.png");
    else if(a==1)
        obrazek.load(":/image/apple.png");
    else if(a==2)
        obrazek.load(":/image/banana.png");
    else if(a==3)
        obrazek.load(":/image/lime.png");
    else if(a==4)
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
        if(y>=500)
            y=-1000;
            //delete this;
        obiekt->setY(y);
    }
}
