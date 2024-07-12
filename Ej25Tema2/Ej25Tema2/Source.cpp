#include <iostream>
using namespace std;
#include "lista.h"


// EJERCICIO 20
// procedimiento genérico que muestra por pantalla una lista (asume elementos imprimibles)

template <class T>
void pinta(const Lista<T>& lista) {
	// Inside a declaration or a definition of a template, 
	// typename can be used to declare that a dependent qualified name is a type.
	// Si declaramos un tipo iterador de una lista no genérica, typename no es necesario.
	typename Lista<T>::ConstIterator it = lista.cbegin();
	while (it != lista.cend()) {
		cout << it.elem() << endl;
		it.next();
	}
}



// EJERCICIO 24
// subprograma que reciba dos listas de enteros ordenados crecientemente 
// y devuelva una nueva lista ordenada con la unión de los enteros de las 
// dos listas iniciales
Lista<int> mezclar(const Lista<int>& l1, const Lista<int>& l2) {
	Lista<int> fin;
	Lista<int>::ConstIterator it1 = l1.cbegin();
	Lista<int>::ConstIterator it2 = l2.cbegin();


	while (it1!=l1.cend() && it2!=l2.cend()) {
		if (it1.elem() > it2.elem()) {
			fin.pon_final(it2.elem());
			it2.next();
		}
		else if (it2.elem() > it1.elem()) {
			fin.pon_final(it1.elem());
			it1.next();

		}
		else {
			fin.pon_final(it1.elem());
			fin.pon_final(it2.elem());
			it1.next();
			it2.next();
		}
	}
	while (it1 != l1.cend()) {
		fin.pon_final(it1.elem());
		it1.next();
	}
	while (it2 != l2.cend()) {
		fin.pon_final(it2.elem());
		it2.next();
	}

	return fin;
}



// EJERCICIO 25
// subprograma que elimina los números pares de una lista de enteros
void quitaPares(Lista<int>& lista) {
	Lista<int>::Iterator it = lista.begin();
	while (it != lista.end()) {
		if (it.elem() % 2 == 0) {
			it=lista.eliminar(it);
		}
		else {
			it.next();
		}

	}
}

//EJRCICIO 

int main() {

	// listas para las pruebas
	Lista<int> listaVacia, lista1, lista2, lo1, lo2;

	for (int i = 1; i <= 6; i++)
		for (int repeticiones = 1; repeticiones <= 2; repeticiones++)
			lista1.pon_final(i);

	for (int i = 2; i <= 6; i = i + 2)
		lista2.pon_ppio(i);

	for (int i = 1; i < 10; i = i + 2)
		lo1.pon_final(i);

	for (int i = 0; i <= 10; i = i + 2)
		lo2.pon_final(i);



	cout << "\n\n--- EJ24: uso de MEZCLAR para MEZCLAR DOS LISTAS ORDENADAS ---\n";

	cout << "Cuando mezclo dos listas vacias resulta\n";
	pinta(mezclar(listaVacia, listaVacia));
	cout << endl;

	cout << "Cuando mezclo la lista vacia con \n";
	pinta(lo1);
	cout << "Resulta\n";
	pinta(mezclar(listaVacia, lo1));

	cout << "Cuando mezclo\n";
	pinta(lo1);
	cout << "con la lista vacia resulta\n";
	pinta(mezclar(lo1, listaVacia));

	cout << "Cuando mezclo\n";
	pinta(lo1);
	cout << "con\n";
	pinta(lo2);
	cout << "Resulta\n";
	pinta(mezclar(lo1, lo2));

	cout << "Cuando mezclo\n";
	pinta(lo2);
	cout << "con\n";
	pinta(lo1);
	cout << "Resulta\n";
	pinta(mezclar(lo2, lo1));



	/*cout << "\n\n--- EJ25: uso de ELIMINAR para ELIMINAR LOS PARES DE lista ---\n";

	cout << "Cuando elimino los numeros pares de la lista vacia resulta\n";
	quitaPares(listaVacia);
	pinta(listaVacia);
	cout << endl;

	cout << "Cuando elimino los numeros pares de la lista\n";
	pinta(lista1);
	cout << "Resulta\n";
	quitaPares(lista1);
	pinta(lista1);
	cout << endl;

	cout << "Cuando elimino los numeros pares de la lista\n";
	pinta(lista2);
	cout << "Resulta\n";
	quitaPares(lista2);
	pinta(lista2);
	cout << endl;*/


	return 0;
}