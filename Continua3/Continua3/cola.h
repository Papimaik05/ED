/*
NOMBRE Y APELLIDOS PRIMER INTEGRANTE DEL GRUPO: Miguel Mateos Matias
NOMBRE Y APELLIDOS SEGUNDO INTEGRANTE DEL GRUPO: Enrique Martín Rodriguez
USUARIO DEL JUEZ DOMJUDGE: B03
 */


 /**
   @file Cola.h

   Implementación del TAD Cola utilizando una
   lista enlazada de nodos.

   Estructura de Datos y Algoritmos
   Facultad de Informática
   Universidad Complutense de Madrid

  (c) Marco Antonio Gómez Martín, 2012   Mercedes Gómez Albarrán, 2016
 */
#ifndef __COLA_LISTA_ENLAZADA_H
#define __COLA_LISTA_ENLAZADA_H
#include <cstddef>
#include <iostream>
using namespace std;

/// Excepciones generadas por algunos métodos
class EColaVacia {};


/**
 Implementación del TAD Cola utilizando una lista enlazada.

 Las operaciones son:

 - ColaVacia: -> Cola. Generadora implementada en el
   constructor sin parámetros.
 - pon: Cola, Elem -> Cola. Generadora
 - quita: Cola - -> Cola. Modificadora parcial.
 - primero: Cola - -> Elem. Observadora parcial.
 - esVacia: Cola -> Bool. Observadora.

 @author Marco Antonio Gómez Martín   Mercedes Gómez Albarrán
 */
template <class T>
class Cola {
public:
	/* COMPLEJIDAD: Determina justificadamente la complejidad de esta operación

	O ( numero de elementos de la cola) (ya que la recorre entera en el bucle)

	*/
	void penalizaSecuencia(int inicio, int fin) {

		if (inicio >= 0 && fin >= inicio) { //SI no cumple las condiciones iniciales del inicio y fin no entra en el bucle

			Nodo* act = _prim; //nodo auxiliar para saber en cual estamos
			Nodo* auxprevio = _prim; //nodo auxiliar anterior al inicio de la secuencia
			Nodo* auxinicio = _prim; //nodo auxiliar del inicio de la secuencia
			Nodo* auxfinal = _prim;//nodo auxiliar del fin de la secuencia
			int cont = 0; //contador de elementos

			while (act != _ult) { //hasta que recorras la cola entera

				if (cont == inicio) { //guardamos el nodo auxiliar del inicio
					auxinicio = act;
				}
				if (cont == fin) { //guardamos el nodo auxiliar del final
					auxfinal = act;
				}
				if (cont == inicio - 1) { //guardamos el nodo auxiliar previo al inicio
					auxprevio = act;
				}

				act = act->_sig; //Nodo actual apunta al siguiente
				cont++; //Aumentamos contador de elementos
			}

			//RECABLEADO
			if (fin < cont) { //si el fin es superior o igual  al num de elementos no debe modificar nada

				if (inicio != 0) { //en caso de que inicio no sea el primer elemento
					auxprevio->_sig = auxfinal->_sig;  //Unimos el nodo anterior al inicio de la secuencia, con el siguiente nodo del final de la secuencia
					_ult->_sig = auxinicio; // Unimos el ultimo nodo con el  del inicio de la secuencia
					_ult = auxfinal; //establecemos el ultimo nodo de la secuencia como el ultimo
					auxfinal->_sig = NULL;  // El ultimo nodo de la secuencia apunta a vacio		
				}
				else {//si este en el incio lo que quiero penalizar
					_ult->_sig = auxinicio;  // Unimos el ultimo nodo con el  del inicio de la secuencia 
					_prim = auxfinal->_sig;  //establecemos el nodo siguiente al ultimo nodo de la secuencia como el primero
					_ult = auxfinal; //establecemos el ultimo nodo de la secuencia como el ultimo
					auxfinal->_sig = NULL; // El ultimo nodo de la secuencia apunta a vacio
				}
			}
		}
	}

	void imprime() {
		cout << "/";
		if (_prim != NULL) {
			Nodo* act;
			act = _prim;
			while (act != _ult) {
				cout << act->_elem << " ";
				act = act->_sig;
			}
			cout << act->_elem;
		}
		cout << "/";
	}


	/** Constructor; operacion ColaVacia */
	Cola() : _prim(NULL), _ult(NULL) {
	}


	/**
	 Añade un elemento en la parte trasera de la cola.
	 Operación generadora.

	 @param elem Elemento a añadir.
	*/
	void pon(const T& elem) {
		Nodo* nuevo = new Nodo(elem);
		if (esVacia()) _prim = nuevo;
		else _ult->_sig = nuevo;
		_ult = nuevo;
	}

	/**
	 Elimina el primer elemento de la cola.
	 Operación modificadora parcial.

	 error: falla si la cola está vacía
	*/
	void quita() {
		if (esVacia())
			throw EColaVacia();
		Nodo* aBorrar = _prim;
		if (_prim == _ult)
			_prim = _ult = NULL;
		else
			_prim = _prim->_sig;
		delete aBorrar;
	}

	/**
	 Devuelve el primer elemento de la cola. Operación
	 observadora parcial.

	 error: falla si la cola está vacía
	 @return El primer elemento de la cola.
	 */
	const T& primero() const {
		if (esVacia())
			throw EColaVacia();
		return _prim->_elem;
	}

	/**
	 Indica si la cola tiene elementos o no.

	 @return true si la cola no tiene ningún elemento.
	 */
	bool esVacia() const {
		return _prim == NULL;
	}


	/** Destructor; elimina la lista enlazada. */
	~Cola() {
		libera();
		_prim = _ult = NULL;
	}


	/** Constructor copia */
	Cola(const Cola<T>& other) : _prim(NULL), _ult(NULL) {
		copia(other);
	}

	/** Operador de asignación */
	Cola<T>& operator=(const Cola<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparación. */
	bool operator==(const Cola<T>& rhs) const {
		Nodo* p1 = _prim;
		Nodo* p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL) && (p1->_elem == p2->_elem)) {
			p1 = p1->_sig;
			p2 = p2->_sig;
		}
		return (p1 == NULL) && (p2 == NULL);
	}

	bool operator!=(const Cola<T>& rhs) const {
		return !(*this == rhs);
	}


private:

	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que podría ser NULL si
	 el nodo es el último de la lista enlazada.
	 */
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T& elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T& elem, Nodo* sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo* _sig;
	};


	/**
	Genera una copia de other en la cola receptora
	*/
	void copia(const Cola& other) {
		if (other.esVacia())
			_prim = _ult = NULL;
		else {
			Nodo* puntAOrigen = other._prim;
			Nodo* ultimo;
			_prim = new Nodo(puntAOrigen->_elem);
			ultimo = _prim;
			while (puntAOrigen->_sig != NULL) {
				puntAOrigen = puntAOrigen->_sig;
				ultimo->_sig = new Nodo(puntAOrigen->_elem);
				ultimo = ultimo->_sig;
			}
			_ult = ultimo;
		}
	}


	/**
	 Elimina todos los nodos de la lista enlazada que soporta la cola.
	 */
	void libera() {
		while (_prim != NULL) {
			Nodo* aBorrar = _prim;
			_prim = _prim->_sig;
			delete aBorrar;
		}
	}


	/** Puntero al primer elemento. */
	Nodo* _prim;

	/** Puntero al último elemento. */
	Nodo* _ult;
};

#endif // __COLA_LISTA_ENLAZADA_H

