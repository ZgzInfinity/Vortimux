/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 2-4-19 --------------------
 * ----------------------------------
 */


/*
 * Fichero de interfaz del modulo graficos
 */

#ifndef GRAFICOS_H
#define GRAFICOS_H


#include <iostream>
#include <conio.h>
#include <unistd.h>

using namespace std;

const int ESPACIADO = 4;
const int ESQUINA_SUP_IZQ = 218;
const int ESQUINA_SUP_DER = 191;
const int ESQUINA_INF_IZQ = 192;
const int ESQUINA_INF_DER = 217;
const int LINEA_HORIZONTAL = 196;
const int LINEA_VERTICAL = 179;
const int TRI_LAT_IZQ = 195;
const int TRI_LAT_INF = 193;
const int TRI_LAT_SUP = 194;
const int TRI_LAT_DER = 180;
const int CRUZ = 197;


// Retardo del bucle de carga
const int RETARDO = 20000;
const int TECLA_ENTER = 13;

/*
 * Pre: ---
 * Post: Ha mostrado por pantalla el nombre del generador y
 *       validador de tarjetas de credito
 */
void introduccion();


/*
 * Pre: ---
 * Post: Ha presentado por pantalla el menu de opciones
 *       disponibles para el usuario
 */
void presentarMenu();



/*
 * Pre: ---
 * Post: Ha mostrado por pantalla el mensaje "CARGANDO" seguido de una
 *       secuencia de puntos
 */
void cargando();



/*
 * Pre: ---
 * Post: Ha escrito por pantalla una cuadricula con el siguiente formato de
 *       estilo mostrado a continuacion:
 *
 * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
 * │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
 * │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │ 10 │ 11 │ 12 │ 13 │ 14 │ 15 │
 * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
 * │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
 * │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
 * │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
 * └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
 *
 * Cada uno de los digitos de la tabla indica el caracter de la tarjeta de credito que
 * se va a validar
 */
void dibujarCuadricula();

#endif
