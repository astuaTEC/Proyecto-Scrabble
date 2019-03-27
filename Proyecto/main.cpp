#include <iostream>
#include <stdlib.h>
#include "Tablero/Tablero.h"
#include "Dealer/Dealer.h"
#include <locale.h>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <writer.h>


using namespace std;
using namespace rapidjson;

int main(){

    auto *d = new Dealer();

    d->repartir(3);

    auto *tablero = Tablero::getInstance();

    tablero->agregar(5,2,"a",1);

    tablero->agregar(4,2,"s",3);

    tablero->agregar(3,2,"a",1);

    tablero->agregar(2,5,"a",1);

    tablero->agregar(2,4,"m",4);

    tablero->agregar(2,3,"a",1);

    tablero->agregar(2,2,"c",3);

    tablero->recorrerVertical(4,2);
    tablero->recorrerHorizontal(2,2);

    tablero->agregar(2, 6, "m",4);
    tablero->agregar(2, 7, "a",1);
    tablero->agregar(2, 8, "m",4);
    tablero->agregar(2, 9, "a",1);

    tablero->recorrerVertical(2,9);
    tablero->recorrerHorizontal(2,9);

    tablero->agregar(6,2, "s",5);
    tablero->agregar(7,2, "a",1);

    tablero->recorrerVertical(7,2);
    tablero->recorrerHorizontal(7,2);

    tablero->recorrer();

    tablero->limpiar();



    return 0;
}