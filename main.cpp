#include "mainwindow.h"
#include <QApplication>

/*!
 * \mainpage Gra Catch Them All
 * \author Magdalena Sałęga
 *
 * Finalnym produktem jest gra, w której należy poruszać się na boki i łapać spadające obiekty.
 *
 * \section Sterowanie
 *
 * Sterowanie ruchem obiektu gracza odbywa się poprzez poruszanie płytką z akcelerometrem. \n
 * Kąt odchylenia płytki wpływa na prędkość poruszania się gracza na ekranie. \n
 * Dane pobierane z czujnika konwertowane są w programie aplikacji na prędkość obiektu gracza z pomocą funkcji liniowej. \n
 * Ruch ten jest też zależny od kierunku wychylenia akcelerometru. \n
 *
 * \section Kominikacja
 *
 * Zaimplementowana została komunikacja mikrokontrolera z aplikacją. Dane odebrane z mikrokontrolera przesyłane są do aplikacji wykorzystując ramkę danych. \n
 * Zaimplementowane zostały funkcje sumy kontrolnej w programie mikrokontrolera oraz w aplikacji, gdzie sprawdzana jest poprawność przesłanych danych. \n
 *
 * \section Grafika
 *
 * Aplikacja składa się z trzech okien: głównego, łączenia oraz końca gry. \n
 * Wykorzystane zostały obrazki łapek kota, talerza oraz 5 owoców aby urozmaicić grafikę w grze. \n
 * W tle również znajduje się obrazek nawiązujący tematyką do jedzenia. \n
 *
 */


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
