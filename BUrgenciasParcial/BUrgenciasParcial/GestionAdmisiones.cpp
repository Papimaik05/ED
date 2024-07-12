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

/**
Implementa aquí los métodos de las clases adicionales
*/


/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/
InfoPaciente::InfoPaciente(Gravedad gravedad, const Paciente& paciente, const Posicion& posicion) :
_gravedad(gravedad),_paciente(paciente),_posicion(posicion)	{}

Gravedad InfoPaciente::gravedad() const {
	return _gravedad;
}
Posicion InfoPaciente::posicion() const {
	return _posicion;
}
const Paciente InfoPaciente::datos() const {
	return _paciente;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas,  Gravedad gravedad) {
	// A IMPLEMENTAR
	if (_infopacientes.contiene(codigo)) {
		throw EPacienteDuplicado();
	}
	else {
		
		lista_espera[gravedad].pon_ppio(codigo);
		_infopacientes.inserta(codigo, InfoPaciente(gravedad, Paciente(nombre, edad, sintomas), lista_espera[gravedad].begin()));
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	if (!_infopacientes.contiene(codigo)) {
		throw EPacienteNoExiste();
	}
	else {
		nombre = _infopacientes.valorPara(codigo).datos().nombre();
		edad = _infopacientes.valorPara(codigo).datos().edad();
		sintomas = _infopacientes.valorPara(codigo).datos().sintomas();

	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {

	if(!lista_espera[2].esVacia()){
		codigo = lista_espera[2].ultimo();
		gravedad = GRAVE;
	}
	else {
		if (!lista_espera[1].esVacia()) {
			codigo = lista_espera[1].ultimo();
			gravedad = NORMAL;
		}
		else {
			if (!lista_espera[0].esVacia()) {
				codigo = lista_espera[0].ultimo();
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
	if (!lista_espera[2].esVacia()) {
		return true;
	}
	else {
		if (!lista_espera[1].esVacia()) {
			return true;
		}
		else {
			if (!lista_espera[0].esVacia()) {
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
	if (_infopacientes.contiene(codigo)) {
		lista_espera[_infopacientes.valorPara(codigo).gravedad()].eliminar(_infopacientes.valorPara(codigo).posicion());
		_infopacientes.borra(codigo);
	}
	else {
		throw EPacienteNoExiste();
	}
	// A IMPLEMENTAR
}

