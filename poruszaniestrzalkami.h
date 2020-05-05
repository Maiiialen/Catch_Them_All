#ifndef PORUSZANIESTRZALKAMI_H
#define PORUSZANIESTRZALKAMI_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>


class poruszanieStrzalkami: public QGraphicsPixmapItem
{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PORUSZANIESTRZALKAMI_H
