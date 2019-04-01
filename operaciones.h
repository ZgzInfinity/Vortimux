/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 1-4-19 --------------------
 * ----------------------------------
 */

#ifndef OPERACIONES_H
#define OPERACIONES_H

/*
 * Fichero de interfaz del modulo operaciones para trabajar con enteros
 */
 

/*
 * Pre: <<n>> es un nunero entero mayor o igual que cero
 * Post: Ha devuelto la cifra de las unidades del numero <<n>>
 */
int cifraDeUnidades(int n);


/*
 * Pre: <<n>> es un nunero entero mayor o igual que cero
 * Post: Ha devuelto el numero resultante de haber eliminado de <<n>> la
 *       cifra de las unidades
 */
int numeroSinUnidades(int n);



/*
 * Pre: <<n>> es un numero positivo
 * Post: Ha devuelto la suma de las cifras del numero <<n>>
 */
int sumarCifras(int n);

#endif