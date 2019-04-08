#include "juego.h"
#include "tablero.h"
#include "boton.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QDebug>
#include <QMediaPlayer>

#include "inicio_ventana.h"



Juego::Juego(QWidget *parent){
    // proyectar la pantalla
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,695);

    //configurar la escena
    escena = new QGraphicsScene();
    escena->setSceneRect(0,0,1200,695);
    setScene(escena);

    //inicializar las variables
    cartaParaPoner = NULL;

    //inicializo en contador en 0


    converter = Converter::getInstance();

    jueputa = new QMediaPlayer();

    jueputa->setMedia(QUrl("qrc:/sonidos/jueputa.wav"));

    bloqueoturno = false;





}

void Juego::mouseMoveEvent(QMouseEvent *event){
    //si hay una carta por poner, entonces siga el mouse
    if(cartaParaPoner){
        //cartaParaPoner->setPos(event->pos()); // le mando la posicion del cursor
        cartaParaPoner->setPos(event->x()+10,event->y());
    }
    QGraphicsView::mouseMoveEvent(event);

}

void Juego::mousePressEvent(QMouseEvent *event){
    //comprobar si es click derecho o click izquierdo
    //click derecho devuelve la carta a la posicion original
    if (event->button() == Qt::RightButton){
        if(cartaParaPoner && cartaParaPoner->getEsComodin() == false){
            cartaParaPoner->setPos(posicionOriginal);
            cartaParaPoner = NULL;
            return;
        }
    }
    QGraphicsView::mousePressEvent(event);


}

void Juego::Iniciar(){
    //limpiar la escena
    escena->clear();
    connect(conexion3,SIGNAL(NewMensaje(QString)),SLOT(RecibirMensaje2(QString)));
    //crear el tablero
    qDebug()<<"el momento preciso";

    DibujarCapaNegra();
    tablero = new Tablero();
    tablero->ponerFichas(500,10,15,15);
    //le doy las posiciones de la matriz
    tablero->valoresMatrix();

    DibujarInterfazInteractiva();
    crearCartasIniciales();




}

void Juego::EnviarDatosServidor(){

    if(fichasJugadas.size() != 0 ){

        sendMensaje(converter->PalabraToJson(fichasJugadas));

        /*if(jueputa->state() == QMediaPlayer::PlayingState){
            jueputa->setPosition(0);
        }
        else if(jueputa->state() == QMediaPlayer::StoppedState){
            jueputa->play();
        }*/


    }


}

void Juego::RecibirMensaje2(QString mensaje){
    qDebug()<<"mensaje desde juego"<<mensaje;

    //mando el mensaje a la función general para activar o desactivar flags
    converter->funcionGeneral(mensaje.toStdString().c_str());


    if(converter->llegaResultado){
        qDebug()<<"entrando a llegaResultado";
        int resultado = converter->confirmarPalabra(QString(mensaje).toStdString().c_str());
        if(resultado == 0){
            qDebug()<<"La palabra no ha sido aceptada, voy a devolver las cartas";
            devolverCartasJugadas();
            qDebug()<<"Cartas devueltas";

            converter->llegaResultado = false;
        }
        else{
            qDebug()<<"palabra aceptada, voy a eliminar las fichas del tablero";
            eliminarFichasTablero();
            qDebug()<<"Fichas del tablero eliminadas";
            converter->llegaResultado = false;
        }
    }
    else if(converter->llegaPalabra){
        qDebug()<<"entrando a llegapalabra";
        converter->jsonToPalabra(mensaje.toStdString().c_str());
        listaActualizar = converter->fichasActualizacion;

        //limpio la lista
        converter->fichasActualizacion.clear();
        qDebug()<<"Voy a actualizar el tablero";
        actualizarTablero();
        qDebug()<<"Tablero actualizado";
        converter->llegaPalabra = false;

    }
    else if(converter->llegaPuntajes){
        ActualizarPuntajes(converter->nombres, converter->puntajes);
        converter->puntajes.clear();
        converter->nombres.clear();
        converter->llegaPuntajes = false;
    }
    else if(converter->llegaTurno){
        setTurnoDe(converter->turnoDe);

        converter->llegaTurno = false;
    }


}

void Juego::sendMensaje(string msj){
    conexion3->setMensaje(msj.c_str());

    qDebug() << "paso la prueba";
}

void Juego::DibujarPanel(int x, int y, int width, int height, QColor color, double opacity){
    //dibujar un panel con los datos e fichas del jugador
    QGraphicsRectItem *panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity); //la transparencia
    escena->addItem(panel);

}

void Juego::DibujarInterfazInteractiva(){
    //dibujar el panel a la izquierda
    DibujarPanel(320,10,150,675,Qt::darkYellow,0.5);


    //poner los textos

    //la fuente
    QFont fuenteTexto("comic sans",15);

    QGraphicsTextItem *jugadorTexto = new QGraphicsTextItem("Fichas disponibles");
    jugadorTexto->setPos(340,20);
    escena->addItem(jugadorTexto);

    //poner el texto que dice de quien es el turno
    turnoDeTexto = new QGraphicsTextItem();
    turnoDeTexto->setPos(15,20);
    escena->addItem(turnoDeTexto);






    //poner el nombre de los jugadores
    jugador1 = new QGraphicsTextItem("");
    jugador1->setPos(10,80);
    jugador1->setFont(fuenteTexto);
    escena->addItem(jugador1);

    jugador2= new QGraphicsTextItem("");
    jugador2->setPos(10,150);
    jugador2->setFont(fuenteTexto);
    escena->addItem(jugador2);

    jugador3 = new QGraphicsTextItem("");
    jugador3->setPos(10,220);
    jugador3->setFont(fuenteTexto);
    escena->addItem(jugador3);

    jugador4 = new QGraphicsTextItem("");
    jugador4->setPos(10,290);
    jugador4->setFont(fuenteTexto);
    escena->addItem(jugador4);

    //poner los puntajes de los jugadores
    puntaje1 = new QGraphicsTextItem("");
    puntaje1->setPos(120,80);
    puntaje1->setFont(fuenteTexto);
    escena->addItem(puntaje1);

    puntaje2 = new QGraphicsTextItem("");
    puntaje2->setPos(120,150);
    puntaje2->setFont(fuenteTexto);
    escena->addItem(puntaje2);

    puntaje3 = new QGraphicsTextItem("");
    puntaje3->setPos(120,220);
    puntaje3->setFont(fuenteTexto);
    escena->addItem(puntaje3);

    puntaje4 = new QGraphicsTextItem("");
    puntaje4->setPos(120,290);
    puntaje4->setFont(fuenteTexto);
    escena->addItem(puntaje4);

    //crear el boton scrabble
    Boton* botonScrabble = new Boton(QString("SCRABBLE"));
    botonScrabble->setPos(20,610);
    connect(botonScrabble,SIGNAL(clicked()),this,SLOT(EnviarDatosServidor()));
    escena->addItem(botonScrabble);






}

void Juego::DibujarCapaNegra(){
    DibujarPanel(0,0,1200,695,Qt::black,0.7);
}

void Juego::crearNuevaCarta(QString jugador){
    Ficha* carta = new Ficha();
    carta->setDueno(jugador);
    carta->setEstaPuesta(false);
    //aqui se le da una letra a la carta. Proveniente del Servidor
    carta->setTexto(QString("K"));
    carta->setValor(5);
    //por default las cartas no son comodines
    carta->setEsComodin(false);
    //para pruebas ponemos todas las cartas de la baraja como comodines
    //carta->setEsComodin(true);
    //hacer las letras visibles
    carta->letrasVisibles();
    //se le agrega a la lista de cartas
    fichasJugador.append(carta);
    //dibujar la carta en el panel
    //dibujarCartas();

}



void Juego::crearCartasIniciales(){
    //estas son las cartas que llegan desde el servidor para
    //cada jugador
    /*for (size_t i = 0, n = 14; i<n;i++){
        crearNuevaCarta(QString("JUGADOR"));
    }*/

    //tomo las fichas que me llegan del servidor y las dibujo


    //dibujar las cartas
    dibujarCartas();


}

void Juego::dibujarCartas(){
    //poner las cartas de la lista en la pantalla

    for(int i = 0, n = ListaTotal.size(); i < 14; i++){
        Ficha* carta = ListaTotal[i];
        carta->setPos(370,50+45*i);

        //guardo su posicion original
        carta->posicionOriginal = carta->pos();
        escena->addItem(carta);
    }
    //elimino las fichas dibujadas de la lista
    qDebug()<<ListaTotal.size();
    for(int i = 0, n = ListaTotal.size(); i < 14 ; i++){
        ListaTotal.removeAt(0);

    }

}

void Juego::dibujarCarta(QPointF pos){
    if(ListaTotal.size() != 0){
        qDebug()<<ListaTotal.size();
        Ficha *ficha = ListaTotal.first();
        ficha->setPos(pos);
        ficha->posicionOriginal = ficha->pos();
        escena->addItem(ficha);
        ListaTotal.removeAll(ListaTotal.first());
    }
}

void Juego::ProyectarGameOver(){
    //crear el titulo como texto
    QGraphicsTextItem* titulo = new QGraphicsTextItem(QString("GAME OVER"));
    QFont fuenteTitulo("comic sans",50);
    titulo->setFont(fuenteTitulo);
    int txPos = this->width()/2 - titulo->boundingRect().width()/2;
    int tyPos = 150;
    titulo->setPos(txPos,tyPos);
    escena->addItem(titulo);
    //crear el boton "Jugar Otra vez"
    Boton* nuevoJuego = new Boton(QString("Jugar otra vez"));
    int bxPos = this->width()/2 - nuevoJuego->boundingRect().width()/2;
    int byPos = 275;
    nuevoJuego->setPos(bxPos,byPos);
    connect(nuevoJuego,SIGNAL(clicked()),this,SLOT(abrirVentanaInicio()));
    escena->addItem(nuevoJuego);
    //crear el boton "Salir"
    Boton* salir= new Boton(QString("Salir"));
    int b2xPos = this->width()/2 - salir->boundingRect().width()/2;
    int b2yPos = 350;
    salir->setPos(b2xPos,b2yPos);
    connect(salir,SIGNAL(clicked()),this,SLOT(close()));
    escena->addItem(salir);
}
void Juego::abrirVentanaInicio(){
    inicio_ventana *ventanaInicial = new inicio_ventana();
    ventanaInicial->show();
    close();
}

QString Juego::getTurnoDe(){
    return turnoDe;

}

void Juego::setTurnoDe(QString TurnoDe){

    turnoDe = TurnoDe;
    QFont fuenteTexto("comic sans",15);
    turnoDeTexto->setPlainText(QString("Es turno de : ")+ TurnoDe);
    turnoDeTexto->setFont(fuenteTexto);

    if(mn == turnoDe){
        bloqueoturno = false;

    }
    else if(mn != turnoDe){
        bloqueoturno = true;
    }

}

void Juego::levantarCarta(Ficha *carta){
    //levantar una carta especifica
    if(cartaParaPoner == NULL){
        cartaParaPoner = carta;
        posicionOriginal = carta->pos();
        posicionReemplazo = carta->pos();
      return;
    }
}

void Juego::ponerCarta(Ficha *fichaPorReemplazar){
    //reemplaza la ficha especifia por la "fichaParaPoner"
    cartaParaPoner->setPos(fichaPorReemplazar->pos());
    tablero->getFichas().removeAll(fichaPorReemplazar);
    tablero->getFichas().append(cartaParaPoner);

    //agregar la posicion de la carta puesta en la lista de posiciones
    listaPosicionesOriginales.append(cartaParaPoner->posicionOriginal);
    //agrego la ficha seleccioné en el tablero
    fichasTableroPorEliminar.append(fichaPorReemplazar);
    //recordar cambiar el estaPuesta
    cartaParaPoner->setFila(fichaPorReemplazar->getFila());
    cartaParaPoner->setColumna(fichaPorReemplazar->getColumna());
    //la agrego a la lista de fichas jugadas
    fichasJugadas.append(cartaParaPoner);

    cartaParaPoner->setEstaPuesta(true);
    cartaParaPoner = NULL;
    //siguienteTurno();

}

void Juego::GenerarListaConexion(QString json,SocketCliente *c,QString nombre, bool miTurno){
      //le paso la lista y el socket creado en las venatanas anteriores
    qDebug()<<"generando lista";

      ListaTotal = converter->JsonToFicha(json.toStdString().c_str());
      conexion3 = c;

      //inicializo mi nombre
      mn = nombre;
      qDebug()<<"turno"<<miTurno;
      if(miTurno == true){
          bloqueoturno = false;
          qDebug()<<"turno actualizado";
      }
      else if(miTurno == false){
          bloqueoturno = true;
      }

      qDebug()<<"lista generada";



}

void Juego::ActualizarPuntajes(QList<QString> nombres, QList<int> puntajes){
    if(nombres.size() == 2){
        j1 = nombres[0];
        j2 = nombres[1];
        setTextoJugador1(j1);
        setTextoJugador2(j2);

        p1 = puntajes[0];
        p2 = puntajes[1];
        setTextoPuntaje1(p1);
        setTextoPuntaje2(p2);

    }
    else if(nombres.size() == 3){
        j1 = nombres[0];
        j2 = nombres[1];
        j3 = nombres[2];
        setTextoJugador1(j1);
        setTextoJugador2(j2);
        setTextoJugador3(j3);

        p1 = puntajes[0];
        p2 = puntajes[1];
        p3 = puntajes[2];
        setTextoPuntaje1(p1);
        setTextoPuntaje2(p2);
        setTextoPuntaje3(p3);




    }
    else if(nombres.size() == 4){
        j1 = nombres[0];
        j2 = nombres[1];
        j3 = nombres[2];
        j4 = nombres[3];
        setTextoJugador1(j1);
        setTextoJugador2(j2);
        setTextoJugador3(j3);
        setTextoJugador4(j4);

        p1 = puntajes[0];
        p2 = puntajes[1];
        p3 = puntajes[2];
        p4 = puntajes[3];
        setTextoPuntaje1(p1);
        setTextoPuntaje2(p2);
        setTextoPuntaje3(p3);
        setTextoPuntaje4(p4);


    }



}



void Juego::setTextoJugador1(QString texto){
    jugador1->setPlainText(texto);

}

void Juego::setTextoJugador2(QString texto){
    jugador2->setPlainText(texto);

}

void Juego::setTextoJugador3(QString texto){
    jugador3->setPlainText(texto);
}

void Juego::setTextoJugador4(QString texto){
    jugador4->setPlainText(texto);

}

void Juego::setTextoPuntaje1(int puntaje){
    puntaje1->setPlainText(QString::number(puntaje));

}

void Juego::setTextoPuntaje2(int puntaje){
    puntaje2->setPlainText(QString::number(puntaje));

}

void Juego::setTextoPuntaje3(int puntaje){
    puntaje3->setPlainText(QString::number(puntaje));

}

void Juego::setTextoPuntaje4(int puntaje){
    puntaje4->setPlainText(QString::number(puntaje));

}


void Juego::siguienteTurno(){
    if (getTurnoDe() == QString("JUGADOR")){
        setTurnoDe(QString("JUGADOR"));
    }

}


void Juego::dibujarPanelComodin(){
    rectComodines = new QGraphicsRectItem(10,300,305,300);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    rectComodines->setBrush(brush);
    rectComodines->setOpacity(0.5);

    //texto para seleccionar las fichas comodin
    textoComodines = new QGraphicsTextItem("COMODINES");
    textoComodines->setPos(120,305);
    //se añaden a la escena
    escena->addItem(rectComodines);
    escena->addItem(textoComodines);
    //agregar los posibles comodines
    tablero->ponerComodines(15,330,6,5);
    //les pongo una letra
    tablero->ponerLetrasComodines(misComodines);

}

void Juego::quitarComodines(){
    //se eliminan los comodines guardados en la lista de juego
    for(size_t i = 0, n=misComodines.size(); i < n; i++){
        escena->removeItem(misComodines[i]);
    }
    //se elimina el rectangulo
    escena->removeItem(rectComodines);

    //se elimina el texto de comodines
    escena->removeItem(textoComodines);

    //se limpia la lista de comodines
    misComodines.clear();



}

void Juego::setBloqueo(bool b){
    Bloqueo = b;

}

bool Juego::getBloqueo(){
    return Bloqueo;

}

void Juego::devolverCartasJugadas(){
    //primero se les setea la posicion original a cada una de las partes
    qDebug()<<"Tamaño"<<fichasJugadas.size();
    for(int i = 0, n = fichasJugadas.size(); i < n ; i++){
        //les doy la posicion original
        fichasJugadas[i]->setPos(fichasJugadas[i]->posicionOriginal);
        //las convierto de nuevo en cartas de la baraja
        fichasJugadas[i]->setEstaPuesta(false);
    }
    //ahora limpio la lista
    fichasJugadas.clear();
    fichasTableroPorEliminar.clear();
}

void Juego::eliminarFichasTablero(){
    //se elimnan las fichas de la escena
    for(size_t i = 0, n = fichasTableroPorEliminar.size(); i < n ; i++){
        escena->removeItem(fichasTableroPorEliminar[i]);
    }
    //ahora se limpia la lista
    fichasTableroPorEliminar.clear();

    //ahora se agregan nuevas cartas de la ListaTotal
    for(int i = 0; i < listaPosicionesOriginales.size(); i++){
        dibujarCarta(listaPosicionesOriginales[i]);
    }
    qDebug()<<"las cartas se han generado";
    //ahora se eliminan los elementos de la lista
    listaPosicionesOriginales.clear();
    //y se limpia los elementos de fichasJugadas
    fichasJugadas.clear();
}

void Juego::actualizarTablero(){
    for(size_t i = 0, n = listaActualizar.size(); i < n ; i++){
        int fila = listaActualizar[i]->getFila();
        int columna = listaActualizar[i]->getColumna();

        //busco la posicion en el tablero
        for(size_t j = 0, n = tablero->fichas.size(); j < n ; j++){
            //si la fila y la columna coinciden
            if(tablero->fichas[j]->getFila() == fila && tablero->fichas[j]->getColumna() == columna){
                //pongo la ficha por actualizar, en la posicion de la ficha
                //en el tablero
                listaActualizar[i]->setPos(tablero->fichas[j]->pos());

                //la agrego a la escena
                escena->addItem(listaActualizar[i]);

                //eliminamos la ficha vacia
                tablero->fichas.removeAll(tablero->fichas[j]);
                //cortamos el bucle
                break;
            }
        }
    }

    //se limpia la lista de las cartas por actualizar
    listaActualizar.clear();

}


