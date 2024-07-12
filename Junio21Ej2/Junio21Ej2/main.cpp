// NOMBRE Y APELLIDOS:
// USUARIO DEL JUEZ:


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/*
Determinar justificadamente la complejidad del algoritmo:

*/
pair <int,int> aux(const Arbin<int>& a,int &resul) {
	if (!a.esVacio()) {
		pair<int, int>aux1 = aux(a.hijoIz(), resul);
		pair<int, int>aux2 = aux(a.hijoDer(), resul);

		if (!a.hijoDer().esVacio()) {
			if ((aux2.second-aux1.first) ==a.raiz()) {
				resul++;
			}
		}
		return { aux1.first + aux2.first + 1,a.raiz() + aux2.second + aux1.second };
	}
	return { 0,0 };
}
int num_correctivos(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int resul = 0;
	pair <int,int> pepe=aux(a,resul);
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
		cout << num_correctivos(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
