// NOMBRE Y APELLIDOS DEL PRIMER INTEGRANTE: Miguel Mateos Matias
// NOMBRE Y APELLIDOS DEL SEGUNDO INTEGRANTE: Enrique Martín Rodriguez
// Nº DE GRUPO: 03
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
  FUNCION A IMPLEMENTAR.
  Aparte de esta función, puedes implementar todas las funciones auxiliares que
  consideres oportuno.
  Debes describir y justificar aquí la complejidad de la implementación realizada:

  O(n) =  La complejidad es lineal al número de nodos del árbol,debido a que el algoritmo debe recorrer el arbol entero ,llegando hasta el final de cada rama para a la hora de subir,contar el numero de caballeros
  y poder compararlo con el numero de monstruos que hay desde la raiz hasta el nodo de la dama.

*/
int Aux_num_a_salvo(const Arbin<char>& a,int monstruos,int &resul) {
	/*** A IMPLEMENTAR ***/
	int caballeros = 0;
	if (!a.esVacio()) {
		if (a.raiz() == 'M') {
			monstruos = monstruos + 1;
		}
		int caballerosI = Aux_num_a_salvo(a.hijoIz(), monstruos, resul);
		int caballerosD = Aux_num_a_salvo(a.hijoDer(), monstruos, resul);
		caballeros = caballerosI + caballerosD;

		if (a.raiz() == 'C') {
			caballeros++;
		}
		if (a.raiz() == 'D') {
			if (caballeros >= monstruos) {
				resul++;
			}
		}
	}
	return caballeros;
}
int num_a_salvo(const Arbin<char>& a) {
	/*** A IMPLEMENTAR ***/
	int monstruos = 0;
	int resul = 0;
	int aux=Aux_num_a_salvo(a, monstruos,resul);
	return resul;
}



Arbin<char> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = lee_arbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = lee_arbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}


void escribe_arbol(Arbin<char> a) {
	if (a.esVacio()) cout << "#";
	else if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) cout << "[" << a.raiz() << "]";
	else {
		cout << "(";
		escribe_arbol(a.hijoIz());
		cout << a.raiz();
		escribe_arbol(a.hijoDer());
		cout << ")";
	}
}


int main() {
	Arbin<char> arbol;
	while (cin.peek() != EOF) {
		Arbin<char> mapa = lee_arbol(cin);
		cout << "num_a_salvo ";
		escribe_arbol(mapa);
		cout << " => ";
		cout << num_a_salvo(mapa);
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
