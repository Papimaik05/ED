// PON AQUÍ TU NOMBRE Y APELLIDOS, ASÍ COMO EL NÚMERO DE TU DOCUMENTO IDENTIFICATIVO
// NOMBRE:
// APELLIDOS: 
// DNI / NIE:


#include "GestionDeMatriculas.h"

InfoEstudiante::InfoEstudiante(tCurso Curs, Posicion pos,PosicionS s) :
_curso(Curs),_posicion(pos),_posicionS(s){}

Posicion InfoEstudiante::posicion() const{
	return _posicion;
}

PosicionS InfoEstudiante::posicionS() const {
	return _posicionS;
}
//bool InfoEstudiante::estaMatriculado() const {
//	return _matriculado;
//}

tCurso InfoEstudiante::curso() const {
	return _curso;
}
InfoCurso::InfoCurso(int nplazas, Lista<tEstudiante> estudiantes, int contador):
_nplazas(nplazas),_estudiantesCurso(estudiantes),_contador(contador){}

Lista<tEstudiante> InfoCurso::estudiantes()const {
	return _estudiantesCurso;
}
int InfoCurso::plazas() const {
	return _nplazas;
}
int InfoCurso::contador() const {
	return _contador;
}
/* Indicar justificadamente la complejidad de la operación

*/
GestionDeMatriculas::GestionDeMatriculas() {
	// IMPLEMENTAR
}


/* Indicar justificadamente la complejidad de la operación

*/
void GestionDeMatriculas::registra_curso(const tCurso& curso, unsigned int plazas) {
	// IMPLEMENTAR
	if (_diccCurso.contiene(curso)) {
		throw ECursoYaExiste();
	}
	else {
		_diccCurso.inserta(curso,InfoCurso(plazas,Lista<tEstudiante>(),0));
	}
}


/* Indicar justificadamente la complejidad de la operación

*/
void GestionDeMatriculas::registra_estudiante(const tEstudiante& estudiante) {
	// IMPLEMENTAR
	if (_diccEstudiante.contiene(estudiante)) {
		throw EEstudianteYaRegistrado();
	}
	else {
		Lista<tEstudiante> aux;
		tCurso aux2;
		_diccEstudiante.inserta(estudiante,InfoEstudiante(aux2,aux.end(),_solicitudes.end()));
	}
}


/* Indicar justificadamente la complejidad de la operación

*/
void GestionDeMatriculas::registra_solicitud(const tEstudiante& estudiante, const tCurso& curso) {
	// IMPLEMENTAR
	if (!_diccCurso.contiene(curso) || !_diccEstudiante.contiene(estudiante)) {
		throw ESolicitud();
	}
	else {
		if (_diccEstudiante.valorPara(estudiante).posicionS() == _solicitudes.end()) {
			if (_diccEstudiante.valorPara(estudiante).curso() != curso) {
				_solicitudes.pon_ppio({ estudiante,curso });
				_diccEstudiante.inserta(estudiante, InfoEstudiante(_diccEstudiante.valorPara(estudiante).curso(), _diccEstudiante.valorPara(estudiante).posicion(), _solicitudes.begin()));
			}
		}
		else {
			if (_diccEstudiante.valorPara(estudiante).curso()!= curso) {
				_solicitudes.insertar({estudiante,curso}, _diccEstudiante.valorPara(estudiante).posicionS());
			}
			else {
				_solicitudes.eliminar(_diccEstudiante.valorPara(estudiante).posicionS());
			}
		}
	}

}


/* Indicar justificadamente la complejidad de la operación

*/
void GestionDeMatriculas::cancela_solicitud(const tEstudiante& estudiante) {
	// IMPLEMENTAR
	if (!_diccEstudiante.contiene(estudiante)) {
		throw EEstudianteNoExiste();
	}
	else {
		if (_diccEstudiante.valorPara(estudiante).posicionS() != _solicitudes.end()) {
			_solicitudes.eliminar(_diccEstudiante.valorPara(estudiante).posicionS());
		}
	}
}

/* Indicar justificadamente la complejidad de la operación

*/
ResultadoSolicitud GestionDeMatriculas::atiende_solicitud() {
	// IMPLEMENTAR
	bool bien = false;
	if (!_solicitudes.esVacia()) {
		pair<tEstudiante, tCurso> aux = _solicitudes.ultimo();
		if (_diccCurso.valorPara(aux.second).plazas() > 0) {
			tCurso kue;
			if (_diccEstudiante.valorPara(aux.first).curso() != kue) {
				_diccCurso.valorPara(_diccEstudiante.valorPara(aux.first).curso()).estudiantes().eliminar(_diccEstudiante.valorPara(aux.first).posicion());
				int plazas = _diccCurso.valorPara(_diccEstudiante.valorPara(aux.first).curso()).plazas() - 1;
				int contador = _diccCurso.valorPara(_diccEstudiante.valorPara(aux.first).curso()).contador() + 1;
				InfoCurso info = InfoCurso(plazas, _diccCurso.valorPara(_diccEstudiante.valorPara(aux.first).curso()).estudiantes(),contador );
				_diccCurso.inserta(_diccEstudiante.valorPara(aux.first).curso(),info);

				_diccCurso.valorPara(aux.second).estudiantes().pon_ppio(aux.first);
				int plazas2 = _diccCurso.valorPara(aux.second).plazas() - 1;
				int contador2 = _diccCurso.valorPara(aux.second).contador() + 1;
				InfoCurso info2 = InfoCurso(plazas2, _diccCurso.valorPara(aux.second).estudiantes(), contador2);
				_diccCurso.inserta(aux.second,info2);
				_diccEstudiante.inserta(aux.first, InfoEstudiante(aux.second, _diccCurso.valorPara(aux.second).estudiantes().begin(),_solicitudes.end()));
				bien = true;
			}
			else {
				_diccCurso.valorPara(aux.second).estudiantes().pon_ppio(aux.first);
				int plazas2 = _diccCurso.valorPara(aux.second).plazas() - 1;
				int contador2 = _diccCurso.valorPara(aux.second).contador() + 1;
				InfoCurso info2 = InfoCurso(plazas2, _diccCurso.valorPara(aux.second).estudiantes(), contador2);
				_diccCurso.inserta(aux.second, info2);
				_diccEstudiante.inserta(aux.first, InfoEstudiante(aux.second, _diccCurso.valorPara(aux.second).estudiantes().begin(), _solicitudes.end()));
				bien = true;
			}
		}
		_solicitudes.quita_final();
		return { aux.first,aux.second,bien };
	}
	else {
		throw ENoHaySolicitudes();
	}

}

/* Indicar justificadamente la complejidad de la operación

*/
Lista<DatosEstudiante> GestionDeMatriculas::estudiantes_en_curso(const tCurso& curso) const {
	// IMPLEMENTAR
	if (!_diccCurso.contiene(curso)) {
		throw ECursoNoExiste();
	}
	else {
		//Lista<DatosEstudiante> aux;
		Lista<tEstudiante> lista = _diccCurso.valorPara(curso).estudiantes();
		int longi = lista.longitud();
		for (int i = longi;i >=0 ;i--) {
			int matricula = i - longi + 1;
			//aux.pon_final({ lista.elem(i),matricula});
		}
		Lista<DatosEstudiante> aux;
		return aux;
	}
}


