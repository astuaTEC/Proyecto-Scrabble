//
// Created by saymon on 14/03/19.
//
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Tablero.h"
#include <string.h>
#include <ctype.h>
#include <socketserver.h>
#include <jugador.h>


using namespace std;

//auto server = SocketServer::getInstance();

//se asignan las variables staticas
int Tablero:: nFilas =15;
int Tablero:: nCol = 15;
Jugador jug;

Tablero* Tablero::instance = 0;

/**
 * metodo para usar el  singleton
 * @return  la instancia de tablero
 */
Tablero* Tablero::getInstance()
{
    if (instance == 0)
    {
        instance = new Tablero();
    }

    return instance;
}

/**
 * Constructor de tablero
 * Crea una matriz dinamica de punteros de tipo elemento
 */
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

/**
 * Metodo para agregar elementos al tablero
 * @param fil la fila donde poner la letra
 * @param col la columna donde poner la letra
 * @param letra la letra que va a poner en el tablero
 * @param valor el valor que posea la letra
 */
void Tablero::agregar(int fil, int col, string letra, int valor) {
    if(matriz[fil][col].getLetra()=="[]"){
        matriz[fil][col].setLetra(letra);
        matriz[fil][col].setValorLetra(valor);
        cout<< "Agregado en la fila: "<< fil<<" , columna: "<< col<< endl;
    }
    else{
        cout << "Espacio no disponible"<< endl;
    }
}

/**
 * Metodo para liberar la memoria
 * lo que hace es hacerle delete a todos los punteros
 */
void Tablero::limpiar() {

    for(int i=0;i<nFilas;i++){
        delete[] matriz[i];
    }
    delete[] matriz;

    cout<< "Memoria liberada"<< endl;

}

/**
 * Metodo para recorrer la matriz completa
 * lo que hace es imprimir cada uno de los datos que posee
 */
void Tablero::recorrer() {
    cout<< "Imprimiendo matriz: "<< endl;
    for(int i=0; i<nFilas;i++){
        for(int j=0; j<nCol;j++){
            cout<< matriz[i][j].getLetra()<< " ";
        }
        cout<<endl;
    }
}

/**
 * Método para buscar palabras de forma horizontal
 * @param i la fila donde iniciar el recorrido
 * @param j la columna donde iniciar el recorrido
 * @return el valor de la palabra leida
 */
int Tablero:: recorrerHorizontal(int i, int j){
    string palabra;
    int col;
    jug.suma=0;
    if(j==0 || (matriz[i][j-1]).getLetra()=="[]") {
        for (col = j ; col < nCol; col++) {
            if (((matriz [ i ][col]).getLetra()!="[]")) {
                palabra += (matriz [i ][col].getLetra());
                jug.suma += matriz [i][col].getValor() +matriz [i][col].getValorLetra();
            } else {
                break;
            }

        }
        if(palabra.length()>2){
            return validarPalabra(palabra, i, col, 1);
       }
        return 0;

    }

    else if (matriz[i][j-1].getLetra()!="[]"){
        recorrerHorizontalAux(i, j);
    }
    return jug.suma;
}

/**
 * Metodo auxiliar del recorrido horizontal
 * lo que hace es devolverse de derecha a izquierda hasta encontrar un [] para
 * poder volver a recorrerlo de izquierda a derecha posteriormente
 * @param i la fila donde inicia el recorrido
 * @param j la columna donde iniciar el recorrido
 */
void Tablero:: recorrerHorizontalAux(int i, int j){
    cout<<matriz [i][j-1].getLetra()<<endl;
    if(matriz[i][j-1].getLetra()!="[]"){
        for (int col= j-1; col >=0 ; col--) {
            if (matriz [ i][col].getLetra()=="[]") {
                recorrerHorizontal(i,col+1);
                break;
            }
            else if (col==0) {
                recorrerHorizontal(i,col);
                break;

            }
        }
    }
}

/**
 * Metodo para buscar palabras de manera vertical
 * @param i la fila donde iniciar el recorrido
 * @param j la columna donde iniciar el recorrido
 * @return el valor de la palabra formada
 */
int Tablero::recorrerVertical(int i, int j) {
    string palabra;
    jug.suma=0;
    int fil;
    if(i==0 || (matriz[i-1][j].getLetra())=="[]"){
        for (fil = i; fil < nFilas; fil++) {
            if ((matriz[fil][j].getLetra())!="[]") {
                jug.suma+= matriz [fil][j].getValor() +matriz [fil][j].getValorLetra();
                cout<<matriz[fil][j].getLetra()<<endl;
                palabra += matriz[fil][j].getLetra();
            } else {
                break;
            }

        }
        if(palabra.length()>2){
            return validarPalabra(palabra, fil, j, 0);
        }
        return 0;

    }
    else if (matriz[i-1][j].getLetra()!="[]"){
        recorrerVerticalAux(i, j);
    }return jug.suma;
}

/**
 * Metodo auxiliar del recorrer vertical
 * lo que hace es devolverse de abajo hacia arriba hasta encontrar un [] para
 * poder recorrer de arriba a abajo posteriormente
 * @param i la fila donde iniciar el recorrido
 * @param j la columna donde iniciar el recorrido
 */
void Tablero::recorrerVerticalAux(int i, int j) {
    cout<<matriz [i-1][j].getLetra()<<"  noguera"<<endl;
    if(matriz[i-1][j].getLetra()!="[]"){
        for (int fil = i-1; fil >=0; fil--) {
            if (matriz[ fil][j].getLetra()=="[]") {
                recorrerVertical(fil+1,j);
                break;
            }else if (fil==0) {
                recorrerHorizontal(i,fil);
                break;

            }

        }
    }
}

/**
 * Metodo para comprobar o validar que la palabra formada
 * se encuentra en un archivo txt que funciona como diccionario del juego
 * @param palabra la palabra a validar
 * @param suma el valor que posee esa palabra
 * @param i la fila en donde se termina la palabra
 * @param j la columna donde se termina la palabra
 * @param v parametro para verificar que metodo se llama despues
 * @return la suma o el valor de las palabras
 */
int Tablero::validarPalabra(string palabra, int i, int j, int v) {
    ifstream ip("/home/kennet/Scrabble/Proyecto/Tablero/lemario.txt");

    string datos;

    if(ip.fail()) cout<<"No se abrió el archivo"<<endl;

    else {
        while (!ip.eof()) {
            ip >> datos;
            if (datos == palabra) {
                if(v==0){
                    setRecorrerVertical(i, j);
                }
                else{
                    setRecorrerHorizontal(i, j);
                }
                return 0;
            }
        }
        if(v==0){
            eliminarVertical(i,j);
        }
        else{
            eliminarHorizontal(i,j);
        }
        jug.suma=0;
        cout<<"Hay que consultar al experto, turno perdido "<<jug.suma<<endl;
        return jug.suma;
    }
    ip.close();


}

/**
 * Metodo para borrar algun elemento del tablero
 * @param i la fila donde se encuentra el elemento
 * @param j la columna donde se encuentra el elemento
 */
void Tablero:: borrar(int i, int j){
    if(matriz[i][j].getLetra()!="[]"){
        matriz[i][j].setLetra("[]");
        matriz[i][j].setValorLetra(0);
        cout<< "Borrado exitosamente"<< endl;
    }
    else{
        cout << "Error"<< endl;

    }
}
/**
 * Metodo para borrar completamente una palabra de manera vertical
 * @param i la fila donde comenzar a borrar
 * @param j la columna donde empezar a borrar
 */
void Tablero::eliminarVertical(int i, int j) {
    if(matriz[i-1][j].getLetra()!="[]"){
        for (int fil = i-1; fil >=0; fil--) {
            if (matriz[fil][j].getLetra()=="[]" || matriz[fil][j].getRecorrido() ){
                break;
            }
            else{
                matriz [fil][j].setLetra("[]");
            }

        }
    }
}

/**
 * Metodo para eliminar por completo una palabra de manera horizontal
 * @param i la fila donde empezar a eliminar
 * @param j la columna donde empezar a eliminar
 */
void Tablero::eliminarHorizontal(int i, int j) {
    if(matriz[i][j-1].getLetra()!="[]"){
        for (int col= j-1; col >=0 ; col--) {
            if (matriz[i][col].getLetra()=="[]" || matriz[i][col].getRecorrido()) {
                break;
            }
            else{
                matriz [i][col].setLetra("[]");
            }
        }
    }
}

/**
 * Metodo para marcar como bloqueada las celdas en donde se encuentra
 * una palabra vertical que ya fue validada
 * @param i la fila en donde comenzar el recorrido
 * @param j la columna donde iniciar el recorrido
 */
void Tablero::setRecorrerVertical(int i, int j) {
    if(matriz[i-1][j].getLetra()!="[]"){
        for (int fil = i-1; fil >=0; fil--) {
            if (matriz [fil][j].getLetra()=="[]" || matriz[fil] [j].getRecorrido()) {
                break;
            }
            else{
                matriz[fil][j].setRecorrido(true);
            }
        }
    }
}

/**
 * Metodo para marcar como bloqueadas las celdas donde se
 * encuentra una palabra horizontal que ya fue validada
 * @param i la fila donde comenzar
 * @param j la columna donde comenzar
 */
void Tablero::setRecorrerHorizontal(int i, int j) {
    if(matriz[i][j-1].getLetra()!="[]"){
        for (int col= j-1; col >=0 ; col--) {
            if (matriz [i][col].getLetra()=="[]" || matriz[i][col].getRecorrido()) {
                break;
            }
            else{
                matriz [i][col].setRecorrido(true);
            }
        }
    }
}
