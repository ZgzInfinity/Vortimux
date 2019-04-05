/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 2-4-19 --------------------
 * ----------------------------------
 */


 /*
  * Fichero de implementacion del modulo graficos
 */


#include "graficos.h"


using namespace std;



/*
 * Pre: ---
 * Post: Ha presentado por pantalla el menu de opciones
 *       disponibles para el usuario
 */
void presentarMenu(){
    // Posicionamiento en esquina supeior izquierda
    // Muestreo de las opciones por pantalla
    gotoxy(0, 0);
    cout << endl;
    cout << "MENU DE OPERACIONES DE VORTIMUX" << endl;
    cout << "===============================" << endl;
    cout << "0 - Finalizar" << endl;
    cout << "1 - Generar tarjeta de credito" << endl;
    cout << "2 - Validar tarjeta de credito" << endl;
    cout << "3 - Borrar ficheros de almacenamiento" << endl;
}


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
void dibujarCuadricula(){

    // Variables de referencia para dibujar cuadricula
    int refColIzq = 5;
    int refColDer = 80;
    int refFilSup = 4;
    int refFilInf = 11;
    int refFilMed = 7;


    // Recorrido de pantalla en horizontal
    for (int i = refColIzq; i <= refColDer; i++){
        // Recorrrido de pantalla en vertical
        for (int j = refFilSup; j <= refFilInf; j++){
            // tratamiento fila superior
            if (j == refFilSup){
                // escribir triangulo hacia abajo
                if(i % ESPACIADO == 0){
                    // escrbir triangulo lateral superior
                    gotoxy(i, j);
                    printf("%c", TRI_LAT_SUP);
                }
                else {
                    // escribir raya horizontal
                    gotoxy(i, j);
                    printf("%c", LINEA_HORIZONTAL);
                }
            }
            // tratamiento fila inferior
            else if (j == refFilMed){
                // escribir triangulo hacia arriba
                if(i % ESPACIADO == 0){
                    gotoxy(i, j);
                    if (i == refColIzq){
                        // escribir triangulo lateral izquierdo
                        printf("%c", TRI_LAT_IZQ);
                    }
                    else if (i == refColDer){
                        // escribir triangulo lateral derecho
                        printf("%c", TRI_LAT_DER);
                    }
                    else {
                        // escribir interseccion
                        printf("%c", CRUZ);
                    }
                }
                else{
                    // escribir raya horizontal
                    gotoxy(i, j);
                    printf("%c", LINEA_HORIZONTAL);
                }
            }
            else if (j == refFilInf){
                // escribir triangulo hacia arriba
                if(i % ESPACIADO == 0){
                    gotoxy(i, j);
                    printf("%c", TRI_LAT_INF);
                }
                else{
                    // escribir raya horizontal
                    gotoxy(i, j);
                    printf("%c", LINEA_HORIZONTAL);
                }
            }
            // tratamiento espacio intermedio de cuadricula
            else {
                if (i % ESPACIADO == 0){
                    // escribe raya vertical
                    gotoxy(i, j);
                    printf("%c", LINEA_VERTICAL);
                }
            }
        }
    }


    // Dibujo esquina superior izquierda
    gotoxy(refColIzq, refFilSup);
    printf("%c", ESQUINA_SUP_IZQ);
    // Dibujo esquina superior derecha
    gotoxy(refColDer, refFilSup);
    printf("%c", ESQUINA_SUP_DER);
    // Dibujo esquina triangulo lateral izquierdo
    gotoxy(refColIzq, refFilMed);
    printf("%c", TRI_LAT_IZQ);
    // Dibujo esquina superior izquierda
    gotoxy(refColDer, refFilInf);
    printf("%c", ESQUINA_INF_DER);
    // Dibuja esquina inferior derecha
    gotoxy(refColIzq, refFilInf);
    printf("%c", ESQUINA_INF_IZQ);

    // posicion de referencia
    int pos = 1;

    // escritura de la informacion a pedir
    for (int i = refColIzq + 1; i < refColDer; i++){
        // escribir Ci en cuadricula
        if (i % ESPACIADO == 2){
            // crear valor de cadena e impresion del valor
            gotoxy(i, refFilSup + 2);
            cout << pos;
            pos++;
        }
    }

}



