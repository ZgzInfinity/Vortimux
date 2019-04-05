/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 4-4-19 --------------------
 * ----------------------------------
 */


 /*
 * Fichero de implementacion del modulo arbpl para guardar tarjetas de credito
 */


#include "Arbol.h"



/*
 * Pre: ---
 * Post: Ha devuelto un arbol vacio
 */
void crearArbol(Arbol& a){
    a.raiz = nullptr;
}



/*
 * Pre: funcion con debilitamiento de precondicion en la que <<entrada>> es un puntero a un
 *      nodo de un arbol de tarjetas de credito, <<clave>> es el identificador de la nueva
 *      tarjeta de credito a insertar en el nodo <<entrada>> y <<tarjeta>> es el codigo numerico
 *      de la nueva tarjeta de credito a introducir
 * Post: Ha almacenado en el nodo del arbol <<entrada>> o en algunos de los nodos de sus  subarboles
 *       izquierdo o derecho la tarjeta de credito con ientificador <<clave>> y con codigo <<codigo>>.
 *       Si no existia nniguna tarjeta con la clave <<clave la insercion ha ido bien y ha devuelto <<true>>,
 *       pero en caso contario ha devuelto <<false>>
 */
bool insertarRec(Arbol::Nodo* & entrada, const int& clave, const string& tarjeta){
    // error de insercion
	bool error;
	if (entrada == nullptr){
        // el arbol es vacio se reserva memoria
        // se introducen los datos de la nueva tarjeta
        entrada = new Arbol::Nodo;
		entrada->clave = clave;
		entrada->tarjeta = tarjeta;
		entrada->der = nullptr;
		entrada->izq = nullptr;
		error = 0;
	}
	// el arbol no es vacio y tiene al menos una tarjeta
	else if (entrada->clave == clave){
        // la tarjeta ya existe y se devuelve error
		error = 1;
	}
	else{
	    // la tarjeta no existe con esa clave
		if(clave <= entrada->clave){
		    // buscar en el arbol izquierdo si la clave es menor o igual que la raiz
			error = insertarRec(entrada->izq, clave , tarjeta);
		}
		else{
		    // buscar en el arbol derecho si la clave es mayor que la raiz
			error = insertarRec(entrada->der, clave, tarjeta);
		}
	}
	// retorno del resultado
	return error;
}



/*
 * Pre: <<a>> es un arbol binario de busqueda que almacena tarjetas de credito
 *      identificadas por medio de tuplas <clave, valor> donde es el identificador
 *      de una tarjeta de credito y valor hace referencia al codigo de la propia tarjeta.
 *      <<clave>> es el identificador de la tarjeta que sea desea insertar en el arbol y <<tarjeta>>
 *      es el codigo de la tarjeta a insertar
 * Post: Ha devuelto el arbol resultante de insertar la nueva tarjeta de credito con su clave y codigo en el
 *       arbol <<a>>. Si no existia nniguna tarjeta con la clave <<clave la insercion ha ido bien y ha devuelto <<true>>,
 *       pero en caso contario ha devuelto <<false>>
 */
bool insertar(Arbol& a, const int& clave, const string& tarjeta){
	bool control;
	control = insertarRec(a.raiz, clave, tarjeta);
	return control;
}




