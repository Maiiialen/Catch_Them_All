#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    srand(time(NULL));

    osY = new QValueAxis();
    osX = new QValueAxis();
    Okno = new Szukaj(this);

    connect(Okno, SIGNAL(otrzymanieDanych(int)), this, SLOT(odebranieDanych(int)));

    series = new QSplineSeries();
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    ui->graphicsWykres->setChart(chart);
    chart->addAxis(osY, Qt::AlignLeft);
    series->attachAxis(osY);
    osY->setRange(-80, 80);
    chart->addAxis(osX, Qt::AlignBottom);
    series->attachAxis(osX);
    osX->setTitleText("numer pomiaru");
    osX->setLabelFormat("%i");
    osY->setTitleText("wychylenie w stopniach");
    osY->setLabelFormat("%g");

    ui->labelStan->setText("rozłączone");
    ui->labelStan->setStyleSheet("QLabel { background-color : red; }");

    installEventFilter(this);
    pomiary = 0;
    czyBylStart = 0;
    obecnyCzasGry = 0;
}

void MainWindow::aktualizacjaPunktow() {
    ui->labelWyswietlaczPunkty->setNum(gracz->getPunkty());
}

void MainWindow::koniecGry(){
    obecnyCzasGry++;
    if(obecnyCzasGry == 10){
        obecnyCzasGry = 0;
        czyBylStart = 0;
        gracz->deleteLater();
        tlo->deleteLater();
        owoc1->deleteLater();
        owoc2->deleteLater();
        owoc3->deleteLater();
        owoc4->deleteLater();
        owoc5->deleteLater();
        Scene->deleteLater();
        czas->deleteLater();
        czas1->deleteLater();
        czasGry->deleteLater();

        OknoWyniku = new Wynik(this);
        OknoWyniku->show();
        OknoWyniku->setWynik(gracz->getPunkty());
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonSzukaj_clicked() {
    Okno->show();
    connect(Okno, SIGNAL(stan(int)), this, SLOT(Stan(int)));
}

void MainWindow::on_pushButtonStartGry_clicked() {
    if(czyBylStart == 0){
        czyBylStart = 1;
        Scene = new QGraphicsScene(this);
        ui->graphicsViewGra->setInteractive(false);
        ui->graphicsViewGra->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsViewGra->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsViewGra->setScene(Scene);

        tlo = new ObiektKalibracyjny(Scene, -600, -650);
        Scene->addItem(tlo);

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

        czas1 = new QTimer(this);
        connect(czas1, SIGNAL(timeout()), this, SLOT(aktualizacjaPunktow()));

        czasGry = new QTimer(this);
        connect(czasGry, SIGNAL(timeout()), this, SLOT(koniecGry()));

        czas->start(1000/66);
        czas1->start(1000/11);
        czasGry->start(1000);
    }
}

void MainWindow::odebranieDanych(int x) {
    gracz->setAccX(x);

    double kat = 0;
    switch(x){
    case 0:
        kat = 0;
        break;
    case 1:
        kat = 2.69;
        break;
    case 2:
        kat = 5.38;
        break;
    case 3:
        kat = 8.08;
        break;
    case 4:
        kat = 10.81;
        break;
    case 5:
        kat = 13.55;
        break;
    case 6:
        kat = 16.33;
        break;
    case 7:
        kat = 19.16;
        break;
    case 8:
        kat = 22.02;
        break;
    case 9:
        kat = 24.95;
        break;
    case 10:
        kat = 27.95;
        break;
    case 11:
        kat = 31.04;
        break;
    case 12:
        kat = 34.23;
        break;
    case 13:
        kat = 37.54;
        break;
    case 14:
        kat = 41.01;
        break;
    case 15:
        kat = 44.68;
        break;
    case 16:
        kat = 48.59;
        break;
    case 17:
        kat = 52.83;
        break;
    case 18:
        kat = 57.54;
        break;
    case 19:
        kat = 62.95;
        break;
    case 20:
        kat = 69.64;
        break;
    case 21:
        kat = 79.86;
        break;
    case 63:
        kat = -2.69;
        break;
    case 62:
        kat = -5.38;
        break;
    case 61:
        kat = -8.08;
        break;
    case 60:
        kat = -10.81;
        break;
    case 59:
        kat = -13.55;
        break;
    case 58:
        kat = -16.33;
        break;
    case 57:
        kat = -19.16;
        break;
    case 56:
        kat = -22.02;
        break;
    case 55:
        kat = -24.95;
        break;
    case 54:
        kat = -27.95;
        break;
    case 53:
        kat = -31.04;
        break;
    case 52:
        kat = -34.23;
        break;
    case 51:
        kat = -37.54;
        break;
    case 50:
        kat = -41.01;
        break;
    case 49:
        kat = -44.68;
        break;
    case 48:
        kat = -48.59;
        break;
    case 47:
        kat = -52.83;
        break;
    case 46:
        kat = -57.54;
        break;
    case 45:
        kat = -62.95;
        break;
    case 44:
        kat = -69.64;
        break;
    case 43:
        kat = -79.86;
        break;
    }
    series->append(pomiary, kat);
    osX->setRange(pomiary-50, pomiary);
    ++pomiary;
}

void MainWindow::Stan(int czyWlaczone) {
    if(czyWlaczone) {
        ui->labelStan->setText("połączone");
        ui->labelStan->setStyleSheet("QLabel { background-color : green; }");
    } else {
        ui->labelStan->setText("rozłączone");
        ui->labelStan->setStyleSheet("QLabel { background-color : red; }");
    }
}
