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

Tablero::Tablero() {

    int num;
    matriz = new Elemento *[nFilas]();
    for(int i=0; i<nFilas;i++){
        matriz[i]= new Elemento[nCol]();

    }
    for(int i=0;i<nFilas;i++){
        for(int j=0; j<nCol;j++){
            num = 1+ rand()%(15);
            Elemento *elem= new Elemento();
            elem->setValor(num);
            *(*(matriz+i)+j) = *elem;
        }
    }

}


void Tablero::agregar(int fil, int col, string letra) {
    if((*(matriz+(fil-1))+(col-1))->getLetra()=="[]"){
        (*(matriz+(fil-1))+(col-1))->setLetra(letra);
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
    if((*(matriz+(i-1))+(j-2))->getLetra()=="[]" || j==1) {
        cout<<"Horizontal"<<endl;
        for (int col = j - 1; col < nCol; col++) {
            if ((*(matriz + i - 1) + (col))->getLetra()!="[]") {
                palabra += (*(matriz + (i - 1)) + (col))->getLetra();
               //(*(matriz + (i - 1)) + (col))->setHorizontal(true);
                suma += (*(matriz + (i - 1)) + (col))->getValor() + (*(matriz + (i - 1)) + (col))->getValorLetra();
            } else {
                break;
            }
        }
        cout<< suma<<" haha"<<endl;
        cout << palabra << endl;
        return validarPalabra(palabra, suma);
    }
    else if ((*(matriz+(i-1))+(j-2))->getLetra()!="[]" && !(*(matriz+(i-1))+(j-1))->getHorizontal()){
        recorrerHorizontalAux(i, j);
    }

    return 0;
}


void Tablero:: recorrerHorizontalAux(int i, int j){
    if((*(matriz+(i-1))+(j-2))->getLetra()!="[]"){
        cout<<"Horizontal aux"<<endl;
        for (int col= j-1; col >=0 ; col--) {
            if ((*(matriz + (i-1))+(col))->getLetra()=="[]") {
                recorrerHorizontal(i,col+2);
                break;
            }
        }
    }
}

int Tablero::recorrerVertical(int i, int j) {
    string palabra;
    int suma =0;
    if((*(matriz+(i-2))+(j-1))->getLetra()=="[]" || i==1){
        cout<<"Vertical"<<endl;
        for (int fil = i-1; fil < nFilas; fil++) {
            if ((*(matriz + fil) + (j-1))->getLetra()!="[]") {
                suma+= (*(matriz + (fil)) + (j-1))->getValor() + (*(matriz + (fil)) + (j-1))->getValorLetra();
                palabra += (*(matriz + (fil)) + (j-1))->getLetra();
                //(*(matriz + (fil)) + (j-1))->setVertical(true);
            } else {
                break;
            }

        }
        cout<<palabra<<endl;
        cout<< suma<< " jaja"<<endl;
        return validarPalabra(palabra,suma);

    }
    else if ((*(matriz+(i-2))+(j-1))->getLetra()!="[]"){
        recorrerVerticalAux(i, j);
    }

    return 0;
}

void Tablero::recorrerVerticalAux(int i, int j) {
    if((*(matriz+(i-2))+(j-1))->getLetra()!="[]"){
        cout<<"Vertical aux"<<endl;
        for (int fil = i-1; fil >=0; fil--) {
            if ((*(matriz + fil) + (j-1))->getLetra()=="[]") {
                recorrerVertical(fil+2,j);
            }

        }
    }
}

int Tablero::validarPalabra(string palabra, int suma) {
    ifstream ip("/home/saymon/CLionProjects/Proyecto/Tablero/lemario.txt");

    string datos;

    if(ip.fail()) cout<<"No se abrió el archivo"<<endl;

    else {
        while (!ip.eof()) {
            ip >> datos;
            if (datos == palabra) {
                cout << "Bien" << endl;
                return suma;
            }

        }
        cout<<"Hay que consultar al experto o pasar turno"<<endl;
    }
    ip.close();

    return 0;

}
