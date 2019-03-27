//
// Created by saymon on 14/03/19.
//

#include <iostream>
#include <stdlib.h>

using namespace std;


void pedirDatos();
void mostrarMatriz(int **,int,int);

int **matriz, nFilas, nCol;


int main2() {
    pedirDatos();
    mostrarMatriz(matriz,nFilas,nCol);

    //liberar memoria
    for(int i=0;i<nFilas;i++){
        delete[] matriz[i];
    }

    delete[] matriz;

    return 0;
}

void pedirDatos(){
    cout<< "Digite el número de filas"<<endl;
    cin>>nFilas;
    cout<< "Digite el número de columnas"<<endl;
    cin>> nCol;


    matriz = new int*[nFilas];
    for(int i=0; i<nFilas;i++){
        matriz[i]= new int[nCol];

    }

    cout<< "\nDigitando los numeros de la matriz: "<<endl;
    for(int i=0;i<nFilas;i++){
        for(int j=0; j<nCol;j++){
            cout<< "Digite un número["<<i<<"]["<<j<<"]: "<<endl;
            cin>> *(*(matriz+i)+j);

        }
    }
}

void mostrarMatriz(int** matriz, int nFila, int nCol){
    cout<< "Imprimiendo matriz: "<< endl;

    for(int i=0; i<nFila;i++){
        for(int j=0; j<nCol;j++){
            cout<< *(*(matriz+i)+j)<< "  ";

        }
        cout<<endl;
    }
}