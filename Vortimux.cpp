#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

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
    for (int i = 1; i < longitud; i++){
		// obtencion del caracter iésima
        digito = tarjeta.at(i - 1) - '0';
		// si la posicion es par
        if (i % 2 == 0){
			// multiplicar por dos el valor
            valor = 2 * digito;
			// comprobar que el numero tiene el mas de una cifras
			if (valor >= 10){
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
	return 10 - digito == tarjeta.at(longitud - 1) - '0'; 
}



int main (){
    string t = "79927398713";
	
	if (esTarjetaValida(t)){
		cout << " Tarjeta valida " << endl;
	}
	else{
		cout << " Tarjeta invalida " << endl;
	}
    return 0;
}
