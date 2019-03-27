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

Dealer::Dealer() {

    string datos;

    ifstream ip("/home/saymon/CLionProjects/Proyecto/Dealer/letras.txt");

    if(ip.fail()) cout<< "Error al abrir el archivo"<<endl;

    else{

        while(!ip.eof()){
            ip>> datos;

            if(datos=="a"|| datos=="e" || datos== "o" || datos=="i" || datos=="s" ||
            datos =="n" || datos =="l" || datos== "r" || datos=="u" || datos=="t"){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(1);
                lista.add_head(*ficha);
            }
            else if(datos =="d" || datos==""){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(2);
                lista.add_head(*ficha);
            }
            else if(datos =="0"){
                auto *ficha= new Ficha();
                ficha->setLetra("");
                ficha->setValor(0);
                lista.add_head(*ficha);
            }
            else if(datos=="c" || datos== "b" || datos =="m" || datos == "p"){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(3);
                lista.add_head(*ficha);
            }
            else if(datos =="h"|| datos=="f" || datos == "v" || datos=="y" ){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(4);
                lista.add_head(*ficha);
            }
            else if(datos=="ch" || datos =="q"){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(5);
                lista.add_head(*ficha);
            }
            else if(datos=="j" || datos=="ll" || datos=="ñ" || datos=="rr" || datos=="x"){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(8);
                lista.add_head(*ficha);
            }
            else if(datos=="z"){
                auto *ficha= new Ficha();
                ficha->setLetra(datos);
                ficha->setValor(10);
                lista.add_head(*ficha);
            }

        }

    }



}

List<Ficha> Dealer::repartir() {

    List<Ficha> list;
    int cont =0;
    int n;
    cout<< lista.getTam()<< endl;

    while(cont<7) {
        n = rand() % lista.getTam()+1;

        Ficha ficha = this->lista.indice(n);
        list.add_head(ficha);
        lista.del_by_position(n);
        cont++;
    }
    cout<<lista.getTam()<<endl;
    return list;
}

