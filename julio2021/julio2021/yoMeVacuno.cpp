/*
NOMBRE Y APELLIDOS:

USUARIO DomJudge ASIGNADO:

*/

#include "yoMeVacuno.h"
#include "cola.h"

InfoCiudadano::InfoCiudadano(tAnio anio):
_aniociu(anio),_aceptado(false) {}

tAnio InfoCiudadano:: anio() {
	return _aniociu;
}

bool InfoCiudadano:: aceptado() {
	return _aceptado;
}
void InfoCiudadano::setAcept(bool acept) {
	_aceptado = acept;
}

InfoCentro::InfoCentro(tDireccion direccion, Cola<tIdCiudadano> cola):
	_direccion(direccion),_colaciudadano(cola) {}

tDireccion InfoCentro::direccion() {
	return _direccion;
}

Cola<tIdCiudadano> InfoCentro::colaCiu() {
	return _colaciudadano;
}


/*
 DETERMINACION DE LA COMPLEJIDAD

*/
YoMeVacuno::YoMeVacuno(tAnio anio, tNumVacunas n) {
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

	if (centros.contiene(id)) {
		throw ECentroDuplicado();
	}
	else {
		centros.inserta(id, InfoCentro(dir, Cola<tIdCiudadano>()));
	}
	// A IMPLEMENTAR 

}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::registra_ciudadano(tIdCiudadano id, tAnio anio) {
	// A IMPLEMENTAR 
	if (ciudadanos.contiene(id)) {
		throw ECiudadanoDuplicado();
	}
	else {
		ciudadanos.inserta(id, InfoCiudadano(anio));
	}

}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
void YoMeVacuno::pide_cita(tIdCiudadano id) {
	// A IMPLEMENTAR
	if (!ciudadanos.contiene(id)) {
		throw ECiudadanoInexistente();
	}
	else {
		InfoCiudadano info = ciudadanos.valorPara(id);
		if (info.anio() != _anio) {
			throw EAnioErroneo();
		}
		else {
			if (info.aceptado() == true) {
				throw EExisteCita();
			}
			else {
				_colatotal.pon(id);
			}
		}

	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
bool YoMeVacuno::en_espera() {
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
	Lista<Asignacion> aux = Lista<Asignacion>();
	if (_vacunas == 0 || _colatotal.esVacia()) {
		return aux;
	}
	else if(centros.esVacio()){
		throw EErrorDeAtencion();
	}
	else {
		tNumVacunas contador = 0;
		Diccionario<tIdCentro, InfoCentro> ::Iterator puntero = centros.begin();
		while (!_colatotal.esVacia()&&contador<_vacunas ) {
			Asignacion a;
			InfoCentro info = centros.valorPara(puntero.clave());
			a.ponCiudadano(_colatotal.primero());
			a.ponCentro(puntero.clave());
			a.ponDireccion(info.direccion());
			aux.pon_final(a);
			Cola<tIdCiudadano> auxcola = info.colaCiu();
			auxcola.pon(_colatotal.primero());
			centros.inserta(puntero.clave(),InfoCentro(info.direccion(),auxcola));
			_colatotal.quita();
			contador++;
			puntero.next();
			if (puntero == centros.end()) {
				puntero = centros.begin();
			}

		}
		_vacunas -= contador;
		return aux;
	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD

*/
bool YoMeVacuno::administra_vacuna(tIdCentro idCentro) {
	// A IMPLEMENTAR
	if (!centros.contiene(idCentro)) {
		throw ECentroInexistente();
	}
	else {
		InfoCentro iC = centros.valorPara(idCentro);
		if (iC.colaCiu().esVacia()) {
			return false;
		}
		else {
			InfoCiudadano iCiu=ciudadanos.valorPara(iC.colaCiu().primero());
			iCiu.setAcept(true);
			Cola<tIdCiudadano> auxcola = iC.colaCiu();
			auxcola.quita();
			centros.inserta(idCentro,InfoCentro(iC.direccion(),auxcola));
			



			return true;
		}
	}

}
