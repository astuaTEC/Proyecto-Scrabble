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
#include <writer.h>

using namespace std;
#include <document.h>
#include <Converter/Converter.h>

using namespace rapidjson;

/**
 * Constructor del Dealer
 * lo que hace esta clase es leer el archivo txt con el total de letras
 * y asigna el valor a cada letra dependiendo de cual se trate
 */

Dealer::Dealer() {

    string datos;

    ifstream ip("/home/saymon/CLionProjects/Proyecto/Dealer/letras.txt");

    if(ip.fail()) cout<< "Error al abrir el archivo"<<endl;

    else{

        while(!ip.eof()){
            ip>> datos;

            if(datos=="a"|| datos=="e" || datos== "o" || datos=="i" || datos=="s" ||
            datos =="n" || datos =="l" || datos== "r" || datos=="u" || datos=="t"){
                auto *ficha= new Ficha(datos, 1);
                lista.add_head(*ficha);
            }
            else if(datos =="d" || datos =="g"){
                auto *ficha= new Ficha(datos, 2);
                lista.add_head(*ficha);

            }
            else if(datos =="0"){
                auto *ficha= new Ficha("",0);
                lista.add_head(*ficha);

            }
            else if(datos=="c" || datos== "b" || datos =="m" || datos == "p"){
                auto *ficha= new Ficha(datos, 3);
                lista.add_head(*ficha);

            }
            else if(datos =="h"|| datos=="f" || datos == "v" || datos=="y" ){
                auto *ficha= new Ficha(datos,4);
                lista.add_head(*ficha);

            }
            else if(datos=="ch" || datos =="q"){
                auto *ficha= new Ficha(datos, 5);
                lista.add_head(*ficha);

            }
            else if(datos=="j" || datos=="ll" || datos=="ñ" || datos=="rr" || datos=="x"){
                auto *ficha= new Ficha(datos, 8);
                lista.add_head(*ficha);

            }
            else if(datos=="z"){
                auto *ficha= new Ficha(datos,10);
                lista.add_head(*ficha);

            }

        }

    }



}
/**
 * Esta función reparle las cartas a cada jugador
 * @param jugadores el numero de jugadores totales
 * @return una lista con fichas
 */
void Dealer::repartir(int jugadores) {

    static auto converter = Converter::getInstance();

    int cartas = lista.getTam()/jugadores;

    List<Ficha> list;
    int cont =0;
    int n;
    cout<< lista.getTam()<< endl;

    while(cont<cartas) {
        n = rand() % lista.getTam()+1;
        Ficha ficha = this->lista.indice(n);
        list.add_head(ficha);
        lista.del_by_position(n);
        cont++;
    }
    cout<<lista.getTam()<<endl;
    cout<<list.getTam()<<endl;
    cout<<list.indice(0).getLetra()<<endl;
    converter->FichasToJson(&list);
}
