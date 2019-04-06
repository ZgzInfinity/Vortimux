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
#include "Arbol.h"
#include "graficos.h"
#include "tarjetaCredito.h"

// umbrales de las ordenes
const int LIMITE_MINIMO = 0;
const int LIMITE_MAXIMO = 2;

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
    cout << "Introduzca una de las ordenes disponibles " << flush;
    cin >> orden;

    // bucle de validacion de la orden
    while (orden < LIMITE_MINIMO || orden > LIMITE_MAXIMO){
        // mientras que la orden no sea valida la vuelve a pedir
        cout << "La orden " << orden << " no esta contemplada" << endl;
        cout << "Introduzca una de las ordenes disponibles " << flush;
        cin >> orden;
    }
}


/*
 * Pre: <<orden>> es un codigo numerico que expresa una orden
 *      codificada por el usuario a traves del teclado
 * Post: Si la orden <<orden>> vale toma valor 1 ha generado una nueva
 *       tarjeta de credito. Si la orden <<orden>> vale 2 ha comprobado
 *       si una tarjeta introducida por el usuario es valida o no y si la ç
 *       orden toma valor 0 ha finalizado la ejecucion del programa
 */
void ejecutarOrden(const int& orden, Arbol& arbolGeneradas, Arbol& arbolValidas, Arbol& arbolInvalidas){

    // Evaluacion del tipo de orden
    if (orden == 1){
        // La orden es generar una tarjeta de credito
        string tarjeta;
        tarjeta = generarTarjeta();

        // Cambio de color a blanco
        // textcolor(COLOR_BLANCO);
        cout << endl << endl;
        // mostrar por pantalla la nueva tarjeta de credito
        cout << "Se ha generado la nueva tarjeta de credito ";
        mostrarTarjetaCredito(tarjeta);
		
		// Insercion de la tarjeta geenrada en el arbol de tarjetas generadas
		insertar(arbolGeneradas, tarjeta);
        cout << endl << endl << endl;
    }
    else{
        // La orden pulsada es
        // Limpieza de la pantalla
        // clrscr();
        // La orden es validar una tarjeta de credito
        string tarjeta;
        // Muestreo de la cuadricula de validacion
        // dibujarCuadricula();
        // Peticion al usuario de introducir la tarjeta de credito
        introducirTarjetaCredito(tarjeta);
        // Comprobacion de si la tarjeta de credito es valida o no
        if (esTarjetaValida(tarjeta)){
            // Es valida
            // Cambiar fuente a verde
            //textcolor(COLOR_VERDE);
            cout << "La tarjeta de credito " << tarjeta << " es valida" << endl << endl << endl;

            insertar(arbolValidas, tarjeta);
        }
        else {
            // No es valida
            // Cambiar fuente a rojo
            // textcolor(COLOR_ROJO);
            cout << "La tarjeta de credito " << tarjeta << " no es una tarjeta valida" << endl << endl << endl;
			
			insertar(arbolInvalidas, tarjeta);
        }
    }
    // Cambiar fuente a amarillo
    // textcolor(COLOR_AMARILLO);
    system("pause");
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
    const char fichTarjetasGeneradas[MAX_LONG_FICHERO] = "tarjetasGeneradas.txt";
    // fichero de almacenamiento de tarjetas validas
    const char fichTarjetasValidas[MAX_LONG_FICHERO] = "tarjetasValidas.txt";
    // fichero de almacenamiento tarjetas invalidas
    const char fichTarjetasInvalidas[MAX_LONG_FICHERO] = "tarjetasInvalidas.txt";

    // configurar color de la terminal
    //textbackground(FONDO_AZUL);

    // configurar color de la fuente
    // textcolor(COLOR_AMARILLO);

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
    generarArbol(arbolTarGeneradas, fichTarjetasGeneradas);

     // Construir arbol de tarjetas validas a partir de las tarjetas validas
    generarArbol(arbolTarValidas, fichTarjetasValidas);

     // Construir arbol de tarjetas invalidas a partir de las tarjetas invalidas
    generarArbol(arbolTarInvalidas, fichTarjetasInvalidas);


    // Limpieza de pantalla
    // clrscr();

    // Presentacion del menu de opciones al usuario por pantalla
    presentarMenu();

    // Peticion de orden al usuario
    pedirOrden(orden);

    while (orden != 0){
        // Orden de ejecucion valida

        // Ejecucion de la orden del usuario con los icheros donde se va a almacenar
        ejecutarOrden(orden, arbolTarGeneradas, arbolTarValidas , arbolTarInvalidas);

        // Limpieza de la pantalla
        // clrscr();

        // Vuelve a presentar el menu
        presentarMenu();

        // Volver a pedir una nueva tarea al usuario
        pedirOrden(orden);
    }

    // Reemplazar ficheros de tarjetas generadas con los nuevos datos y los anteriores
    generarFichero(arbolTarGeneradas, fichTarjetasGeneradas);

    // Borrar contenido del arbol binarios de tarjetas generadas
    borrar(arbolTarGeneradas);

    // Reemplazar ficheros de tarjetas validas con los nuevos datos y los anteriores
    generarFichero(arbolTarValidas, fichTarjetasValidas);

    // Borrar contenido del arbol binarios de tarjetas validas
    borrar(arbolTarValidas);

    // Reemplazar ficheros de tarjetas invalidas con los nuevos datos y los anteriores
    generarFichero(arbolTarInvalidas, fichTarjetasInvalidas);

    // Borrar contenido del arbol binarios de tarjetas invalidas
    borrar(arbolTarInvalidas);

    // Fin de la ejecucion del programa
    return 0;
}
