/*
 * ----------------------------------
 * Autor: Ruben Rodriguez Esteban ---
 * Fecha: 1-4-19 --------------------
 * ----------------------------------
 */


#include "operaciones.h"
#include "tarjetaCredito.h"


/*
 * Fichero de implemetacion del modulo Tarjeta credito
 */

using namespace std;


const int ANCHO = 4;


/*
 * Pre: <<tarjeta>> es una cadena de caracteres que identifica una
 *       posible tarjeta de credito autentica
 * Post: Ha devuelto <<true>> si y solo si la tarjeta de credito <<tarjeta>> es
 *       una tarjeta de credito valida. En caso contrario ha devuelto <<false>>
 */
bool esTarjetaValida(string tarjeta){
   int numero = 0;
   int valor, cifra;
   int desp = 0;
   int dim = tarjeta.size();

   if (dim % 2 != 0){
	   desp = 1;
   }

   for (int i = tarjeta.length() - 1; i >= 0; i--){
        cifra = tarjeta.at(i) - '0';
        if ( (i + desp) % 2 == 0){
            valor = 2 * cifra;

            if (valor >= BASE){
                valor = sumarCifras(valor);
            }
            // incrementar el valor
			numero += valor;
		}
		else{
			numero += cifra;
		}
    }
	cout << numero << endl;
    return numero % BASE == 0;
}



/*
 * Pre: <<codTarjeta>> es el codigo de una tarjeta
 * Post: Ha devuelto una tarjeta de credito valida de acuerdo
 *       con el codigo de tarjeta <<codTarjeta>>
 */
string generarTarjeta(int codTarjeta){

    // generar semilla de numeros aleatorios
	srand(time(NULL));

    // tarjeta de credito a generar
    string tarjeta;
    int indice;
    int numero = 0;
	int desp = 0;
    int codInicio, valor;
    int total, cifra;
    char digito;

    switch(codTarjeta){
        case 1:
                // tarjetas American Express
                total = MAX_DIGITOS_TARJETA - 1;
                codInicio = rand() % 2;
                if (codInicio == 0){
					// tarjeta empieza por 34
                    tarjeta = "34";
                }
                else {
					// tarjeta empieza por 37
                    tarjeta = "37";
                }
                break;
        case 2:
                // tarjetas Diners Club
                codInicio = rand() % 6;
                if (codInicio == 0){
                    // tarjetas empiezan por 36
                    // Total digitos entre 14 y 19
                    total = rand() % 6 + 14;
					// asignacion de los caracteres por defecto a la tarjeta
                    tarjeta = "36";
                }
                else if (codInicio == 1){
                    // tarjetas empiezan entre 300 y 305
                    // Total digitos entre 16 y 19
                    total = rand() % 4 + MAX_DIGITOS_TARJETA;
                    codInicio = rand() % 6 + 300;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                else if (codInicio == 2){
                    // tarjetas empiezan en 3095
                    // Total digitos entre 16 y 19
                    total = rand() % 4 + MAX_DIGITOS_TARJETA;
					// asignacion de los caracteres por defecto a la tarjeta
                    tarjeta = "3095";
                }
                else if (codInicio == 3){
                    // Tarjetas empiezan por 38 y 39
                    // Total digitos entre 16 y 19
                    total = rand() % 4 + MAX_DIGITOS_TARJETA;
                    codInicio = rand() % 2 + 38;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);

                }
                else {
                    // Tarjetas empiezan por 54 y 55 en EEUU y Canada
                    // Total de digitos 16
                    total = MAX_DIGITOS_TARJETA;
                    codInicio = rand() % 2 + 54;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                break;
        case 3:
                // Tarjetas Discover
                // Total digitos entre 16 y 19
                total = rand() % 4 + MAX_DIGITOS_TARJETA;
                codInicio = rand() % 4;
                if (codInicio == 0){
                    // Tarjeta empieza por 6011
                    tarjeta = "6011";
                }
                else if (codInicio == 1){
                    // Tarjetas empiezan por rango entre 622126 y 622925
                    codInicio = rand() % 800 + 622126;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                else if (codInicio == 2){
                    // Tarjetas empiezan por rango entre 624000 y 626999
                    codInicio = rand() % 3000 + 624000;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                else if (codInicio == 3){
                    // Tarjetas empiezan por rango entre 628200 y 628899
                    codInicio = rand() %  700 + 628200;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                else {
                    // Tarjetas empiezan por 64 o 65
                    codInicio = rand() % 2 + 64;
					tarjeta = to_string(codInicio);
                }
                break;
        case 4:
                // Tarjetas JCB empiezan por rango entre 3528 y 3589
                // Total digitos entre 16 y 19
                total = rand() % 4 + MAX_DIGITOS_TARJETA;
                codInicio = rand() % 62 + 3528;
				// asignacion de los caracteres por defecto a la tarjeta
				tarjeta = to_string(codInicio);
                break;
        case 5:
                // Tarjetas Master Card
                // Total digitos entre 16 y 19
                total = MAX_DIGITOS_TARJETA;
                codInicio = rand() % 2;
                if (codInicio == 0){
                    // tarjetas empiezan por rango entre 2221 y 2620
                    codInicio = rand() % 500 + 2221;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                else {
                    // tarjetas empiezan por rango entre 51 y 55
                    codInicio = rand() % 5 + 51;
					// asignacion de los caracteres por defecto a la tarjeta
					tarjeta = to_string(codInicio);
                }
                break;
        case 6:
                // Tarjetas Visa
                // tarjetas empiezan por 4
                // Total digitos de 16
                total = MAX_DIGITOS_TARJETA;
                tarjeta = "4";
                break;
        default: cerr << " El codigo de la tarjeta es desconocido " << endl;
    }

    // calculo del total de caracteres rellenados segun el modelo de la tarjeta
    indice = tarjeta.length();

	if (total % 2 != 0){
		desp = 1;
	}

    // Iterador para rellenar los caracteres sobrantes
    for (int i = 0; i <= total - 2; i++){
        if (i >= indice){
            // Nuevo digito aleatorio de la tarjeta
            digito = '0' + rand() % (('9' - '0') + 1);

            cifra = digito - '0';

            // Incorporacion del digito a la tarjeta
            tarjeta += digito;
        }
        else {
            // Es uno de los digitos de reconocimiento ya introducidos
            cifra = tarjeta.at(i) - '0';
        }
        if ((i + desp) % 2 == 0){
            valor = 2 * cifra;

            if (valor >= BASE){
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

	numero += tarjeta.at(total - 1) - '0';
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
	// posicionamiento para evitar borrado de tabla
    // gotoxy(5, 2);
	// peticion de la tarjeta de credito al usuario por teclado
	cout << "Introduzca una tarjeta de credito: ";
	for (int i = 0; i < MAX_DIGITOS_TARJETA; i++){
	    // posicionamiento en el lugar correspondiente
        // gotoxy(6 + ANCHO * i, 9);
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
		// mostrar caracter iésimo de la tarjeta
		cout << tarjeta.at(i);
	}
}


/*
 * Pre: <<fichero>> es un fichero de texto que alamcena a razon de una por linea
 *      una secuencia de tarjetas de credito
 * Post: Ha escrito en pantalla un listado con todas las tarjetas de credito almacenadas
 *       en el fichero <<fichero>> de acuerdo con el formato que se muestra en el
 *       siguiente ejemplo
 *
 *       LISTADO DE TARJETAS DE CREDITO
 *
 *       Posicion              Tarjeta     Resultado
 *      ---------     ----------------   -----------
 *              1     1066654591158236        valida
 *              2     1527614232216853        valida
 *              3     1740948824551710      invalida
 *              4     4113874277931980      invalida
 *              5     4575826696910186        valida
 *              6     7618927954312339        valida
 *              7     7974791042538695        valida
 */
void analizarTarjetasFichero(const char fichero[]){
    // flujo de lectura asociado al fichero de tarjetas
    ifstream f;
    // apertura del fichero
    f.open(fichero);
    if (f.is_open()){
        // Escritura de la cabecera
        cout << endl;
        cout << "  LISTADO DE TARJETAS DE CREDITO " << endl;
        cout << endl;
        cout << "  Posicion              Tarjeta     Resultado " << endl;
        cout << " ---------     ----------------   -----------" << endl;

        // Comenzar lectura del fichero de tarjetas
        int i = 1;
        string tarjeta;
        // lectura de tarjeta
        f >> tarjeta;
        while (!f.eof()){
            // Comprobacion de si la tarjeta es valida
            if (esTarjetaValida(tarjeta)){
               // Es valida
               cout << setw(10)  << i << " "
                    << setw(20) << tarjeta << " "
                    << setw(14) << "valida " << endl;
            }
            else {
               // Es invalida
               cout << setw(10)  << i << " "
                    << setw(20) << tarjeta << " "
                    << setw(14) << "invalida " << endl;
            }
            // Lectura de una nueva tarjeta
            i++;
            f >> tarjeta;
        }
        cout << endl << endl;
    }
    else {
        // Informar del error de lectura del fichero
        cerr << " El fichero " << fichero << " es innacesible" << endl;
    }

}



/*
 * Pre: <<n>> es un entero positivo que indica el numero de tarjetas a generar yç
 *      <<tipo>> indica el tipo de tarjeta que se va a crear
 * Post: Ha almacenado en el arbol binario <<a>> todas las tarjetas generadas
 */
void generarTarjetasValidas(const int n, const int tipo, Arbol a){

    // Escritura de la cabecera
    cout << endl;
    cout << "  LISTADO DE TARJETAS DE CREDITO " << endl;
    cout << endl;
    cout << "  Posicion              Tarjeta " << endl;
    cout << " ---------     ---------------- " << endl;

    // Comenzar lectura del fichero de tarjetas
    string tarjeta;
    // lectura de tarjeta
    for (int i = 0; i < n; i++){
        // Comprobacion de si la tarjeta es valida
        tarjeta = generarTarjeta(tipo);
        // Es valida
        cout << setw(10) << i + 1 << " " << setw(20) << tarjeta << endl;
        // Insertar la nueva tarjeta en el arbol
        insertar(a, tarjeta);
    }
}


