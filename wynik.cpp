#include "wynik.h"
#include "ui_wynik.h"

Wynik::Wynik(QWidget *parent): QDialog(parent), ui(new Ui::Wynik) {
    ui->setupUi(this);
}

Wynik::~Wynik() {
    delete ui;
}

void Wynik::setWynik(int wartosc) {
    ui->labelWynik->setNum(wartosc);
}
