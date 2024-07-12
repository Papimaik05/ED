// INDICA AQU� LOS DATOS DEL GRUPO
// NOMBRE Y APELLIDOS DEL PRIMER INTEGRANTE: Miguel Mateos Matias
// NOMBRE Y APELLIDOS DEL SEGUNDO INTEGRANTE: Enrique Mart�n Rodr�guez
// N� DE GRUPO: 03


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

/**
  COMPLEJIDAD: Explica aqu� justificadamente cu�l es la complejidad de
			   esta funci�n
			   ***A COMPLETAR***
			    
			 
	O(n) =  La complejidad es lineal al n�mero de nodos del �rbol,debido a que el algoritmo debe recorrer todos los nodos del arbol para llegar a las hojas

		 
			   
*/
void aux_numero_hojas_mas_profundas_que(const Arbin<int>& a, unsigned int k,int prof,int &resul) {
	if (!a.esVacio()) { //Si no es vac�o no debe hacer nada
		if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) { //Si es hoja
			if (prof > k) { //si cumple la condicion
				resul++;
			}
		}
		else {
			 aux_numero_hojas_mas_profundas_que(a.hijoIz(),k,prof+1,resul); //LLama al hijo izquierdo aumentando la profundidad debido a que bajamos de nivel
			 aux_numero_hojas_mas_profundas_que(a.hijoDer(),k,prof+1,resul);//LLama al hijo derecho aumentando la profundidad debido a que bajamos de nivel
		}
	}
}

unsigned int numero_hojas_mas_profundas_que(const Arbin<int>& a, unsigned int k) {
	int prof = 1; //Empieza en 1 ,que es el primer nivel del �rbol
	int resul=0; //EN caso de que sea vac�o,no har�a el algoritmo por lo que el resultado seria 0
	aux_numero_hojas_mas_profundas_que(a, k, prof,resul);
	return resul;
}


Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}



/**
La entrada al programa consiste de l�neas formadas por:
(1) Un �rbol de enteros
(2) El valor de k
Los �rboles se codifican de acuerdo con las siguientes reglas:
(1) El �rbol vac�o se codifica como #
(2) Los �rboles simples se codifican como [v], con
	v el valor del nodo
(3) Los �rboles complejos se codifican como (IvD),
	con I la codificaci�n del hijo izquierdo,
	v el valor de la ra�z, y D la codificaci�n
	del hijo derecho.
Para cada l�nea leida, escribe en la salida est�ndar
el n�mero de hojas que est�n a profundidad mayor que k


Ejemplo de entrada:

([2]1([4]3[5])) 0
([2]1([4]3[5])) 1
([2]1([4]3[5])) 2
([2]1([4]3[5])) 3
([2]1([4]3[5])) 4
([2]1([4]3[5])) 100

Salida asociada:

3
3
2
0
0
0

*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		int k;
		cin >> k;
		cout << numero_hojas_mas_profundas_que(a, k) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
