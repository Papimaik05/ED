/**
  NOMBRE Y APELLIDOS:
  USUARIO JUEZ:
*/

#ifndef _paqueteria_H
#define _paqueteria_H

#include "lista.h"  
#include "cola.h" 
#include "DiccionarioHash.h" 
#include <string>
using namespace std;

// clases para las excepciones
class EPaqueteDuplicado {};

class EPaqueteInexistente {};

class ENingunPaqueteEnEspera {};

class ENingunCamionEnEspera {};

class EErrorCarga {};

// tipo identificador paquete
typedef unsigned int IdPaquete;

typedef Lista<IdPaquete>::Iterator Posicion;

class InfoPaquete {
	public:
		InfoPaquete(const string &dir,const float &peso,Posicion pos );
		const string dir() const;
		const float peso() const;
		Posicion pos() const;
	private:
		string _dir;
		float _peso;
		Posicion _pos;
};

class Paqueteria {
public:
	Paqueteria();
	void recepciona_paquete(IdPaquete id, string dir, float peso);
	void info_paquete(IdPaquete id, string& dir, float& peso) const;
	void primero_en_fila(IdPaquete& id) const;
	void nuevo_camion(float peso);
	void primer_camion(float& peso) const;
	void elimina(IdPaquete id);
	bool hay_paquetes() const;
	Lista<IdPaquete> carga_camion();
private:
	DiccionarioHash<IdPaquete, InfoPaquete> _dicc;
	Cola<float> _colacamiones;
	Lista<IdPaquete> _lista;
};

#endif
