//
// Created by saymon on 14/03/19.
//

#ifndef PROYECTO_FICHA_H
#define PROYECTO_FICHA_H

#include <string>

using namespace std;

class Ficha {

private:

    int valor, x, y;
    string letra;

public:
    Ficha(string, int);
    Ficha();

    void setLetra(string);
    int getValor();
    void setValor(int);
    string getLetra();

};


#endif //PROYECTO_FICHA_H
