#include <iostream>
#include <fstream>
#include "pila.h"
using namespace std;
void escribeYSumaDigitos(long int num) {
	Pila<int> pil;
	int suma = 0;
	while (num > 0) {
		int aux = num % 10;
		suma += aux;
		pil.apila(aux);
		num = num / 10;

	}
	while (!pil.esVacia()) {
		cout <<" "<< pil.cima();
		pil.desapila();
		if (!pil.esVacia()) {
			cout << " +";
		}
	}
	cout << " = " << suma;
	cout << endl;
}


int main() {
	ifstream fileIn;
	long int num;

	fileIn.open("entrada.txt");
	if (fileIn.is_open()) {
		while (fileIn >> num) {
			cout << num << " --> ";
			escribeYSumaDigitos(num);
		}
		fileIn.close();
	}
	return 0;
}
