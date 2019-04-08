//
// Created by saymon on 17/03/19.
//

#include "Dealer.h"
#include "../Estructuras/List.h"
#include "../Estructuras/List.cpp"
#include "Ficha.h"
#include <locale.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>
#include <include/rapidjson/document.h>
#include <Converter/Converter.h>

using namespace std;
using namespace rapidjson;

Dealer* Dealer::instance=0;
/**
 * @brief Dealer::getInstance
 * @return instancia de dealer lo cual es un singleton
 */
Dealer* Dealer::getInstance()
{
    if (instance == 0)
    {
        instance = new Dealer();
    }

    return instance;
}


/**
 * Constructor del Dealer
 * lo que hace esta clase es leer el archivo txt con el total de letras
 * y asigna el valor a cada letra dependiendo de cual se trate
 */

Dealer::Dealer() {

    string datos;

    ifstream ip("/home/kennet/Scrabble/Proyecto/Dealer/letras.txt");

    if(ip.fail()) cout<< "Error al abrir el archivo"<<endl;

    else{

        while(!ip.eof()){
            ip>> datos;

            if(datos=="a"|| datos=="e" || datos== "o" || datos=="i" || datos=="s" ||
            datos =="n" || datos =="l" || datos== "r" || datos=="u" || datos=="t"){
                auto *ficha= new Ficha(datos, 1);
                lista.append(ficha);
            }
            else if(datos =="d" || datos =="g"){
                auto *ficha= new Ficha(datos, 2);
                lista.append(ficha);

            }
            else if(datos == "0"){
                auto *ficha= new Ficha("0",0);
                lista.append(ficha);

            }
            else if(datos=="c" || datos== "b" || datos =="m" || datos == "p"){
                auto *ficha= new Ficha(datos, 3);
                lista.append(ficha);

            }
            else if(datos =="h"|| datos=="f" || datos == "v" || datos=="y" ){
                auto *ficha= new Ficha(datos,4);
                lista.append(ficha);

            }
            else if(datos=="ch" || datos =="q"){
                auto *ficha= new Ficha(datos, 5);
                lista.append(ficha);

            }
            else if(datos=="j" || datos=="ll" || datos=="ñ" || datos=="rr" || datos=="x"){
                auto *ficha= new Ficha(datos, 8);
                lista.append(ficha);

            }
            else if(datos=="z"){
                auto *ficha= new Ficha(datos,10);
                lista.append(ficha);
            }
        }
    }
}

/**
 * Esta función reparle las cartas a cada jugador
 * @param jugadores el numero de jugadores totales
 * @return una lista con fichas
 */
string Dealer::repartir(int jugadores) {

    static auto converter = Converter::getInstance();

    int cartas = 80/jugadores;

    QList<Ficha*> list;
    int cont =0;
    Ficha *ficha1;
    int n;

    while(cont<cartas) {
        srand(time(NULL));

        n = rand() % lista.size();
        ficha1 = lista[n];
        if(lista.size()<=1){
            list.append(ficha1);
            break;
        }
        list.append(ficha1);
        lista.removeAt(n);
        cont++;

    }


    return converter->FichasToJson(list);
}
