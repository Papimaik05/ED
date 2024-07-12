// NO MODIFIQUES NADA EN ESTE ARCHIVO

#include "paqueteria.h"

#include <iostream>
#include <string>
using namespace std;


void recepciona(Paqueteria& paqueteria) {
	IdPaquete id;
	unsigned int peso;
	string direccion;
	cin >> id >> direccion >> peso;
	try {
		paqueteria.recepciona_paquete(id, direccion, peso);
		cout << "OK" << endl;
	}
	catch (EPaqueteDuplicado) {
		cout << "ID_PAQUETE_DUPLICADO" << endl;
	}
}


void datos_paquete(const Paqueteria& paqueteria) {
	IdPaquete id;
	string direccion;
	float peso;
	cin >> id;
	try {
		paqueteria.info_paquete(id, direccion, peso);
		cout << direccion << " " << peso << endl;
	}
	catch (EPaqueteInexistente) {
		cout << "ID_PAQUETE_NO_EXISTE" << endl;
	}
}

void primero_en_fila(const Paqueteria& paqueteria) {
	IdPaquete id;
	string direccion;
	float peso;
	try {
		paqueteria.primero_en_fila(id);
		paqueteria.info_paquete(id, direccion, peso);
		cout << id << " " << direccion << " " << peso << endl;
	}
	catch (ENingunPaqueteEnEspera) {
		cout << "NO_HAY_PAQUETES" << endl;
	}
}

void nuevoCamion(Paqueteria& paqueteria) {
	unsigned int peso;
	cin >> peso;
	paqueteria.nuevo_camion(peso);
}

void primerCamion(const Paqueteria& paqueteria) {
	float peso;
	try {
		paqueteria.primer_camion(peso);
		cout << peso << endl;
	}
	catch (ENingunCamionEnEspera) {
		cout << "NO_HAY_CAMIONES" << endl;
	}
}

void recogida(Paqueteria& paqueteria) {
	IdPaquete id;
	cin >> id;
	paqueteria.elimina(id);
	cout << "OK" << endl;
}

void en_espera(const Paqueteria& paqueteria) {
	if (paqueteria.hay_paquetes())
		cout << "HAY" << endl;
	else
		cout << "NO HAY" << endl;
}


void carga(Paqueteria& paqueteria) {
	try {
		Lista<IdPaquete> l = paqueteria.carga_camion();
		if (l.esVacia())
			cout << "VACIA" << endl;
		else {
			Lista<IdPaquete>::ConstIterator ilista = l.cbegin();
			while (ilista != l.cend()) {
				cout << ilista.elem() << " ";
				ilista.next();
			}
			cout << endl;
		}
	}
	catch (EErrorCarga) {
		cout << "NO_HAY_CAMIONES o NO_HAY_PAQUETES" << endl;
	}
}

int main() {
	Paqueteria paqueteria;
	string comando;

	while (cin >> comando) {
		if (comando == "recepciona") recepciona(paqueteria);
		else if (comando == "datos") datos_paquete(paqueteria);
		else if (comando == "primeroEnFila") primero_en_fila(paqueteria);
		else if (comando == "nuevoCamion") nuevoCamion(paqueteria);
		else if (comando == "primeroParaCarga") primerCamion(paqueteria);
		else if (comando == "recogeInSitu") recogida(paqueteria);
		else if (comando == "enEspera") en_espera(paqueteria);
		else if (comando == "carga") carga(paqueteria);
	}
	return 0;
}

