/*
NOMBRE Y APELLIDOS PRIMER INTEGRANTE DEL GRUPO:
NOMBRE Y APELLIDOS SEGUNDO INTEGRANTE DEL GRUPO:
USUARIO DEL JUEZ DOMJUDGE:
 */


 /**
   @file Cola.h

   Implementaci�n del TAD Cola utilizando una
   lista enlazada de nodos.

   Estructura de Datos y Algoritmos
   Facultad de Inform�tica
   Universidad Complutense de Madrid

  (c) Marco Antonio G�mez Mart�n, 2012   Mercedes G�mez Albarr�n, 2016
 */
#ifndef __COLA_LISTA_ENLAZADA_H
#define __COLA_LISTA_ENLAZADA_H
#include <cstddef>
#include <iostream>
using namespace std;

/// Excepciones generadas por algunos m�todos
class EColaVacia {};


/**
 Implementaci�n del TAD Cola utilizando una lista enlazada.

 Las operaciones son:

 - ColaVacia: -> Cola. Generadora implementada en el
   constructor sin par�metros.
 - pon: Cola, Elem -> Cola. Generadora
 - quita: Cola - -> Cola. Modificadora parcial.
 - primero: Cola - -> Elem. Observadora parcial.
 - esVacia: Cola -> Bool. Observadora.

 @author Marco Antonio G�mez Mart�n   Mercedes G�mez Albarr�n
 */
template <class T>
class Cola {
public:
	/* COMPLEJIDAD: Determina justificadamente la complejidad de esta operaci�n


	*/
	void penalizaSecuencia(int inicio, int fin) {
		if (inicio>=0 && fin>=inicio) {
			int contador = 0;
			Nodo *cont = _prim;
			Nodo *auxInicio = _prim;
			Nodo *auxFinal = _prim;
			Nodo *prevIni = _prim;
			Nodo *postFin = _prim;
			while (cont != _ult) {
				if (contador == inicio - 1 && inicio > 0) {
					prevIni = cont;
				}
				else if (inicio == contador) {
					auxInicio = cont;
				}
				else if (fin == contador) {
					auxFinal = cont;
				}
				else if (fin+1== contador) {
					postFin = cont;
				}
				cont = cont->_sig;
				contador++;
			}
			if (fin <= contador &&inicio>=0) {
				if (postFin == _prim) {
					postFin = _ult;
				}
				if (inicio == 0) {
					_prim = postFin;
				}
				else {
					prevIni->_sig = postFin;
				}
				postFin->_sig = auxInicio;
				_ult = auxFinal;
				_ult->_sig = NULL;
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
	 A�ade un elemento en la parte trasera de la cola.
	 Operaci�n generadora.

	 @param elem Elemento a a�adir.
	*/
	void pon(const T& elem) {
		Nodo* nuevo = new Nodo(elem);
		if (esVacia()) _prim = nuevo;
		else _ult->_sig = nuevo;
		_ult = nuevo;
	}

	/**
	 Elimina el primer elemento de la cola.
	 Operaci�n modificadora parcial.

	 error: falla si la cola est� vac�a
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
	 Devuelve el primer elemento de la cola. Operaci�n
	 observadora parcial.

	 error: falla si la cola est� vac�a
	 @return El primer elemento de la cola.
	 */
	const T& primero() const {
		if (esVacia())
			throw EColaVacia();
		return _prim->_elem;
	}

	/**
	 Indica si la cola tiene elementos o no.

	 @return true si la cola no tiene ning�n elemento.
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

	/** Operador de asignaci�n */
	Cola<T>& operator=(const Cola<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
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
	 y un puntero al nodo siguiente, que podr�a ser NULL si
	 el nodo es el �ltimo de la lista enlazada.
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

	/** Puntero al �ltimo elemento. */
	Nodo* _ult;
};

#endif // __COLA_LISTA_ENLAZADA_H

