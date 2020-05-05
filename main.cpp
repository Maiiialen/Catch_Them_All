#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

/*
 #include "mainwindow.h"
#include "poruszaniestrzalkami.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    QPixmap pixmap;   ////


    // create an item to add to the scene
    poruszanieStrzalkami * pixmapObject = new poruszanieStrzalkami();

    pixmap.load(":/image/cherry.png");
    pixmap = pixmap.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    pixmapObject->setPixmap(pixmap);



    // add the item to the scene
    scene->addItem(pixmapObject);

    // make rect focusable
    pixmapObject->setFlag(QGraphicsItem::ItemIsFocusable);
    pixmapObject->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->show();

    return a.exec();
}
*/
