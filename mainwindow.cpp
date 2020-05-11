#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "szukaj.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    Scene = new QGraphicsScene(this);
    ui->graphicsViewGra->setInteractive(false);
    ui->graphicsViewGra->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsViewGra->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsViewGra->setScene(Scene);

    installEventFilter(this);

    kalibracja1 = new ObiektKalibracyjny(Scene, -400, -1200);
    kalibracja2 = new ObiektKalibracyjny(Scene, 400, -50);
    Scene->addItem(kalibracja1);
    Scene->addItem(kalibracja2);

    gracz = new Gracz(Scene);
    Scene->addItem(gracz);
    gracz->setFlag(QGraphicsItem::ItemIsFocusable);
    gracz->setFocus();

    owoc1 = new Owoc(Scene, gracz);
    owoc2 = new Owoc(Scene, gracz);
    owoc3 = new Owoc(Scene, gracz);
    owoc4 = new Owoc(Scene, gracz);
    owoc5 = new Owoc(Scene, gracz);
    Scene->addItem(owoc1);
    Scene->addItem(owoc2);
    Scene->addItem(owoc3);
    Scene->addItem(owoc4);
    Scene->addItem(owoc5);

    czas = new QTimer(this);
    connect(czas, SIGNAL(timeout()), Scene, SLOT(advance()));

    //przerwa = new QTimer(this);
    //connect(przerwa, SIGNAL(timeout()), this, SLOT(stworz()));

    czas1 = new QTimer(this);
    connect(czas1, SIGNAL(timeout()), this, SLOT(aktualizacjaPunktow()));

    czas->start(1000/66);
    //przerwa->start(1000);
    czas1->start(1000/11);
}

bool MainWindow::eventFilter(QObject *target, QEvent *event){
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()){
            case Qt::Key_A:
                gracz->SetX(0);
                break;
            case Qt::Key_D:
                gracz->SetX(1);
                break;
        }
    }
    return QObject::eventFilter(target, event);
}

void MainWindow::aktualizacjaPunktow()
{
    ui->labelWyswietlaczPunkty->setNum(gracz->getPunkty());

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::stworz(){
    Scene->addItem(new Owoc(Scene));
}
*/

void MainWindow::on_pushButtonSzukaj_clicked()
{
    Szukaj Okno;
    Okno.setModal(true);
    Okno.exec();
}
