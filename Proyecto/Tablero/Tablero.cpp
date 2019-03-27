//
// Created by saymon on 14/03/19.
//
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Tablero.h"
#include <string.h>
#include <ctype.h>


using namespace std;


int Tablero:: nFilas =15;
int Tablero:: nCol = 15;


Tablero* Tablero::instance = 0;

Tablero* Tablero::getInstance()
{
    if (instance == 0)
    {
        instance = new Tablero();
    }

    return instance;
}

Tablero::Tablero() {

    int num;
    matriz = new Elemento *[nFilas]();
    for(int i=0; i<nFilas;i++){
        matriz[i]= new Elemento[nCol]();

    }
    for(int i=0;i<nFilas;i++){
        for(int j=0; j<nCol;j++){
            num = 1+ rand()%(15);
            auto *elem= new Elemento();
            elem->setValor(num);
            *(*(matriz+i)+j) = *elem;
        }
    }

}


void Tablero::agregar(int fil, int col, string letra, int valor) {
    if((*(matriz+fil)+col)->getLetra()=="[]"){
        (*(matriz+fil)+col)->setLetra(letra);
        (*(matriz+fil)+col)->setValorLetra(valor);
        cout<< "Agregado en la fila: "<< fil<<" , columna: "<< col<< endl;
    }
    else{
        cout << "Espacio no disponible"<< endl;

    }
}


void Tablero::limpiar() {

    for(int i=0;i<nFilas;i++){
        delete[] matriz[i];
    }
    delete[] matriz;

    cout<< "Memoria liberada"<< endl;

}

void Tablero::recorrer() {
    cout<< "Imprimiendo matriz: "<< endl;
    for(int i=0; i<nFilas;i++){
        for(int j=0; j<nCol;j++){
            cout<< (*(matriz+i)+j)->getLetra()<< " ";

        }
        cout<<endl;
    }
}


int Tablero:: recorrerHorizontal(int i, int j){
    string palabra;
    int suma = 0;
    int col;
    if((*(matriz+(i))+(j-1))->getLetra()=="[]" || j==0) {
        cout<<"Horizontal"<<endl;
        for (col = j ; col < nCol; col++) {
            if ((*(matriz + i ) + col)->getLetra()!="[]") {
                palabra += (*(matriz + i ) + (col))->getLetra();
                suma += (*(matriz + i) + (col))->getValor() + (*(matriz + i) + col)->getValorLetra();
            } else {
                break;
            }
        }
        if(palabra.length()>2){
            cout<< suma<<" haha"<<endl;
            cout << palabra << endl;
            return validarPalabra(palabra, &suma, i, col, 1);
        }
    }
    else if ((*(matriz+(i))+(j-1))->getLetra()!="[]"){
        recorrerHorizontalAux(i, j);
    }

    return 0;
}


void Tablero:: recorrerHorizontalAux(int i, int j){
    if((*(matriz+(i))+(j-1))->getLetra()!="[]"){
        cout<<"Horizontal aux"<<endl;
        for (int col= j-1; col >=0 ; col--) {
            if ((*(matriz + i)+col)->getLetra()=="[]") {
                recorrerHorizontal(i,col+1);
                break;
            }
        }
    }
}

int Tablero::recorrerVertical(int i, int j) {
    string palabra;
    int suma=0;
    int fil;
    if((*(matriz+(i-1))+j)->getLetra()=="[]" || i==0){
        cout<<"Vertical"<<endl;
        for (fil = i; fil < nFilas; fil++) {
            if ((*(matriz + fil) + (j))->getLetra()!="[]") {
                suma+= (*(matriz + (fil)) + (j))->getValor() + (*(matriz + (fil)) + (j))->getValorLetra();
                palabra += (*(matriz + (fil)) + (j))->getLetra();
            } else {
                break;
            }

        }
        if(palabra.length()>2){
            cout<< suma<<" jaja"<<endl;
            cout << palabra << endl;
            return validarPalabra(palabra, &suma, fil, j, 0);
        }

    }
    else if ((*(matriz+(i-1))+(j))->getLetra()!="[]"){
        recorrerVerticalAux(i, j);
    }

    return 0;
}

void Tablero::recorrerVerticalAux(int i, int j) {
    if((*(matriz+(i-1))+(j))->getLetra()!="[]"){
        cout<<"Vertical aux"<<endl;
        for (int fil = i-1; fil >=0; fil--) {
            if ((*(matriz + fil) + (j))->getLetra()=="[]") {
                recorrerVertical(fil+1,j);
                break;
            }

        }
    }
}

int Tablero::validarPalabra(string palabra, int *suma, int i, int j, int v) {
    ifstream ip("/home/saymon/CLionProjects/Proyecto/Tablero/lemario.txt");

    string datos;

    if(ip.fail()) cout<<"No se abrió el archivo"<<endl;

    else {
        while (!ip.eof()) {
            ip >> datos;
            if (datos == palabra) {
                cout << "Bien" << endl;
                if(v==0){
                    setRecorrerVertical(i, j);
                }
                else{
                    setRecorrerHorizontal(i, j);
                }
                return *suma;
            }

        }
        if(v==0){
            eliminarVertical(i,j);
        }
        else{
            eliminarHorizontal(i,j);
        }
        cout<<"Hay que consultar al experto o pasar turno"<<endl;
    }
    ip.close();

    return 0;
}

void Tablero:: borrar(int i, int j){
    if((*(matriz+i)+j)->getLetra()!="[]"){
        (*(matriz+i)+j)->setLetra("[]");
        (*(matriz+i)+j)->setValorLetra(0);
        cout<< "Borrado exitosamente"<< endl;
    }
    else{
        cout << "Error"<< endl;

    }
}

void Tablero::eliminarVertical(int i, int j) {
    if((*(matriz+(i-1))+(j))->getLetra()!="[]"){
        for (int fil = i-1; fil >=0; fil--) {
            if ((*(matriz + fil) + (j))->getLetra()=="[]" || (*(matriz + fil) + (j))->getRecorrido()) {
                break;
            }
            else{
                (*(matriz + fil) + (j))->setLetra("[]");
            }

        }
    }
}

void Tablero::eliminarHorizontal(int i, int j) {
    if((*(matriz+(i))+(j-1))->getLetra()!="[]"){
        for (int col= j-1; col >=0 ; col--) {
            if ((*(matriz + i)+col)->getLetra()=="[]" || (*(matriz + i)+col)->getRecorrido()) {
                break;
            }
            else{
                (*(matriz + i)+col)->setLetra("[]");
            }
        }
    }
}

void Tablero::setRecorrerVertical(int i, int j) {
    if((*(matriz+(i-1))+(j))->getLetra()!="[]"){
        for (int fil = i-1; fil >=0; fil--) {
            if ((*(matriz + fil) + (j))->getLetra()=="[]" || (*(matriz + fil) + (j))->getRecorrido()) {
                break;
            }
            else{
                (*(matriz + fil) + (j))->setRecorrido(true);
            }

        }
    }

}

void Tablero::setRecorrerHorizontal(int i, int j) {
    if((*(matriz+(i))+(j-1))->getLetra()!="[]"){
        for (int col= j-1; col >=0 ; col--) {
            if ((*(matriz + i)+col)->getLetra()=="[]" || (*(matriz + i)+col)->getRecorrido()) {
                break;
            }
            else{
                (*(matriz + i)+col)->setRecorrido(true);
            }
        }
    }
}
