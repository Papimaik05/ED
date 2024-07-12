/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "GestionAdmisiones.h"

/**
Implementación de las operaciones de la clase Paciente
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas) :
	_nombre(nombre), _sintomas(sintomas), _edad(edad) {}

unsigned int Paciente::edad() const {
	return _edad;
}
const string& Paciente::nombre() const {
	return _nombre;
}
const string& Paciente::sintomas() const {
	return _sintomas;
}

InfoPaciente::InfoPaciente(Posicion pos, const Paciente& pac, const Gravedad& grav) :
_pos(pos),_paciente(pac),_grav(grav){}

Posicion InfoPaciente::posicion() const {
	return _pos;
}
const Gravedad InfoPaciente::gravedad()const {
	return _grav;
}
const Paciente InfoPaciente::paciente()const {
	return _paciente;
}
/**
Implementa aquí los métodos de las clases adicionales
*/


/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENTAR
	if (_diccionario.contiene(codigo)) {
		throw EPacienteDuplicado();
	}
	else {
		_lista[gravedad].pon_ppio(codigo);
		_diccionario.inserta(codigo, InfoPaciente(_lista[gravedad].begin(), Paciente(nombre, edad, sintomas), gravedad));
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	if (!_diccionario.contiene(codigo)) {
		throw EPacienteNoExiste();
	}
	else {
		nombre = _diccionario.valorPara(codigo).paciente().nombre();
		edad = _diccionario.valorPara(codigo).paciente().edad();
		sintomas = _diccionario.valorPara(codigo).paciente().sintomas();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENTAR
	if (!_lista[2].esVacia()) {
		codigo = _lista[2].ultimo();
		gravedad = GRAVE;
	}
	else{
		if (!_lista[1].esVacia()) {
			codigo = _lista[1].ultimo();
			gravedad = NORMAL;
		}
		else {
			if (!_lista[0].esVacia()) {
				codigo = _lista[0].ultimo();
				gravedad = LEVE;
			}
			else {
				throw ENoHayPacientes();
			}
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {
	// A IMPLEMENTAR
	if (!_lista[2].esVacia()) {
		return true;
	}
	else {
		if (!_lista[1].esVacia()) {
			return true;
		}
		else {
			if (!_lista[0].esVacia()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	if (_diccionario.contiene(codigo)) {
		_lista[_diccionario.valorPara(codigo).gravedad()].eliminar(_diccionario.valorPara(codigo).posicion());
		_diccionario.borra(codigo);
	}

}

