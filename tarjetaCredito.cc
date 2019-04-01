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
#include "operaciones.h"
#include "tarjetaCredito.h"


/*
 * Fichero de implemetacion del modulo Tarjeta credito
 */

using namespace std;


/*
 * Pre: <<tarjeta>> es una cadena de caracteres que identifica una 
 *       posible tarjeta de credito autentica
 * Post: Ha devuelto <<true>> si y solo si la tarjeta de credito <<tarjeta>> es
 *       una tarjeta de credito valida. En caso contrario ha devuelto <<false>>
 */
bool esTarjetaValida(string tarjeta){
    int digito;
	int numero = 0; 
	int valor = 0;
	
	// longitud de la cadena
    int longitud = tarjeta.size();

	// bucle de recorrido de la cadena
    for (int i = 0; i <= longitud - 2; i++){
		// obtencion del caracter iésima
        digito = tarjeta.at(i) - '0';
		// si la posicion es par
        if (i % 2 == 0){
			// multiplicar por dos el valor
            valor = 2 * digito;
			// comprobar que el numero tiene el mas de una cifras
			if (valor >= BASE){
				// retorno de la suma de las cifras
				valor = sumarCifras(valor);
			}
			// incrementar el valor
			numero += valor;
        }
        else{
            numero += digito;
        }
    }
	// obtencion de la cifra menos significativa
    digito = cifraDeUnidades(numero);
	// numero sin cifra de las unidades
	return BASE - digito == tarjeta.at(longitud - 1) - '0'; 
}


/*
 * Pre: ---
 * Post: Ha devuelto una tarjeta de credito valida 
 */
string generarTarjeta(){
	// tarjeta de credito a generar
	string tarjeta = "";
	
	// variables auxiliares
	char digito;
	int numero = 0;
	int cifra;
	int valor;
	
	for (int i = 0; i <= MAX_DIGITOS_TARJETA - 2; i++){
		// generacion aleatoria de un caracter entre 0 y 9
		digito = '0' + rand() % (('9' - '0') + 1);
		// obtencion del valor equivalente entero
		cifra = digito - '0';
		// concatenacion del digito a la tarjeta
		tarjeta += digito;
		if (i % 2 == 0){
			// multiplicar por dos el valor
			valor = 2 * cifra;
			// comprobar que el numero tiene el mas de una cifras
			if (valor >= BASE){
				// retorno de la suma de las cifras
				valor = sumarCifras(valor);
			}
			// incrementar el valor
			numero += valor;
		}
		else{
			numero += cifra;
		}
	}
	// obtencion de la cifra menos significativa
    cifra = cifraDeUnidades(numero);
	// concatenar el ultimo digito resultante para hacer la tarjeta valida
	if (cifra != 0){
		tarjeta += (BASE - cifra) + '0';
	}
	else{
		tarjeta += '0';
	}
	// retorno de la tarjeta de credito
	return tarjeta;
}


/*
 * Pre: ----
 * Post: Ha guardadado en <<tarjeta>> una secuencia de MAX_DIGITOS_TARJETA
 *       caracteres para crear una tarjeta de credito
 */
void introducirTarjetaCredito(string& tarjeta){
	char c;
	// peticion de la tarjeta de credito al usuario por teclado
	cout << "Introduzca una tarjeta de credito: " << flush;
	for (int i = 0; i < MAX_DIGITOS_TARJETA; i++){
		// introducir caracter
		cin >> c;
		// concatenacion del caracter a la tarjeta de credito
		tarjeta += c;
	}
}


/*
 * Pre: <<tarjeta>> es una secuencia de caracteres que conforma una
 *      tarjeta de credito
 * Post: Ha mostrado por pantalla la tarjeta de credito <<tarjeta>>
 */
void mostrarTarjetaCredito(string tarjeta){
	// longitud total de la cadena
	int total = tarjeta.size();
	// recorrido de la cadena de caracteres
	for (int i = 0; i < total; i++){
		if (i % 4 == 0 && i != 0){
			// separacion de los caracteres en grupos de 4
			cout << "-";
		}
		// mostrar caracter iésimo de la tarjeta
		cout << tarjeta.at(i);
	}
}