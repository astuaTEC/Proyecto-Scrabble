//
// Created by saymon on 14/03/19.
//

#include "Ficha.h"
#include <iostream>

using namespace std;


void Ficha::setLetra(string letra) {
    this->letra=letra;

}

int Ficha::getValor() {
    return this->valor;
}

void Ficha::setValor(int n) {
    this->valor= n;

}

string Ficha::getLetra() {
    return this->letra;
}

Ficha::Ficha(string letra, int valor) {
    this->letra= letra;
    this->valor= valor;

}

Ficha::Ficha() {

}
