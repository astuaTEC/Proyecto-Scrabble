#include <iostream>
#include <stdlib.h>
#include "Tablero/Tablero.h"
#include "Dealer/Dealer.h"
#include <locale.h>


using namespace std;

int main(){

    Dealer *d = new Dealer();

    d->repartir();

    Tablero *tablero = new Tablero();

    tablero->agregar(5,2,"a");

    tablero->agregar(4,2,"s");

    tablero->agregar(3,2,"a");

    tablero->agregar(2,5,"a");

    tablero->agregar(2,4,"m");

    tablero->agregar(2,3,"a");

    tablero->agregar(2,2,"c");


    tablero->recorrerVertical(4,2);
    tablero->recorrerHorizontal(2,2);

    tablero->agregar(2,6,"c");
    tablero->agregar(2,7,"a");
    tablero->agregar(2,8,"c");
    tablero->agregar(2,9,"a");

    tablero->recorrerHorizontal(2,6);

    tablero->recorrer();

    tablero->limpiar();



    return 0;
}