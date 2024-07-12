#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "lista.h"
#include "DiccionarioHash.h"
#include <string>
using namespace std;

class EConductorDuplicado {};
class EConductorNoExiste {};
class EPuntosNoValidos {};

typedef Lista<string>::Iterator Posicion;
class InfoConductor {
	public:
		InfoConductor(int puntos, Posicion posicion);
		Posicion posicion()const;
		int puntos()const;
	private:
		int _puntos;
		Posicion _posicion;
};
class CarnetPorPuntos {
public:
	void nuevo(const string& dni);
	void quitar(const string& dni, unsigned int puntos);
	void recuperar(const string& dni, unsigned int puntos);
	unsigned int consultar(const string& dni) const;
	unsigned int cuantos_con_puntos(unsigned int puntos) const;
	const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:
	Lista<string> _lista[16];
	DiccionarioHash<string, InfoConductor> _diccionario;
	// A COMPLETAR
};

#endif
