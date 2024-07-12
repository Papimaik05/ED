#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/** Indica aquí, razonadamente, la complejidad de numero_neutros

*/
int aux(const Arbin<int>& a,int &resul) {
	if (!a.esVacio()) {
		if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) {
			resul++;
			if (a.raiz() > 0) {
				return 1;
			}
			else {
				return 0;
			}
			
		}
		else {
			int posIz= aux(a.hijoIz(), resul);
			int posDer= aux(a.hijoDer(), resul);
			if (posIz == posDer) {
				resul++;
			}
			if (a.raiz() > 0) {
				return posIz+posDer+1;
			}
			else {
				return posIz + posDer;
			}
		}
	}
	else {
		return 0;
	}
}
unsigned int numero_neutros(const Arbin<int>& a) {
	int resul = 0;
	int pepe=aux(a,resul);
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


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		cout << numero_neutros(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
