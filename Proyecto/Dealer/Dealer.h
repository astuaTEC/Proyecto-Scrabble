//
// Created by saymon on 17/03/19.
//

#ifndef PROYECTO_DEALER_H
#define PROYECTO_DEALER_H

#include <string>
#include "../Tablero/Elemento.h"
#include "../Estructuras/List.h"
#include "Ficha.h"

using namespace std;

class Dealer {

private:
    string letras;
    List<Ficha> lista;


public:

    Dealer();
    ~Dealer();

    void repartir(int);
};


#endif //PROYECTO_DEALER_H
