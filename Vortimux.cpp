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
 * Pre: <<tarjeta>> es una secuencia de caracteres que conforma una
 *      tarjeta de credito y <<fichero>> es un fichero de texto que
 *      almacena tarjetas de credito a razon de una por linea
 * Post: Ha devuelto <<true>> si en el fichero de tarjetas de credito
 *       <<fichero>> existe una tarjeta de credito igual a <<tarjeta.
 *       Si no se ha podido leer el fichero o no existe la tarjeta
 *       <<tarjeta>> en el ha devuelto <<false>>
 */
bool existeTarjetaCredito(const string& tarjeta, const char fichero[]){
    // flujo de lectura asociado al fichero de tarjetas de credito
    ifstream f;
    f.open(fichero);
    if (f.is_open()){
        // variable que guarda la ultima tarjeta del fichero leida
        string tarjetaActual;
        // El fichero se ha abierto correctamente
        bool encontrado = false;
        // bucle de busqueda secuencial
        f >> tarjetaActual;
        while (!encontrado && !f.eof()){
            // mientras no se halla encontrado o queden tarjetas por evaluar
            if (tarjetaActual == tarjeta){
                // tarjeta buscada encontrada
                encontrado = true;
            }
            else {
                // lectura de una nueva tarjeta del fichero
                f >> tarjetaActual;
            }
        }
        // cierre del flujo de lectura asociado al fichero
        f.close();
        return encontrado;
    }
    else {
        // El fichero no se ha podido abrir
        cerr << "El fichero " << fichero << " no se ha podido lerr" << endl;
        return false;
    }
}


/*
 * Pre: <<tarjeta>> es una tarjeta de credito generada de forma automatica o que
 *      ha sido introducida por el usuario para comprobar su validez y <<nombreFichero>>
 *      es un fichero de texto que guarda tarjetas de credito generadas o validadas a razon
 *      de una por linea
 * Post: Si la apertura del fichero <<nombreFichero>> se ha realizado correctamente ha almacenado
 *       la tarjeta de credito <<tarjeta>> al final del fichero en una nueva linea. En caso contrario
 *       ha informado por pantalla del problema de acceso al fichero
 */
void escribirEnFichero(const string& tarjeta, const char nombreFichero[]){
    // apertura del fichero para realizar escritura
    ofstream f;
    // flujo en modo append para poder escribir en la ultima linea
    f.open(nombreFichero, ios::app);

    if (f.is_open()){
        // si el fichero se ha abierto correctamente
        // escritura de la nueva tarjeta en el fichero correspondiente
        f << tarjeta << endl;
        // cierre del flujo de lectura asociado al fichero
        f.close();
    }
    else {
        // el fichero no se ha abierto correctamente y mada error
        cerr << "El fichero " << nombreFichero << " es innacesible " << endl;
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
void ejecutarOrden(const int& orden, const char ficheroGeneradas[],
                    const char ficheroValidas[], const char ficheroInvalidas[]){

    // evaluacion del tipo de orden
    if (orden == 1){
        // la orden es generar una tarjeta de credito
        string tarjeta;
        tarjeta = generarTarjeta();

        // cambio de color a blanco
        textcolor(COLOR_BLANCO);
        cout << endl << endl;
        // mostrar por pantalla la nueva tarjeta de credito
        cout << "Se ha generado la nueva tarjeta de credito ";
        mostrarTarjetaCredito(tarjeta);

        // escribir la nueva informacion en el fichero de tarjetas generadas
        escribirEnFichero(tarjeta, ficheroGeneradas);
        cout << endl << endl << endl;
    }
    else if (orden == 2){
        // la orden pulsada es 2
        // limpieza de la pantalla
        clrscr();
        // la orden es validar una tarjeta de credito
        string tarjeta;
        // muestreo de la cuadricula de validacion
        dibujarCuadricula();
        // peticion al usuario de introducir la tarjeta de credito
        introducirTarjetaCredito(tarjeta);
        // comprobacion de si la tarjeta de credito es valida o no
        if (esTarjetaValida(tarjeta)){
            // es valida
            // cambiar fuente a verde
            textcolor(COLOR_VERDE);
            cout << "La tarjeta de credito " << tarjeta << " es valida" << endl << endl << endl;
             // escribir la nueva informacion en el fichero de tarjetas validas
            escribirEnFichero(tarjeta, ficheroValidas);
        }
        else {
            // no es valida
            // cambiar fuente a rojo
            textcolor(COLOR_ROJO);
            cout << "La tarjeta de credito " << tarjeta << " no es una tarjeta valida" << endl << endl << endl;
            // escribir la nueva informacion en el fichero de tarjetas invalidas
            escribirEnFichero(tarjeta, ficheroInvalidas);
        }
    }
    else {
        // la orden pulsada es la 3
        // borrar contenido de todos los ficheros e historial
        remove(ficheroGeneradas);
        remove(ficheroInvalidas);
        remove(ficheroValidas);
        cout << "Los ficheros de datos e historial se han borrado correctamente" << endl << endl << endl;
    }
    // cambiar fuente a amarillo
    textcolor(COLOR_AMARILLO);
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


    // Construir arbol de tarjetas generadas a partir de las tarjetas ya generadas
    generarArbol(arbolTarGeneradas, fichTarjetasGeneradas);

     // Construir arbol de tarjetas validas a partir de las tarjetas validas
    generarArbol(arbolTarValidas, fichTarjetasValidas);

     // Construir arbol de tarjetas invalidas a partir de las tarjetas invalidas
    generarArbol(arbolTarInvalidas, fichTarjetasInvalidas);


    // Limpieza de pantalla
    clrscr();

    // presentacion del menu de opciones al usuario por pantalla
    presentarMenu();

    // peticion de orden al usuario
    pedirOrden(orden);

    while (orden != 0){
        // orden de ejecucion valida

        // ejecucion de la orden del usuario con los icheros donde se va a almacenar
        ejecutarOrden(orden, fichTarjetasGeneradas, fichTarjetasValidas , fichTarjetasInvalidas);

        // limpieza de la pantalla
        clrscr();

        // vuelve a presentar el menu
        presentarMenu();

        // volver a pedir una nueva tarea al usuario
        pedirOrden(orden);
    }


    // Borrar contenido del arbol binarios de tarjetas generadas
    borrar(arbolTarGeneradas);

    // Borrar contenido del arbol binarios de tarjetas validas
    borrar(arbolTarValidas);

    // Borrar contenido del arbol binarios de tarjetas invalidas
    borrar(arbolTarInvalidas);




    // Fin de la ejecucion del programa
    return 0;
}
