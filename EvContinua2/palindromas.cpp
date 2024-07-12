/** PONED NOMBRES Y APELLIDOS, ASÍ COMO NÚMERO DE GRUPO
GRUPO:
NOMBRE Y APELLIDOS (INTEGRANTE 1):
NOMBRE Y APELLIDOS (INTEGRANTE 2):
*/

#include <iostream>
#include <string>
using namespace std;
#include "cola.h"

 
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



