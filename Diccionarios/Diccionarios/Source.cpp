// plantilla para Diccionario<string, lista<int>>
#include "diccionario.h"
#include "lista.h"
#include <iostream>
#include <string>
using namespace std;



void refsCruzadasOrigen(const Lista<string>& texto) {
	Lista<string>::ConstIterator it(texto.cbegin());
	Diccionario<string, int> refs;
	while (it != texto.cend()) {
		Diccionario<string, int>::Iterator aux = refs.busca(it.elem());
		if (aux == refs.end()) {
			refs.inserta(aux.clave(), 1);
		}
		else {
			aux.valor()++;
		}

		it.next();
	}

	Diccionario<string, int>::ConstIterator ita = refs.cbegin();
	while (ita != refs.cend()) {
		cout << ita.clave() << " " << ita.valor() << endl;
		ita.next();
	}
}

template <class T>
void imprimeLineas(const Lista<T>& lineas) {
	typename Lista<T>::ConstIterator i = lineas.cbegin();
	typename Lista<T>::ConstIterator fin = lineas.cend();
	while (i != fin) {
		cout << i.elem() << " ";
		i.next();
	}
}
// subprograma que computa las referencias cruzadas y las muestra por pantalla
void refsCruzadas(const Lista<Lista<string>>& texto) {
	Diccionario<string, Lista<int>> refs;
	Lista<Lista<string>>::ConstIterator it(texto.cbegin());
	int contador = 1;
	while (it !=texto.cend()) {
		Lista<string>::ConstIterator it1(it.elem().cbegin());
		while (it1!=it.elem().cend()) {
			Diccionario<string, Lista<int>> ::Iterator aux = refs.busca(it1.elem());
			if (aux == refs.end()) {
				Lista<int> listas;
				listas.pon_final(contador);
				refs.inserta(it1.elem(), listas);
			}
			else {
				aux.valor().pon_final(contador);
			}
			it1.next();
		}
		contador++;
		it.next();
	}

	Diccionario<string, Lista<int>>::ConstIterator ita = refs.cbegin();
	while (ita != refs.cend()) {
		cout << ita.clave();
		cout << " ";
		imprimeLineas(ita.valor());
		cout << "\n";

		ita.next();
	}
	

}

void refsCruzadas(const Lista<Lista<string>>& texto) {
	Diccionario<string, Lista<int>> refs;
	Lista<Lista<string>>::ConstIterator it(texto.cbegin());
	int contador = 1;
	while (it !=texto.cend()) {
		Lista<string>::ConstIterator it1(it.elem().cbegin());
		while (it1!=it.elem().cend()) {
			Diccionario<string, Lista<int>> ::Iterator aux = refs.busca(it1.elem());
			if (aux == refs.end()) {
				Lista<int> listas;
				listas.pon_final(contador);
				refs.inserta(it1.elem(), listas);
			}
			else {
				aux.valor().pon_final(contador);
			}
			it1.next();
		}
		contador++;
		it.next();
	}

	Diccionario<string, Lista<int>>::ConstIterator ita = refs.cbegin();
	while (ita != refs.cend()) {
		cout << ita.clave();
		cout << " ";
		imprimeLineas(ita.valor());
		cout << "\n";

		ita.next();
	}
}

int main() {
	Lista<Lista<string>> lineas;

	// inicialización de lineas 

	Lista<string> linea1;
	linea1.pon_ppio("hola");
	linea1.pon_ppio("adios");
	linea1.pon_ppio("hola");
	linea1.pon_ppio("bye");
	lineas.pon_final(linea1);


	Lista<string> linea2;
	linea2.pon_ppio("amigo");
	linea2.pon_ppio("mio");
	linea2.pon_ppio("adios");
	linea2.pon_ppio("bye");
	lineas.pon_final(linea2);


	Lista<string> linea3;
	linea3.pon_ppio("querido");
	linea3.pon_ppio("amigo");
	linea3.pon_ppio("hola");
	linea3.pon_ppio("adios");
	lineas.pon_final(linea3);


	// mostramos las referencias cruzadas
	refsCruzadas(lineas);

	return 0;
}
