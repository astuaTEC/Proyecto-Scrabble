//
// Created by saymon on 14/03/19.
//

#ifndef PROYECTO_TABLERO_H
#define PROYECTO_TABLERO_H


#include "Elemento.h"

using namespace std;

class Tablero {

private:

    Elemento **matriz;

    static int nFilas, nCol;

public:

    Tablero();
    void agregar(int, int, string);
    void limpiar();
    void recorrer();

    int recorrerHorizontal(int, int);
    void recorrerHorizontalAux(int, int);
    int recorrerVertical(int, int);
    void recorrerVerticalAux(int, int);

    int validarPalabra(string, int);

};


#endif //PROYECTO_TABLERO_H
