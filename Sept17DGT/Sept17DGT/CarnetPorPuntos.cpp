#include "CarnetPorPuntos.h"


/**
Implementa aqu� los m�todos de las clases adicionales
*/

InfoConductor::InfoConductor(const Posicion& _pos, int puntos):
 _posicion(_pos),n_puntos(puntos){}

Posicion InfoConductor::posicion() const {
	return _posicion;
}

unsigned int InfoConductor::puntos()const {
	return n_puntos;
}
/**
Debes completar la implementaci�n de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/
CarnetPorPuntos::CarnetPorPuntos() {

}
/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
*/
void CarnetPorPuntos::nuevo(const string& dni) {
	// A IMPLEMENTAR
	if (_conductores.contiene(dni)) {
		throw EConductorDuplicado();
	}
	else {
		_listas_por_puntos[15].pon_ppio(dni);
		InfoConductor info = InfoConductor(_listas_por_puntos[15].begin(), 15);
		_conductores.inserta(dni, info);
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
	// A IMPLEMENTAR
	if (!_conductores.contiene(dni)) {
		throw EConductorNoExiste();
	}
	else {
		if (_conductores.valorPara(dni).puntos() > 0 && puntos>0) {
			_listas_por_puntos[_conductores.valorPara(dni).puntos()].eliminar(_conductores.valorPara(dni).posicion());
			int pts = _conductores.valorPara(dni).puntos() - puntos;
			if (pts < 0) {
				pts = 0;
			}
			_listas_por_puntos[pts].pon_ppio(dni);
			InfoConductor info = InfoConductor(_listas_por_puntos[pts].begin(), pts);
			_conductores.inserta(dni, info);
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
	if (!_conductores.contiene(dni)) {
		throw EConductorNoExiste();
	}
	else {
		if (_conductores.valorPara(dni).puntos() < 15 && puntos > 0) {
			_listas_por_puntos[_conductores.valorPara(dni).puntos()].eliminar(_conductores.valorPara(dni).posicion());
			int pts = _conductores.valorPara(dni).puntos() + puntos;
			if (pts > 15) {
				pts = 15;
			}
			_listas_por_puntos[pts].pon_ppio(dni);
			InfoConductor info = InfoConductor(_listas_por_puntos[pts].begin(), pts);
			_conductores.inserta(dni, info);
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
	if (!_conductores.contiene(dni)) {
		throw EConductorNoExiste();
	}
	else {
		return _conductores.valorPara(dni).puntos();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
	// A IMPLEMENTAR
	if (puntos>15 || puntos<0) {
		throw EPuntosNoValidos();
	}
	else {
		return _listas_por_puntos[puntos].longitud();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
	// A IMPLEMENTAR
	if (puntos > 15 || puntos < 0) {
		throw EPuntosNoValidos();
	}
	else {
		return _listas_por_puntos[puntos];
	}
}

