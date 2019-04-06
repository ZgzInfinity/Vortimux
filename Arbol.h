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
#include <cstring>
#include <fstream>


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
        friend bool insertarRec(Arbol::Nodo* & entrada, const string& tarjeta);


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
        friend bool insertar(Arbol& a, const string& tarjeta);



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



        /*
         * Pre: <<a>> es un arbol bianrio de busqueda de tarjetas de credito vacio y <<nombreFichero>> es un
         *      fichero de texto que almacena tarjetas de credito a razon de una por linea
         * Post: Ha almacenado en el arbol bianrio de busqueda <<a>> todas las tarjetas de credito recogidas en
         *       el fichero de texto <<nombreFichero>>
         */
        friend void generarArbol(Arbol& a, const char nombreFichero[]);



        /*
         * Pre: <<entrada>> es un puntero a un nodo de un arbol binario de busqueda que
         *      almacena tarjetas de credito y <<f>> es un flujo de escritura asociado a un
         *      fichero de texto de tarjetas de credito
         * Post: Ha almacenado en el fichero <<nombreFichero>> las tarjetas de credito recogidas en
         *       el arbol binario <<a>> a razon de una por linea
         */
        friend void generarFicheroRec(Arbol::Nodo* & entrada, ofstream& f);


        /*
         * Pre: <<a>> es un arbol binario de busqueda que almacena tarjetas de credito
         * Post: Ha almacenado en el fichero de texto <<nombreFichero>> las tarjetas de credito
         *       recogidas en el arbol <<a>> ordenadas por orden numerico descendente a razon de una
         *       tarjeta de credito por linea
         */
        friend void generarFichero(Arbol& a, const char nombreFichero[]);

};


# endif
