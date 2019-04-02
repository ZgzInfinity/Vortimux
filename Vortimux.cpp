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
#include "graficos.h"
#include "tarjetaCredito.h"


const int LIMITE_MINIMO = 0;
const int LIMITE_MAXIMO = 2;



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
void ejecutarOrden(const int& orden){
    if (orden == 1){
        // la orden es generar una tarjeta de credito
        string tarjeta;
        tarjeta = generarTarjeta();
        // mostrar por pantalla la nueva tarjeta de credito
        cout << "Se ha generado la nueva tarjeta de credito ";
        mostrarTarjetaCredito(tarjeta);
        cout << endl;
    }
    else if (orden == 2) {
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
            cout << "La tarjeta de credito " << tarjeta << " es valida" << endl;
        }
        else {
            // no es valida
            cout << "La tarjeta de credito " << tarjeta << " no es una tarjeta valida" << endl;
        }
    }
    else {
        // la orden es finalizar la ejecucion del programa
        cout << "Ejecucion finalizada" << endl;
    }
}




int main (){

    // variable para almacenar las ordenes del usuario
    int orden;

    // Limpieza de pantalla
    clrscr();

    // presentacion del menu de opciones al usuario por pantalla
    presentarMenu();

    // peticion de orden al usuario
    pedirOrden(orden);

    while (orden != 0){
        // orden de ejecucion valida

        // ejecucion de la orden del usuario
        ejecutarOrden(orden);

        // volver a pedir una nueva tarea al usuario
        pedirOrden(orden);
    }

    // Fin de la ejecucion del programa
    return 0;
}
