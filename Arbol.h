/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 4-4-19 --------------------
 * ----------------------------------
 */


/*
 * Fichero de interfaz del modulo arbpl para guardar tarjetas de credito
 */


#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>

using namespace std;


struct Arbol {

    private:
        // estructura interna del arbol
        struct Nodo {
            // estructura interna del tipo de dato Nodo
            // para almacenar tarjetas de credito
            int clave;          // identificador de la tarjeta
            string tarjeta;     // codigo de la tarjeta
            Nodo* der;         // puntero al arbol derecho
            Nodo* izq;         // puntero al arbol izquierdo


        };

        Nodo* raiz;             // puntero a la raiz del arbol
        int numTarjetas;        // numero de tarjetas del arbol

    public:


        /*
         * Pre: ---
         * Post: Ha devuelto un arbol vacio
         */
        friend void crearArbol(Arbol& a);



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
        friend bool insertarRec(Arbol::Nodo* & entrada, const int& clave, const string& tarjeta);


        /*
         * Pre: <<a>> es un arbol binario de busqueda que almacena tarjetas de credito
         *      identificadas por medio de tuplas <clave, valor> donde es el identificador
         *      de una tarjeta de credito y valor hace referencia al codigo de la propia tarjeta.
         *      <<clave>> es el identificador de la tarjeta que sea desea insertar en el arbol y <<tarjeta>>
         *      es el codigo de la tarjeta a insertar
         * Post: Ha devuelto el arbol resultante de insertar la nueva tarjeta de credito con su clave y codigo en el
         *       arbol <<a>>. Si todo ha ido bien ha almacenado en <<estado>> el valor 0 y si la insercion ha ido mal
         *       ha guardado el valor 1
         */
        friend bool insertar(Arbol& a, const int& clave, const string& tarjeta);



        /*
         * Pre: <<entrada>> es un puntero a un nodo de un arbol que almacena tarjetas de credito
         * Post: Ha borrado todos los nodos de los subarboles izquierdos y derechos del nodo <<entrada>>,
         *       incluido el mismo
         */
        friend void borrarRec(Arbol::Nodo* & entrada);



        /*
         * Pre: <<a>> es un arbol binario de busqueda binaria que almacena tarjetas de credito
         * Post: Ha eliminado todas las tarjetas de credito y ha devuelto <<true>> si el borrado se ha
         *       efectuado de forma correcta. En caso contrario ha devuelto <<false>>
         */
        friend void borrar(Arbol& a);


};


# endif
