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
    static Tablero* instance;
    Tablero();

public:

    static Tablero* getInstance();

    void agregar(int, int, string, int);
    void limpiar();
    void recorrer();
    void borrar(int, int);

    int recorrerHorizontal(int, int);
    void recorrerHorizontalAux(int, int);
    int recorrerVertical(int, int);
    void recorrerVerticalAux(int, int);
    void eliminarVertical(int,int);
    void eliminarHorizontal(int,int);

    void setRecorrerVertical(int, int);
    void setRecorrerHorizontal(int, int);



    int validarPalabra(string, int, int, int);

};


#endif //PROYECTO_TABLERO_H
