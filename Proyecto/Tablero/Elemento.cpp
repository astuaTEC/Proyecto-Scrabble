//
// Created by saymon on 14/03/19.
//

#include "Elemento.h"


string Elemento::getLetra() {
    return this->letra;

}

int Elemento::getValor() {
    return this->valor;
}

void Elemento::setLetra(string letra) {
    this->letra= letra;
}

void Elemento::setValor(int n) {
    this->valor = n;
}

Elemento::Elemento() {

}
Elemento::Elemento(char letra, int valor) {
    this->letra= letra;
    this->valor= valor;
}

Elemento::~Elemento() {

}

void Elemento::setValorLetra(int n) {
    this->valorLetra= n;
}

int Elemento::getValorLetra() {
    return this->valorLetra;
}

void Elemento::setHorizontal(bool b) {
    this->horizontal= b;

}

void Elemento::setVertical(bool b) {
    this->vertical= b;

}

bool Elemento::getHorizontal() {
    return this->horizontal;
}

bool Elemento::getVertical() {
    return this->vertical;
}
