#include "tablero.h"
#include "juego.h"
#include <QDebug>

extern Juego* juego;

Tablero::Tablero(){

    //creo todas las posibles letras comodines y las agrego a una lista
    QString A = "a";
    letrasComodines.append(A);
    QString B = "b";
    letrasComodines.append(B);
    QString C = "c";
    letrasComodines.append(C);
    QString D = "d";
    letrasComodines.append(D);
    QString E = "e";
    letrasComodines.append(E);
    QString F = "f";
    letrasComodines.append(F);
    QString G = "g";
    letrasComodines.append(G);
    QString H = "h";
    letrasComodines.append(H);
    QString I = "i";
    letrasComodines.append(I);
    QString J = "j";
    letrasComodines.append(J);
    QString K = "k";
    letrasComodines.append(K);
    QString L = "l";
    letrasComodines.append(L);
    QString M = "m";
    letrasComodines.append(M);
    QString N = "n";
    letrasComodines.append(N);
    QString S = "s";
    letrasComodines.append(S);
    QString O = "o";
    letrasComodines.append(O);
    QString P = "p";
    letrasComodines.append(P);
    QString Q = "q";
    letrasComodines.append(Q);
    QString R = "r";
    letrasComodines.append(R);
    QString T = "t";
    letrasComodines.append(T);
    QString U = "u";
    letrasComodines.append(U);
    QString V = "v";
    letrasComodines.append(V);
    QString W = "w";
    letrasComodines.append(W);
    QString X = "x";
    letrasComodines.append(X);
    QString Y = "y";
    letrasComodines.append(Y);
    QString Z = "z";
    letrasComodines.append(Z);
    QString LL = "ll";
    letrasComodines.append(LL);
    QString RR = "rr";
    letrasComodines.append(RR);
    QString CH = "ch";
    letrasComodines.append(CH);
}

QList<Ficha *> Tablero::getFichas(){
    return fichas;
}

void Tablero::ponerFichas(int x,int y,int columnas,int filas){
    //crear la cuadricula del tablero
    int X_SHIFT = 45;
    for (size_t i = 0,n = columnas; i < n;i++){
        crearColumnaFichas(x+X_SHIFT*i,y,filas);

        //les agrego sus letras
        for(size_t i = 0, n = letrasComodines.size(); i < n ; i++){

        }
    }


}

void Tablero::ponerComodines(int x, int y, int columnas, int filas){
    //crear una cuadricula con el abecedario
    int X_ES = 50;
    for(size_t i = 0, n = columnas; i < n ; i++){
        crearColumnaComodines(x+X_ES*i,y,filas);
    }

}

void Tablero::ponerLetrasComodines(QList<Comodin*> misComodines){
    for(size_t i = 0, n = letrasComodines.size() ; i < n ; i++){
        misComodines[i]->setTexto(letrasComodines[i]);
    }

}

void Tablero::valoresMatrix(){
    int contador = 0;
    int fila = 0;
    int columna = 0;
    while(contador < fichas.size()){
        if(fila == 15){
            fila = 0;
            columna++;
        }

        fichas[contador]->setFila(fila);
        fichas[contador]->setColumna(columna);

        fila ++;

        contador++;

    }

}

void Tablero::crearColumnaFichas(int x, int y, int numFilas){
    // crear una columna de fichas con datos especificos

    for (size_t i = 0, n = numFilas; i<n;i++){
        Ficha* ficha = new Ficha();
        ficha->setPos(x,y+45*i);

        //configurar la posicion original de la ficha en el tablero
        ficha->posicionOriginal = ficha->pos();
        fichas.append(ficha);
        juego->escena->addItem(ficha);

        //poner el dueño por default = NADIE
        ficha->setDueno(QString("NADIE"));
        ficha->setEstaPuesta(true);



    }
}

void Tablero::crearColumnaComodines(int x, int y, int numFilas){
    //crear una columna de comodines con datos especificos
    for(size_t i = 0, n = numFilas; i < n; i++){
        Comodin* comodin = new Comodin();
        comodin->setPos(x,y+50*i);
        //le pongo la letra coorrespondiente
        //comodin->setTexto(QString("W"));
        comodines.append(comodin);
        //agrego comodines a la lista de juego
        juego->misComodines.append(comodin);
        juego->escena->addItem(comodin);

        //aqui se les debe de asignar las letras

    }

}


