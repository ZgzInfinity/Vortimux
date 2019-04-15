/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 1-4-19 --------------------
 * ----------------------------------
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <fcntl.h>
#include "Arbol.h"
#include "graficos.h"
#include "tarjetaCredito.h"

// Umbrales de las ordenes
const int LIMITE_MINIMO = 0;
const int LIMITE_MAXIMO = 4;

// Codigos de tarjeta umbrales
const int TARJETA_MIN = 1;
const int TARJETA_MAX = 6;

// valores de color de fondo y fuente
const int FONDO_AZUL = 1;
const int COLOR_VERDE = 10;
const int COLOR_ROJO = 12;
const int COLOR_AMARILLO = 14;
const int COLOR_BLANCO = 15;

// longitud maxima del nombre de un fichero de tarjetas
const int MAX_LONG_FICHERO = 100;




/*
 * Pre: ---
 * Post: Ha almacenado en <<orden>> una orden valida metida
 *       por el usuario a traves del teclado
 */
void pedirOrden(int& orden){
    cout << endl;
    // Peticion al usuario de orden por teclado
    cout << " Introduzca una de las ordenes disponibles: " << flush;
    cin >> orden;

    // bucle de validacion de la orden
    while (orden < LIMITE_MINIMO || orden > LIMITE_MAXIMO){
        // mientras que la orden no sea valida la vuelve a pedir
        cout << " La orden " << orden << " no esta contemplada" << endl;
        cout << " Introduzca una de las ordenes disponibles: " << flush;
        cin >> orden;
    }
}




/*
 * Pre: ---
 * Post: Ha almacenado en <<orden>> una orden valida metida
 *       por el usuario a traves del teclado
 */
void pedirTipoTarjeta(int& tarjeta){
    cout << endl;
    // Peticion al usuario de tarjeta por teclado
    cout << " Introduzca uno de los tipos de tarjeta disponibles: " << flush;
    cin >> tarjeta;

    // bucle de validacion de la orden
    while (tarjeta < TARJETA_MIN || tarjeta > TARJETA_MAX){
        // mientras que la tarjeta no sea valida la vuelve a pedir
        cout << " La tarjeta " << tarjeta << " no esta contemplada" << endl;
        cout << " Introduzca uno de los tipos de tarjeta disponibles: " << flush;
        cin >> tarjeta;
    }
}




/*
 * Pre: <<orden>> es un codigo numerico que expresa una orden
 *      codificada por el usuario a traves del teclado
 * Post: Si la orden <<orden>> vale toma valor 1 ha generado una nueva
 *       tarjeta de credito. Si la orden <<orden>> vale 2 ha comprobado
 *       si una tarjeta introducida por el usuario es valida o no y si la
 *       orden toma valor 0 ha finalizado la ejecucion del programa
 */
void ejecutarOrden(const int& orden, Arbol& arbolGeneradas, Arbol& arbolValidas, Arbol& arbolInvalidas,
                    const char fichTarGeneradas[], const char fichTarValidas[], const char fichTarInvalidas[]){

    // Evaluacion del tipo de orden
    if (orden == 1){
        // Limpiar la pantalla
        clrscr();

        // Menu de tarjetas disponibles
        presentarTarjetas();

        // Peticion de tarjeta al usuario
        int codTarjeta;
        pedirTipoTarjeta(codTarjeta);

        // La orden es generar una tarjeta de credito
        string tarjeta;
        tarjeta = generarTarjeta(codTarjeta);

        // Cambio de color a blanco
        textcolor(COLOR_BLANCO);
        cout << endl << endl;
        // mostrar por pantalla la nueva tarjeta de credito
        cout << " Se ha generado la nueva tarjeta de credito ";
        mostrarTarjetaCredito(tarjeta);

		// Insercion de la tarjeta geenrada en el arbol de tarjetas generadas
		insertar(arbolGeneradas, tarjeta);
        cout << endl << endl << endl;
    }
    else if (orden == 2){
        // La orden pulsada es
        // Limpieza de la pantalla
        clrscr();
        // La orden es validar una tarjeta de credito
        string tarjeta;
        // Muestreo de la cuadricula de validacion
        dibujarCuadricula();
        // Peticion al usuario de introducir la tarjeta de credito
        introducirTarjetaCredito(tarjeta);
        // Comprobacion de si la tarjeta de credito es valida o no
        if (esTarjetaValida(tarjeta)){
            // Es valida
            // Cambiar fuente a verde
            textcolor(COLOR_VERDE);
            gotoxy(4, 13);
            cout << "La tarjeta de credito " << tarjeta << " es valida" << endl << endl << endl;

            insertar(arbolValidas, tarjeta);
        }
        else {
            // No es valida
            // Cambiar fuente a rojo
            textcolor(COLOR_ROJO);
            gotoxy(4, 13);
            cout << "La tarjeta de credito " << tarjeta << " no es una tarjeta valida" << endl << endl << endl;

			insertar(arbolInvalidas, tarjeta);
        }
    }
    else if (orden == 3){
        // Limpieza de pantalla
        clrscr();

        cout << endl;
        // la orden es la cuatro
        char nombreFichero[MAX_LONG_FICHERO];

        // Peticion al usuario de un fichero de tarjetas de credito
        cout << " Introduzca el nombre de un fichero de tarjetas de credito: " << flush;
        cin >> nombreFichero;

        // analalizar tarjetas de un fichero
        analizarTarjetasFichero(nombreFichero);
    }
    else {
        cout << endl << endl;
        textcolor(COLOR_BLANCO);

        cout << " Los ficheros de datos se han formateado " << endl;
        // la orden es 4
        // los ficheros se crean con permisos de escritura y lectura para todos los usuarios
        // truncar contenido de fichero de tarjetas de credito generadas
        creat(fichTarGeneradas, 0777);
        // truncar contenido de fichero de tarjetas de credito validas
        creat(fichTarValidas, 0777);
        // truncar contenido de fichero de tarjetas de credito invalidas
        creat(fichTarInvalidas, 0777);
    }
    // Cambiar fuente a amarillo
    textcolor(COLOR_AMARILLO);

    bool pulsada = false;

    // Capturar codigo de la tecla ENTER
    while (!pulsada){
        // Borrado de linea
        gotoxy(1, 18);
        clreol();

        // Vuelve a pedir tecla
        cout << " Pulsa INTRO para continuar";

        // Capturar tecla pulsada
        unsigned char tecla = getch();

        // Comprobacion de tecla ENTER
        if (int(tecla) == TECLA_ENTER){
            // Es la tecla ENTER
            pulsada = true;
        }
    }
}



/*
 * Vortimux es un generador y validador de tarjetas de credito.
 * Al comenzar el programa le muestra por pantalla al usuario un menu con las posibles
 * operaciones que es capaz de realizar. Si la orden y los posibles parametros que proporcionados
 * por el usuario son correctos Vortimux ejecuta la tarea en cuestion y retorna los resultados
 * obtenidos por pantalla. Una vez concluida la tarea pide otra al usuario hasta que se le manda la
 * orden de acabado
 */
int main (){
    // ficheros de almacenamiento de tarjetas generadas
    const char fichTarGeneradas[MAX_LONG_FICHERO] = "tarjetasGeneradas.txt";
    // fichero de almacenamiento de tarjetas validas
    const char fichTarValidas[MAX_LONG_FICHERO] = "tarjetasValidas.txt";
    // fichero de almacenamiento tarjetas invalidas
    const char fichTarInvalidas[MAX_LONG_FICHERO] = "tarjetasInvalidas.txt";

    // configurar color de la terminal
    textbackground(FONDO_AZUL);

    // configurar color de la fuente
    textcolor(COLOR_AMARILLO);

    // variable para almacenar las ordenes del usuario
    int orden;

    // Arbol binaria de busqueda para almacenar las tarjetas generadas por el usuario
    Arbol arbolTarGeneradas;
    // Arbol binario de busqueda para almacenar las tarjetas validas
    Arbol arbolTarValidas;
    // Arbol binario de busqueda para almacenar las tarjetas invalidas
    Arbol arbolTarInvalidas;

    // Inicio del arbol binario de tarjetas generadas
    crearArbol(arbolTarGeneradas);

    // Inicio del arbol binario de tarjetas validas
    crearArbol(arbolTarValidas);

    // Inicio del arbol binario de tarjetas invalidas
    crearArbol(arbolTarInvalidas);

    // Construir arbol de tarjetas generadas a partir de las tarjetas ya generadas
    generarArbol(arbolTarGeneradas, fichTarGeneradas);

     // Construir arbol de tarjetas validas a partir de las tarjetas validas
    generarArbol(arbolTarValidas, fichTarValidas);

     // Construir arbol de tarjetas invalidas a partir de las tarjetas invalidas
    generarArbol(arbolTarInvalidas, fichTarInvalidas);

    // Introduccion del programa
    introduccion();

    // Limpieza de pantalla
    system("cls");

    // bucle del mensaje cargando
    cargando();

    // Limpieza de pantalla
    clrscr();

    // Presentacion del menu de opciones al usuario por pantalla
    presentarMenu();

    // Peticion de orden al usuario
    pedirOrden(orden);

    while (orden != 0){
        // Orden de ejecucion valida

        // Ejecucion de la orden del usuario con los icheros y los arboles donde se va a almacenar
        ejecutarOrden(orden, arbolTarGeneradas, arbolTarValidas , arbolTarInvalidas, fichTarGeneradas, fichTarValidas, fichTarInvalidas);

        // Limpieza de la pantalla
        system("cls");

        // Vuelve a presentar el menu
        presentarMenu();

        // Volver a pedir una nueva tarea al usuario
        pedirOrden(orden);
    }

    // Reemplazar ficheros de tarjetas generadas con los nuevos datos y los anteriores
    generarFichero(arbolTarGeneradas, fichTarGeneradas);

    // Borrar contenido del arbol binarios de tarjetas generadas
    borrar(arbolTarGeneradas);

    // Reemplazar ficheros de tarjetas validas con los nuevos datos y los anteriores
    generarFichero(arbolTarValidas, fichTarValidas);

    // Borrar contenido del arbol binarios de tarjetas validas
    borrar(arbolTarValidas);

    // Reemplazar ficheros de tarjetas invalidas con los nuevos datos y los anteriores
    generarFichero(arbolTarInvalidas, fichTarInvalidas);

    // Borrar contenido del arbol binarios de tarjetas invalidas
    borrar(arbolTarInvalidas);

    // Fin de la ejecucion del programa
    return 0;
}
