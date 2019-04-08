//
// Created by saymon on 14/03/19.
//

#ifndef PROYECTO_ELEMENTO_H
#define PROYECTO_ELEMENTO_H

#include <string>

using namespace std;

class Elemento {


private:

    string letra ="[]";
    int valor;
    int valorLetra;
    bool recorrido;


public:


    Elemento();
    Elemento(char, int);
    int getValor();
    void setValor(int);
    void setLetra(string);
    void setValorLetra(int);


    int getValorLetra();
    string getLetra();
    void setRecorrido(bool);
    bool getRecorrido();



};


#endif //PROYECTO_ELEMENTO_H
