#include "CarnetPorPuntos.h"


/**
Implementa aquí los métodos de las clases adicionales
*/


/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/
InfoConductor::InfoConductor(int puntos, Posicion posicion):
_puntos(puntos),_posicion(posicion){}

Posicion InfoConductor::posicion() const {
	return _posicion;
}

int InfoConductor::puntos() const {
	return _puntos;
}
/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/

void CarnetPorPuntos::nuevo(const string& dni) {
	if (_diccionario.contiene(dni)) {
		throw EConductorDuplicado();
	}
	else {
		_lista[15].pon_ppio(dni);
		_diccionario.inserta(dni, InfoConductor(15, _lista[15].begin()));
	}
}
/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
	// A IMPLEMENTAR
	if (!_diccionario.contiene(dni)) {
		throw EConductorNoExiste();
	}
	else {
		int aux = _diccionario.valorPara(dni).puntos() - puntos;
		if (aux < 0) {
			aux = 0;
		}
		if (aux != _diccionario.valorPara(dni).puntos()) {
			_lista[_diccionario.valorPara(dni).puntos()].eliminar(_diccionario.valorPara(dni).posicion());
			_lista[aux].pon_ppio(dni);
			_diccionario.inserta(dni, InfoConductor(aux, _lista[aux].begin()));
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
	if (!_diccionario.contiene(dni)) {
		throw EConductorNoExiste();
	}
	else {
		int aux = _diccionario.valorPara(dni).puntos() + puntos;
		if (aux > 15) {
			aux = 15;
		}
		if (aux != _diccionario.valorPara(dni).puntos()) {
			_lista[_diccionario.valorPara(dni).puntos()].eliminar(_diccionario.valorPara(dni).posicion());
			_lista[aux].pon_ppio(dni);
			_diccionario.inserta(dni, InfoConductor(aux, _lista[aux].begin()));
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
	// A IMPLEMENTAR
	if (!_diccionario.contiene(dni)) {
		throw EConductorNoExiste();
	}
	else {
		return _diccionario.valorPara(dni).puntos();
	}
	
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {

	// A IMPLEMENTAR
	if (puntos < 0 || puntos>15) {
		throw EPuntosNoValidos();
	}
	else {
		return _lista[puntos].longitud();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
	// A IMPLEMENTAR
	if (puntos < 0 || puntos>15) {
		throw EPuntosNoValidos();
	}
	else {
		return _lista[puntos];
	}
}

