/*
NOMBRE Y APELLIDOS:

USUARIO DomJudge ASIGNADO:

*/

#include "yoMeVacuno.h"

InfoCiudadano::InfoCiudadano(const tAnio& anio) {
	_aniociu = anio;
	_aceptado = false;
	_solicitud = false;
}

const tAnio InfoCiudadano::anio()const {
	return _aniociu;
}
void InfoCiudadano::setAcept(bool acept) {
	_aceptado = acept;
}
void InfoCiudadano::setSoli(bool sol) {
	_solicitud = sol;
}
const bool InfoCiudadano::aceptado()const {
	return _aceptado;
}

const bool InfoCiudadano::solicitud()const {
	return _solicitud;
}

InfoCentro::InfoCentro(const tDireccion &direccion, Cola<tIdCiudadano> cola) :
	_direccion(direccion), _colaciudadano(cola) {}

const tDireccion InfoCentro::direccion() const {
	return _direccion;
}

Cola<tIdCiudadano> InfoCentro::colaCiu() {
	return _colaciudadano;
}

tNumVacunas YoMeVacuno::vacunas() {
	return _vacunas;
}


tAnio YoMeVacuno::anio() {
	return _anio;
}
/*
 DETERMINACION DE LA COMPLEJIDAD

*/
YoMeVacuno::YoMeVacuno(tAnio anio, tNumVacunas n) {
	// A IMPLEMENTAR
	_anio = anio;
	_vacunas = n;
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::fija_Anio_NumVacunas(tAnio anio, tNumVacunas n) {
	// A IMPLEMENTAR 
	_anio = anio;
	_vacunas += n;

}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::registra_centro(tIdCentro id, tDireccion dir) {
	// A IMPLEMENTAR 
	if (_centros.contiene(id)) {
		throw ECentroDuplicado();
	}
	else {
		_centros.inserta(id, InfoCentro(dir, Cola<tIdCiudadano>()));
	}

}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::registra_ciudadano(tIdCiudadano id, tAnio anio) {
	// A IMPLEMENTAR 
	if (_ciudadanos.contiene(id)) {
		throw ECiudadanoDuplicado();
	}
	else {
		_ciudadanos.inserta(id, InfoCiudadano(anio));
	}

}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::pide_cita(tIdCiudadano id) {
	// A IMPLEMENTAR
	if (!_ciudadanos.contiene(id)) {
		throw ECiudadanoInexistente();
	}
	else {
		if (_ciudadanos.valorPara(id).anio() != anio()) {
			throw EAnioErroneo();
		}
		else {
			if (_ciudadanos.valorPara(id).aceptado() || _ciudadanos.valorPara(id).solicitud()) {
				throw EExisteCita();
			}
			else {
				_colatotal.pon(id);
				InfoCiudadano ciu = _ciudadanos.valorPara(id);
				ciu.setSoli(true);
				_ciudadanos.inserta(id, ciu);

			}
		}
	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
bool YoMeVacuno::en_espera() {
	// A IMPLEMENTAR
	if (_colatotal.esVacia()) {
		return false;
	}
	else {
		return true;
	}

}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
Lista<Asignacion> YoMeVacuno::atiende_solicitudes() {
	// A IMPLEMENTAR
	if (_centros.esVacio()) {
		throw EErrorDeAtencion();
	}
	else {

		Lista<Asignacion> aux;
		if (!_colatotal.esVacia() && _vacunas>0) {
			Diccionario<tIdCentro, InfoCentro>::ConstIterator it = _centros.cbegin();
			while (!_colatotal.esVacia() && _vacunas>0) {
				Asignacion asig;
				asig.ponCentro(it.clave());
				asig.ponCiudadano(_colatotal.primero());
				asig.ponDireccion(it.valor().direccion());
				aux.pon_final(asig);
				InfoCentro auxcentro = _centros.valorPara(it.clave());
				Cola<tIdCiudadano> auxcola = auxcentro.colaCiu();
				auxcola.pon(_colatotal.primero());
				_centros.inserta(it.clave(), InfoCentro(auxcentro.direccion(),auxcola));
				_colatotal.quita();
				it.next();
				if (it == _centros.cend()) {
					it = _centros.cbegin();
				}
				_vacunas -= 1;
			}
		}
		return aux;
	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
bool YoMeVacuno::administra_vacuna(tIdCentro idCentro) {
	// A IMPLEMENTAR
	if (!_centros.contiene(idCentro)) {
		throw ECentroInexistente();
	}
	else {
		InfoCentro info = _centros.valorPara(idCentro);
		Cola<tIdCiudadano> auxcola = info.colaCiu();
		if (auxcola.esVacia()) {
			return false;
		}
		else {

			while (!auxcola.esVacia()) {
				InfoCiudadano aux = auxcola.primero();
				aux.setAcept(true);
				_ciudadanos.inserta(auxcola.primero(), aux);
				auxcola.quita();
			}
			_centros.inserta(idCentro, InfoCentro(info.direccion(),auxcola));
			return true;
		}
	}

}
