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

void Ficha::setX(int x) {
    this->x= x;

}

int Ficha::getX() {
    return this->x;
}

void Ficha::setY(int y) {
    this->y= y;
}

int Ficha::getY() {
    return this->y;
}
