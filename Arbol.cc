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
    // booleano de control de insercion
	bool correcto;
	if (entrada == nullptr){
        // el arbol es vacio se reserva memoria
        // se introducen los datos de la nueva tarjeta
        entrada = new Arbol::Nodo;
		entrada->clave = clave;
		entrada->tarjeta = tarjeta;
		entrada->der = nullptr;
		entrada->izq = nullptr;
		correcto = true;
	}
	// el arbol no es vacio y tiene al menos una tarjeta
	else if (entrada->clave == clave){
        // la tarjeta ya existe y se devuelve error
		correcto = false;
	}
	else{
	    // la tarjeta no existe con esa clave
		if(clave <= entrada->clave){
		    // buscar en el arbol izquierdo si la clave es menor o igual que la raiz
			correcto = insertarRec(entrada->izq, clave , tarjeta);
		}
		else{
		    // buscar en el arbol derecho si la clave es mayor que la raiz
			correcto = insertarRec(entrada->der, clave, tarjeta);
		}
	}
	// retorno del resultado
	return correcto;
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



/*
 * Pre: <<entrada>> es un puntero a un nodo de un arbol que almacena tarjetas de credito
 * Post: Ha borrado todos los nodos de los subarboles izquierdos y derechos del nodo <<entrada>>,
 *       incluido el mismo
 */
void borrarRec(Arbol::Nodo* & entrada){
      // comprobacion de si el nodo es hoja o no
      if (entrada != nullptr){
          // el nodo no es nulo
          if (entrada->izq != nullptr){
                // comprobar y borrar el hijo izquierdo si existe
                borrarRec(entrada->izq);
          }
          if (entrada->der != nullptr){
                // comprobar y borrar el hijo derecho si existe
                borrarRec(entrada->der);
          }
          else {
               // el nodo es hoja y se procede a borrar
               delete entrada;
          }
      }
}




/*
 * Pre: <<a>> es un arbol binario de busqueda binaria que almacena tarjetas de credito
 * Post: Ha eliminado todas las tarjetas de credito.
 */
void borrar(Arbol& a){
    // eliminacion del arbol de tarjetas de credito
    borrarRec(a.raiz);
    // eliminacion del nodo raiz
    delete a.raiz;
}




/*
 * Pre: <<a>> es un arbol bianrio de busqueda de tarjetas de credito vacio y <<nombreFichero>> es un
 *      fichero de texto que almacena tarjetas de credito a razon de una por linea
 * Post: Ha almacenado en el arbol bianrio de busqueda <<a>> todas las tarjetas de credito recogidas en
 *       el fichero de texto <<nombreFichero>>
 */
void generarArbol(Arbol& a, const char nombreFichero[]){
    // flujo de lectura asociado al fichero
    ifstream f;
    f.open(nombreFichero);
    if (f.is_open()){
        // generador autoincremental de claves
        bool error = false;
        int i = 1;
        string tarjetaLeida;
        // lectura de la primera tarjeta
        f >> tarjetaLeida;
        while (!error && !f.eof()){
            // insertar en el arbol la nueva tarjeta leida
            if (insertar(a, i, tarjetaLeida)){
                // se ha podido insertar la tarjeta correctamente porque no existe
                i++;
                // lectura de la siguiente tarjeta del fichero
                f >> tarjetaLeida;
            }
            else {
                // se ha producido un error en la insercion de la tarjeta
                cerr << "Se ha producido un error al insertar la tarjeta " << tarjetaLeida << endl;
                error = true;
            }
        }
    }
    else{
        cerr << "El fichero " << nombreFichero << " es innacesible" << endl;
    }
}




