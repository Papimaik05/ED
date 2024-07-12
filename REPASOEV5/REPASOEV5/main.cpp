// NOMBRE Y APELLIDOS DEL PRIMER INTEGRANTE:
// NOMBRE Y APELLIDOS DEL SEGUNDO INTEGRANTE:
// Nº DE GRUPO:
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

int aux(const Arbin<char>& a, int monstruos, int& resul) {
	int caballeros = 0;
	if (!a.esVacio()) {
		if (a.raiz() == 'M') {
			monstruos++;
		}
		if (a.raiz() == 'C') {
			caballeros++;
		}
		int auxIz = aux(a.hijoIz(), monstruos, resul);
		int auxDer = aux(a.hijoDer(), monstruos, resul);
		int auxT = auxIz + auxDer + caballeros;
		if (a.raiz() == 'D') {
			if (monstruos <= auxT) {
				resul++;
			}
		}
		return auxT;
		}
	return 0;
	}


//if (!a.esVacio()) {
//	if (a.raiz() == 'M') {
//		monstruos++;
//	}
//	int auxIz = aux(a.hijoIz(), monstruos, resul);
//	int auxDer = aux(a.hijoDer(), monstruos, resul);
//	int auxT = auxIz + auxDer;
//
//	if (a.raiz() == 'C') {
//		return auxT + 1;
//	}
//	else {
//		if (a.raiz() == 'D') {
//			if (monstruos <= auxT) {
//				resul++;
//			}
//		}
//		return auxT;
//	}
//}
//return 0;

int num_a_salvo(const Arbin<char>& a) {
	int resul = 0;
	int monstruos = 0;
	int ala = aux(a, monstruos, resul);
	return resul;
	/*** A IMPLEMENTAR ***/
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