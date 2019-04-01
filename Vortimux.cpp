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
#include "tarjetaCredito.h"

/*
 * Fichero de implemetacion del modulo Tarjeta credito
 */

using namespace std;


int main (){
	
	srand(time(NULL));
	
	string t;
    t = generarTarjeta();
	
	if (esTarjetaValida(t)){
		cout << " Tarjeta valida " << endl;
	}
	else{
		cout << " Tarjeta invalida " << endl;
	}
	
	string t2;
	
	introducirTarjetaCredito(t2);
	
	cout << t2 << endl;
	
	mostrarTarjetaCredito(t2);
	
    return 0;
}
