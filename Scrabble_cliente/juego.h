#ifndef JUEGO_H
#define JUEGO_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include "tablero.h"
#include "socketcliente.h"
#include "Converter.h"
#include <QMediaPlayer>


/**
 * @brief The Juego class Constrola el funcionamiento principal del juego.
 */
class Juego: public QGraphicsView{
    Q_OBJECT
public:
    /**
     * @brief Juego Constructor.
     * @param parent
     */
    Juego(QWidget* parent = NULL);


    //eventos del mouse
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief ProyectarGameOver Muestra la terminacion del juego.
     */
    void ProyectarGameOver();

    QString getTurnoDe();
    void setTurnoDe(QString TurnoDe);
    void levantarCarta(Ficha* carta);
    void ponerCarta(Ficha* fichaPorReemplazar);
    /**
     * @brief GenerarListaConexion Recibe los datos desde la ventana anterior.
     * @param json El json
     * @param c La conexion.
     * @param nombre El nombre.
     * @param miTurno El turno.
     */
    void GenerarListaConexion(QString json, SocketCliente *c, QString nombre, bool miTurno);
    /**
     * @brief ActualizarPuntajes actualiza los puntajes.
     * @param nombres Los nombres.
     * @param puntajes Los puntajes.
     */
    void ActualizarPuntajes(QList<QString> nombres, QList<int> puntajes);


    void setTextoJugador1(QString texto);
    void setTextoJugador2(QString texto);
    void setTextoJugador3(QString texto);
    void setTextoJugador4(QString texto);
    void setTextoPuntaje1(int puntaje);
    void setTextoPuntaje2(int puntaje);
    void setTextoPuntaje3(int puntaje);
    void setTextoPuntaje4(int puntaje);
    void siguienteTurno();
    void dibujarPanelComodin();
    void quitarComodines();
    void setBloqueo(bool b);
    bool getBloqueo();
    //en caso de que la palabra formada no sea válida
    void devolverCartasJugadas();
    //en caso de que la palabra formada sea valida,
    //entonces se deben eliminary reemplazar las fichas
    void eliminarFichasTablero();


    //metodo para recibir las cartas actualizadas
    //luego se actualiza el tablero con las nuevas fichas
    void actualizarTablero();




    //atributos publicos
    QGraphicsScene* escena;
    Tablero* tablero;
    Ficha* cartaParaPoner;
    QPointF posicionOriginal;
    QPointF posicionReemplazo;
    SocketCliente *conexion3;

    /////////////////////
    bool bloqueoturno;


    //partes de los comodines
    QList<Comodin*> misComodines;
    QGraphicsRectItem* rectComodines;
    QGraphicsTextItem* textoComodines;

    //lista de las fichas que se colocan en mi turno
    QList<Ficha*> fichasJugadas;

    //lista de fichas por actualizar
    QList<Ficha*> listaActualizar;

    //lista de fichas de tablero que se deben eliminar en caso de que la palabra sea valida
    QList<Ficha*> fichasTableroPorEliminar;

    //Esta lista almacena las fichas que me llegan al inicio.
    QList<Ficha*> ListaTotal;

    //Esta lista va a guardar las posiciones de las cartas que se ponen
    //en caso de que la palabra no sea válida
    QList<QPointF> listaPosicionesOriginales;

    //el puntero del sonido
    QMediaPlayer *jueputa;



public slots:
    void Iniciar();
    void EnviarDatosServidor();
    void RecibirMensaje2(QString mensaje);
    void sendMensaje(string msj);
    void abrirVentanaInicio();

private:
    //metodos privados
    void DibujarPanel(int x,int y,int width,int height,QColor color,double opacity);
    void DibujarInterfazInteractiva();
    void DibujarCapaNegra();
    void crearNuevaCarta(QString jugador);


    void crearCartasIniciales();
    void dibujarCartas();
    void dibujarCarta(QPointF pos);


    //atributos privados
    QString turnoDe;
    QGraphicsTextItem* turnoDeTexto;
    QList<Ficha*> fichasJugador;
    //variable que bloque y desbloquea
    bool Bloqueo;
    Converter *converter;





    //nombre de los jugadores
    QGraphicsTextItem *jugador1;
    ///////////////////
    QString mn;
    ///////////////////
    QString j1;
    QGraphicsTextItem *jugador2;
    QString j2;
    QGraphicsTextItem *jugador3;
    QString j3;
    QGraphicsTextItem *jugador4;
    QString j4;

    //Porcentaje de los jugadores
    QGraphicsTextItem *puntaje1;
    int p1;
    QGraphicsTextItem *puntaje2;
    int p2;
    QGraphicsTextItem *puntaje3;
    int p3;
    QGraphicsTextItem *puntaje4;
    int p4;


};

#endif // JUEGO_H
