#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    kalibracja1 = new ObiektKalibracyjny(Scene, -700, -2000);
    kalibracja2 = new ObiektKalibracyjny(Scene, 700, 0);
    Scene->addItem(kalibracja1);
    Scene->addItem(kalibracja2);

    gracz = new Gracz(Scene);
    Scene->addItem(gracz);
    gracz->setFlag(QGraphicsItem::ItemIsFocusable);
    gracz->setFocus();

    owoc1 = new Owoc(Scene);
    owoc2 = new Owoc(Scene);
    owoc3 = new Owoc(Scene);
    owoc4 = new Owoc(Scene);
    owoc5 = new Owoc(Scene);
    Scene->addItem(owoc1);
    Scene->addItem(owoc2);
    Scene->addItem(owoc3);
    Scene->addItem(owoc4);
    Scene->addItem(owoc5);

    czas = new QTimer(this);
    connect(czas, SIGNAL(timeout()), Scene, SLOT(advance()));

    //przerwa = new QTimer(this);
    //connect(przerwa, SIGNAL(timeout()), Scene, SLOT(stworz()));

    czas->start(1000/66);
    //przerwa->start(1000);
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

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::stworz(){
    //Scene->addItem(new Owoc(Scene));
//}

