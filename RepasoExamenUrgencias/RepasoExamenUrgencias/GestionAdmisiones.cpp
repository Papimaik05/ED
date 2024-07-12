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

InfoPaciente::InfoPaciente():
{}

Posicion InfoPaciente::posicion() const {
	return _posicion;
}
const Paciente InfoPaciente:: datos() const {
	return _datos;
}
/**
Implementa aquí los métodos de las clases adicionales
*/


/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de las mismas.
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
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	// A IMPLEMENTAR
	if (_diccionarioP.contiene(codigo)) {
		throw EPacienteDuplicado();
	}
	else {
		_lista.pon_ppio(codigo);
		_diccionarioP.inserta(codigo, InfoPaciente(_lista.begin(), Paciente(nombre, edad, sintomas)));
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	if (!_diccionarioP.contiene(codigo)) {
		throw EPacienteNoExiste();
	}
	else {
		nombre = _diccionarioP.valorPara(codigo).datos().nombre();
		edad = _diccionarioP.valorPara(codigo).datos().edad();
		sintomas = _diccionarioP.valorPara(codigo).datos().sintomas();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
	// A IMPLEMENTAR
	if (_lista.esVacia()) {
		throw ENoHayPacientes();
	}
	else {
		codigo=_lista.ultimo();
	}

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {
	// A IMPLEMENTAR
	if (_lista.esVacia()) {
		return false;
	}
	else {
		return true;
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	if (_diccionarioP.contiene(codigo)) {
		_lista.eliminar(_diccionarioP.valorPara(codigo).posicion());
		_diccionarioP.borra(codigo);
	}

}

