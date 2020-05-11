#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>

//#include "gracz.h"
#include "owoc.h"
#include "obiektkalibracyjny.h"
#include <QTimer>
#include <QKeyEvent>
#include <iostream>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stworz();
    bool eventFilter(QObject *target, QEvent *event);
private:
    Ui::MainWindow *ui;
    QPixmap pixmapObject;
    QGraphicsScene *Scene;
    ObiektKalibracyjny *kalibracja1;
    ObiektKalibracyjny *kalibracja2;
    Owoc *owoc1;
    Owoc *owoc2;
    Owoc *owoc3;
    Owoc *owoc4;
    Owoc *owoc5;
    Gracz *gracz;
    QTimer *czas;
    QTimer *czas1;
    QTimer *przerwa;

public slots:
    void aktualizacjaPunktow();
private slots:
    void on_pushButtonSzukaj_clicked();
};
#endif // MAINWINDOW_H
