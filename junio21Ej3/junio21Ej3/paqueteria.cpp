/**
  NOMBRE Y APELLIDOS:
  USUARIO JUEZ:
*/

#include "paqueteria.h"

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
InfoPaquete::InfoPaquete(const string& dir, const float& peso, Posicion pos) :
    _dir(dir), _peso(peso), _pos(pos)
{}
const string InfoPaquete::dir() const {
    return _dir;
}
const float InfoPaquete::peso() const {
    return _peso;
}
Posicion InfoPaquete::pos() const {
    return _pos;
}
Paqueteria::Paqueteria() {
    // A IMPLEMENTAR

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void Paqueteria::recepciona_paquete(IdPaquete id, string dir, float peso) {
    // A IMPLEMENTAR
    if (_dicc.contiene(id)) {
        throw EPaqueteDuplicado();
    }
    else {
        _lista.pon_ppio(id);
        _dicc.inserta(id, InfoPaquete(dir, peso, _lista.begin()));
    }
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void Paqueteria::info_paquete(IdPaquete id, string& dir, float& peso) const {
    // A IMPLEMENTAR
    if (!_dicc.contiene(id)) {
        throw EPaqueteInexistente();
    }
    else {
        dir = _dicc.valorPara(id).dir();
        peso = _dicc.valorPara(id).peso();
    }
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool Paqueteria::hay_paquetes() const {
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
void Paqueteria::primero_en_fila(IdPaquete& id) const {
    // A IMPLEMENTAR
    if (_lista.esVacia()) {
        throw ENingunPaqueteEnEspera();
    }
    else {
        id= _lista.ultimo();
    }
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void Paqueteria::nuevo_camion(float peso) {
    // A IMPLEMENTAR
    _colacamiones.pon(peso);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void Paqueteria::primer_camion(float& peso) const {
    // A IMPLEMENTAR
    if (_colacamiones.esVacia()) {
        throw ENingunCamionEnEspera();
    }
    else {
        peso = _colacamiones.primero();
    }
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void Paqueteria::elimina(IdPaquete id) {
    // A IMPLEMENTAR
    if (_dicc.contiene(id)) {
        _lista.eliminar(_dicc.valorPara(id).pos());
        _dicc.borra(id);
    }

}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
Lista<IdPaquete> Paqueteria::carga_camion() {
    // A IMPLEMENTAR
    if (_colacamiones.esVacia() || _lista.esVacia()) {
        throw EErrorCarga();
    }
    else {
        Lista <IdPaquete> aux;

        float peso = _colacamiones.primero();
        float contador = 0;
        while (!_lista.esVacia() && contador + _dicc.valorPara(_lista.ultimo()).peso() <= peso ) {
            aux.pon_final(_lista.ultimo());
            contador += _dicc.valorPara(_lista.ultimo()).peso();
            elimina(_lista.ultimo());
        }
        _colacamiones.quita();
        return aux;
    }

}



