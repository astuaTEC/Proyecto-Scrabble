#include "inicio_ventana.h"
#include <QApplication>
#include "juego.h"

Juego *juego;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inicio_ventana w;
    juego = new Juego();
    w.show();


    return a.exec();
}
