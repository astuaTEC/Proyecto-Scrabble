//
// Created by saymon on 17/03/19.
//

#ifndef PROYECTO_DEALER_H
#define PROYECTO_DEALER_H

#include <QList>
#include <string>
#include "../Tablero/Elemento.h"
#include "../Estructuras/List.h"
#include "Ficha.h"

using namespace std;

class Dealer {

private:
    string letras;
    QList<Ficha*> lista;
    static Dealer* instance;

    Dealer();


public:
    string repartir(int);
    static Dealer* getInstance();
};


#endif //PROYECTO_DEALER_H
