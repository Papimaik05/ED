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
	InfoConductor(const Posicion& _pos, int puntos);
	Posicion posicion() const;
	unsigned int puntos()const;

private:
	Posicion _posicion;
	unsigned int n_puntos;
};

class CarnetPorPuntos {
public:
	CarnetPorPuntos();
	void nuevo(const string& dni);
	void quitar(const string& dni, unsigned int puntos);
	void recuperar(const string& dni, unsigned int puntos);
	unsigned int consultar(const string& dni) const;
	unsigned int cuantos_con_puntos(unsigned int puntos) const;
	const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:
	// A COMPLETAR
	Lista<string> _listas_por_puntos[16];
	DiccionarioHash<string,InfoConductor> _conductores;
};

#endif
