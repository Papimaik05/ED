/** PONED NOMBRES Y APELLIDOS, ASÍ COMO NÚMERO DE GRUPO
GRUPO:
NOMBRE Y APELLIDOS (INTEGRANTE 1):
NOMBRE Y APELLIDOS (INTEGRANTE 2):
*/

#include <iostream>
#include <string>
#include "cola.h"
#include "pila.h"
using namespace std;



void lee_caso(Cola<char>& cola) {
	char ch;
	cin.get(ch);
	while (ch != '\n') {
		if (ch != ' ')
			cola.pon(ch);
		cin.get(ch);
	}
}


bool palindroma(Cola<char> cola) {
	Pila<char> pil;
	Cola<char> colaAux1=cola;
	bool pal = true;
	if (!colaAux1.esVacia()) {
		while (!colaAux1.esVacia()) {
			pil.apila(colaAux1.primero());
			colaAux1.quita();
		}
		Cola<char> colaAux2;
		while (!pil.esVacia()) {
			colaAux2.pon(pil.cima());
			pil.desapila();
		}

		if (!cola.operator==(colaAux2)) {
			pal=false;
		}

	}
	return pal;
}


int main() {
	Cola<char> cola;

	lee_caso(cola);

	Cola<char> colaAux;
	colaAux = cola;
	int longitud = colaAux.longitud();
	for (int i = 1; i <= longitud; i++) {
		cout << colaAux.primero();
		colaAux.quita();
	}
	cout << " = ";
	if (palindroma(cola)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}



