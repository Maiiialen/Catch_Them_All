#include "poruszaniestrzalkami.h"


void poruszanieStrzalkami::keyPressEvent(QKeyEvent *event){
    int predkosc = 10;
    if (event->key() == Qt::Key_Left){
        setPos(x()-predkosc,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+predkosc,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-predkosc);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+predkosc);
    }
}
