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
    bool horizontal;
    bool vertical;


public:


    Elemento();
    Elemento(char, int);
    ~Elemento();
    int getValor();
    void setValor(int);
    void setLetra(string);
    void setValorLetra(int);

    int getValorLetra();
    string getLetra();
    void setHorizontal(bool);
    void setVertical(bool);
    bool getHorizontal();
    bool getVertical();



};


#endif //PROYECTO_ELEMENTO_H
