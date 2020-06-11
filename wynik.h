#ifndef WYNIK_H
#define WYNIK_H

/*!
* \file
* \brief Definicja klasy Wynik
*
* Plik zawiera definicję klasy Wynik, która
* odpowiada za okno z wynikiem gry,
* które pojawia się po zakończeniu gry
* i jest pochodną klasy QDialog
*
*/

#include <QDialog>

namespace Ui {
class Wynik;
}

class Wynik : public QDialog {
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor klasy
    *
    * Funkcja inicjalizuje zmienne
    */
    explicit Wynik(QWidget *parent = nullptr);
    /*!
    * \brief Destruktor klasy
    *
    * Destruktor klasy
    */
    ~Wynik();
    /*!
    * \brief Funkcja uaktualniająca zmienną
    *
    * Funkcja uaktualniająca zmienną zawierającą
    * informację o ilości zdobytych punktów
    */
    void setWynik(int wartosc);

private:
    /*!
    * \brief Obiekt ui
    *
    * Wskaźnik na obiekt interfejsu użytkownika
    */
    Ui::Wynik *ui;
};

#endif // WYNIK_H
