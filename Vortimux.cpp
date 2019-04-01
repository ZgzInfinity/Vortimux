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




int main (){

    // variable para almacenar las ordenes del usuario
    int orden;

    // Limpieza de pantalla
    clrscr();

    // presentacion del menu de opciones al usuario por pantalla
    presentarMenu();

    // peticion de orden al usuario
    pedirOrden(orden);

    return 0;
}
