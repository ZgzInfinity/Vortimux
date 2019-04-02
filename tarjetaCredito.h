/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 1-4-19 --------------------
 * ----------------------------------
 */

#ifndef TARJETACREDITO_H
#define TARJETACREDITO_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "operaciones.h"

/*
 * Fichero de implemetacion del modulo Tarjeta credito
 */

using namespace std;

// constantes del modulo
const int BASE = 10;
const int MAX_DIGITOS_TARJETA = 16;

/*
 * Pre: <<tarjeta>> es una cadena de caracteres que identifica una
 *       posible tarjeta de credito autentica
 * Post: Ha devuelto <<true>> si y solo si la tarjeta de credito <<tarjeta>> es
 *       una tarjeta de credito valida. En caso contrario ha devuelto <<false>>
 */
bool esTarjetaValida(string tarjeta);


/*
 * Pre: ---
 * Post: Ha devuelto una tarjeta de credito valida
 */
string generarTarjeta();

/*
 * Pre: ----
 * Post: Ha guardadado en <<tarjeta>> una secuencia de MAX_DIGITOS_TARJETA
 *       caracteres para crear una tarjeta de credito
 */
void introducirTarjetaCredito(string& tarjeta);


/*
 * Pre: <<tarjeta>> es una secuencia de caracteres que conforma una
 *      tarjeta de credito
 * Post: Ha mostrado por pantalla la tarjeta de credito <<tarjeta>>
 */
void mostrarTarjetaCredito(string tarjeta);

#endif
