/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "GestionAdmisiones.h"
#include "DiccionarioHash.h"
#include "lista.h"

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

/**
Implementa aquí los métodos de las clases adicionales
*/
InfoPaciente::InfoPaciente(const Paciente& Paciente, const Posicion& posicion) :
	_paciente(Paciente), _posicion(posicion) {};

Posicion InfoPaciente::posicion() const{
	return _posicion;
}
const Paciente& InfoPaciente::datos() const {
	return _paciente;
}

/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de las mismas.
*/

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	if (_pacientes.contiene(codigo)) {
		throw EPacienteDuplicado();
	}
	else {
		_lista_espera.pon_ppio(codigo);
		Paciente p= Paciente(nombre,edad,sintomas);
		InfoPaciente info = {p,_lista_espera.begin()};
		_pacientes.inserta(codigo, info);
		
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	if (!_pacientes.contiene(codigo)) {
		throw EPacienteNoExiste();
	}
	else {
		InfoPaciente info = _pacientes.valorPara(codigo);
		nombre = info.datos().nombre();
		edad = info.datos().edad();
		sintomas = info.datos().sintomas();

		
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
	if (_lista_espera.esVacia()) {
		throw ENoHayPacientes();
	}
	else {
		codigo=_lista_espera.ultimo();
	}

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {
	if (_lista_espera.esVacia()) {
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
	if (!_pacientes.contiene(codigo)) {
		throw EPacienteNoExiste();
	}
	else {
		Posicion pos= _pacientes.valorPara(codigo).posicion();
		_lista_espera.eliminar(pos);
		_pacientes.borra(codigo);
	}
}

