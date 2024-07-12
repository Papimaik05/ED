/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/


#ifndef _GESTION_ADMISIONES_H
#define _GESTION_ADMISIONES_H

#include <string>
#include "DiccionarioHash.h"
#include "lista.h"
using namespace std;

/**
Tipo que representa el c�digo de los
pacientes
*/
typedef unsigned int CodigoPaciente;

/**
Clase para almacenar los datos de un paciente
*/
class Paciente {
public:
	/**
	  Operaci�n de construcci�n
	*/
	Paciente(const string& nombre, unsigned int edad, const string& sintomas);

	/**
	  Operaciones observadoras para consultar los distintos
	  datos del paciente: su nombre, su edad y los s�ntomas que
	  tiene
	*/
	unsigned int edad() const;
	const string& nombre() const;
	const string& sintomas() const;
private:
	/** Campos para almacenar los datos del paciente */
	string _nombre;
	string _sintomas;
	unsigned int _edad;
};


/**
RECUERDA QUE PUEDES DEFINIR AQUI TODAS LAS CLASES
Y TIPOS ADICIONALES QUE CONSIDERES OPORTUNO
*/
typedef Lista<CodigoPaciente>::Iterator Posicion;
class InfoPaciente { //Para tener una referencia de donde esta en la lista
	public:
		InfoPaciente(const Paciente& Paciente, const Posicion& posicion);
		Posicion posicion() const;
		const Paciente& datos() const;
	private:
		Paciente _paciente;
		Posicion _posicion;
};

/**
Excepci�n que debe levantarse cuando trata de darse de alta
un paciente con un c�digo duplicado
*/
class EPacienteDuplicado {};

/**
Excepci�n que debe levantarse cuando trata de consultarse los
datos de un paciente a trav�s de un c�digo que no existe.
*/
class EPacienteNoExiste {};

/**
Excepci�n que debe levantarse cuando trata de consultarse la informaci�n
del siguiente paciente a atender, pero no hay pacientes en el sistema.
*/
class ENoHayPacientes {};

/**
Clase que implementa el TAD
*/
class GestionAdmisiones {
public:
	/**
	  Constructora: crea un sistema de gesti�n de admisiones vac�o
	*/
	GestionAdmisiones();
	/**
	  A�ade un paciente al sistema.
	  Levanta la excepci�n EPacienteDuplicado si ya hay un paciente esperando con el
	  mismo codigo
	  @param codigo El c�digo del paciente
	  @param nombre El nombre del paciente
	  @param edad La edad del paciente
	  @param sintomas Los sintomas del paciente
	*/
	void an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas);
	/**
	  Recupera los datos de un paciente, dado su c�digo.
	  Levanta la excepci�n EPacienteNoExiste si el c�digo no se corresponde con el
	  de ning�n paciente en espera
	  @param codigo El c�digo del paciente
	  @param nombre El nombre del paciente
	  @param edad La edad del paciente
	  @param sintomas Los sintomas del paciente
	*/
	void info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const;
	/**
	  Recupera el c�digo del siguiente paciente que va a ser atendido.
	  Levanta la excepci�n ENoHayPacientes en caso de que no haya pacientes en espera.
	  @param codigo El c�digo del paciente
	*/
	void siguiente(CodigoPaciente& codigo) const;
	/**
	 Determina si hay pacientes en espera
	 @return true si hay pacientes, false en otro caso.
   */
	bool hay_pacientes() const;
	/**
	  Elimina del sistema todo el rasto de un paciente, dado su c�digo.
	  Si el c�digo no existe, la operaci�n no tiene efecto.
	  @param codigo El codigo del paciente a eliminar.
	*/
	void elimina(CodigoPaciente codigo);
private:
	// Debe elegirse la representaci�n m�s adecuada para implementar
	// eficientemente este TAD
	DiccionarioHash<CodigoPaciente, InfoPaciente> _pacientes;
	Lista<CodigoPaciente> _lista_espera;
};

#endif
