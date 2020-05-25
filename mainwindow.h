#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>
#include <QObject>
#include "owoc.h"
#include "obiektkalibracyjny.h"
#include "szukaj.h"
//#include "gracz.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //bool eventFilter(QObject *target, QEvent *event);

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
    Szukaj *Okno;

public slots:
    void aktualizacjaPunktow();
    void on_pushButtonSzukaj_clicked();
    void on_pushButtonStartGry_clicked();
    void odebranieDanych(int x);
};
#endif // MAINWINDOW_H
