#include <iostream>
#include "pila.h"
using namespace std;

void ejer5(Pila<int> entrada) {
	Pila<int> aux;
	while (!entrada.esVacia()) {
		aux.apila(entrada.cima());
		entrada.desapila();
	}
	while (!aux.esVacia())
	{
		cout << aux.cima() << " ";
		aux.desapila();
	}
	cout << "\n";
}

void recursiva(Pila<int> entrada) {
	if (!entrada.esVacia()) {
		int aux = entrada.cima();
		entrada.desapila();
		recursiva(entrada);
		cout << aux << " ";
	}
}
int main() {
	Pila<int> pepe;
	pepe.apila(6);
	pepe.apila(5);
	pepe.apila(4);
	pepe.apila(3);
	pepe.apila(2);
	pepe.apila(1);
	ejer5(pepe);
	cout << "\n";
	recursiva(pepe);

}