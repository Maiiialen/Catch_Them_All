#include "gracz.h"

Gracz::Gracz(QGraphicsScene *_scena)
{
    scena = _scena;
    punkty = 0;
    x = -100;
    y = 0;
    predkosc = 10;
    obrazek.load(":/image/paws&tlate.png");
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


void Gracz::advance(int phase)
{
    Owoc *tym;
    if(phase==0){
        return;
    } else {
        obiekt->setX(x);
        if (collidingItems().size() > 1){
            qDebug() << collidingItems();
            tym = dynamic_cast<Owoc*>(collidingItems().takeAt(0));
            //std::cout << tym << std::endl;
            if(tym){
                if(tym->getZderzony() == 0){
                    punkty+=10;
                }
                std::cout << "boom" << std::endl;
                tym->boom();
                tym->setZderzony(1);
            }
            /*
            if(dynamic_cast<Owoc*>(collidingItems().takeAt(0))->getZderzony() == 0){
                punkty+=10;
            }
            //std::cout << "boom" << std::endl;
            dynamic_cast<Owoc*>(collidingItems().takeAt(0))->boom();
            dynamic_cast<Owoc*>(collidingItems().takeAt(0))->setZderzony(1);
            std::cout << dynamic_cast<Owoc*>(collidingItems().takeAt(0))->getZderzony() << std::endl;
            */
        }
    }
}
