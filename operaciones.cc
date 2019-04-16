/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 2-4-19 --------------------
 * ----------------------------------
 */

/*
 * Fichero de implementacion del modulo operaciones para trabajar con enteros
 */


#include "operaciones.h"


/*
 * Pre: <<n>> es un nunero entero mayor o igual que cero
 * Post: Ha devuelto la cifra de las unidades del numero <<n>>
 */
int cifraDeUnidades(int n){
	return n % 10;
}



/*
 * Pre: <<n>> es un nunero entero mayor o igual que cero
 * Post: Ha devuelto el numero resultante de haber eliminado de <<n>> la
 *       cifra de las unidades
 */
int numeroSinUnidades(int n){
	return n / 10;
}



/*
 * Pre: <<n>> es un numero positivo
 * Post: Ha devuelto la suma de las cifras del numero <<n>>
 */
int sumarCifras(int n){
	// variables auxiliares
	int numero = 0;
	int cifra;
	while (n != 0){
		// obtencion de la cifra menos significativa
		cifra = cifraDeUnidades(n);
		// actualizacion del numero
		n = numeroSinUnidades(n);
		// incremento del numero con la cifra
		// menos significativa
		numero += cifra;
	}
	// retorno del valor
	return numero;
}
