#include "Arbin.h"
#include "lista.h"
#include <iostream>

using namespace std;

//Extiende la implementación de los árboles binarios con las siguientes
//operaciones :
//  numNodos : devuelve el número de nodos del árbol.
//  esHoja : devuelve cierto si el árbol es una hoja(los hijos izquierdo y
//	derecho son vacíos).
//	numHojas : devuelve el número de hojas del árbol.
//	talla : devuelve la talla del árbol.
//	frontera : devuelve una lista con todas las hojas del árbol de izquierda a
//	derecha.
//	espejo : devuelve un árbol nuevo que es la imagen especular del
//	original.
//	minElem : devuelve el elemento más pequeño de todos los almacenados
//	en el árbol.Es un error ejecutar esta operación sobre un árbol vacío.

template <class T>
int numnodos(const Arbin<T> dr) {
		
	if (dr.esVacio()) {
		return 0;
	}
	else {
		return numnodos(dr.hijoIz()) + numnodos(dr.hijoDer) + 1;
	}
}

template <class T>
bool esHoja(const Arbin<T> &dr) {
	if (dr.esVacio()) {
		return false;
	}
	else {
		return dr.hijoIz().esVacio() && dr.hijoDer().esVacio();
	}
	
}

template <class T>
int numHojas(const Arbin<T>& dr) {
	if (dr.esVacio()) {
		return 0;
	}
	else {
		if (dr.hijoIz().esVacio() && dr.hijoDer().esVacio()) {
			return 1;
		}
		else {
			return numHojas(dr.hijoIz()) + numHojas(dr.hijoDer());
		}
		
	}
}
template <class T>
int talla(const Arbin<T>& dr) {
	if (dr.esVacio()) {
		return 0;
	}
	else {
		Arbin<T> auxiz = dr.hijoIz();
		Arbin<T> auxder = dr.hijoDer();
		return max(talla(auxiz), talla(auxder)) + 1;
	}
}

template <class T>
Lista<T> frontera(const Arbin<T>& a) {
	Lista<T> f;
	fronteraAux(a, f);
	return f;
}

template <class T>
void fronteraAux(const Arbin<T>& a, Lista<T>& resul) {
	if (!a.esVacio()) {
		if (esHoja(a))
			resul.pon_final(a.raiz());
		else {
			fronteraAux(a.hijoIz(), resul);
			fronteraAux(a.hijoDer(), resul);
		}
	}
}

//minElem: devuelve el elemento más pequeño de todos los almacenados
//	en el árbol.Es un error ejecutar esta operación sobre un árbol vacío.

template <class T>
T minElem(const Arbin<T>& a) {
	if (!a.esVacio()) {
		throw EArbolVacio();
	}
	if (eshoja(a)) {
		return a.raiz();
	}
	else {
		Arbin<T> auxiz = dr.hijoIz();
		Arbin<T> auxder = dr.hijoDer();
		aux= min(minelem(auxiz), minelem(auxder)); //AQUI PUEDE HABER UN ERROR YA QUE SI UNO DE LOS HIJOS ES VACIO SALTA EL THROW ,POR ESO HAY QUE MIRAR QUE NO ESTEEN VACIOS
		return min(a.raiz(),aux);
	}
}
//opcion B

template <class T>
T minElem(const Arbin<T>& a) {
	if (!a.esVacio()) {
		throw EArbolVacio();
	}
	if (eshoja(a)) {
		return a.raiz();
	}
	else if (a.hijoIz().esVacio())) {
		return min(a.raiz(),minElem(a.hijoDer()))
	}
	else if (a.hijoDer().esVacio) {
		return min(a.raiz(), minElem(a.hijoIz()))
	}
	else {
		Arbin<T> auxiz = dr.hijoIz();
		Arbin<T> auxder = dr.hijoDer();
		aux = min(minelem(auxiz), minelem(auxder));
		return min(a.raiz(), aux);
	}
}

//Ej6 Recursiva
template <class T>
bool esdegenerado(const Arbin<T>& a) {
	if (a.esVacio()) {
		return true;
	}
	else {
		return (a.hijoIz().esVacio() && esdegenerado(a.hijoDer()) || a.hijoDer().esVacio() && esdegenerado(a.hijoIz()));
	}
}

//Ej6 iterativa

//Ej8 1 apartado Escribe una función que determine si existe un camino desde la raíz
//hasta una hoja cuyos nodos sumen un valor dado como parámetro.

bool existeCamino(const Arbin<int>& a, int suma) {

	if (a.esVacio()) {
		return false;
	}
	else {

	}
}


//EJ9
template <class T>
bool esBalanceadoAux(const Arbin<T>& a,int &talla) {
	if (a.esVacio()) {
		talla = 0;
		return true;
	}
	else {
		int tallaIz, tallaDer;
		if (esBalanceadoAux(a.hijoIz(), tallaIz) && esBalanceadoAux(a.hijoDer(), tallaDer)) {
			talla = max(tallaIz, tallaDer) + 1;
			return abs(tallaIz - tallaDer) <= 1;
		}
		else {
			return false;
		}
		

	}
}

template <class T>
bool esBalanceado(const Arbin<T>& a) {
	int talla;
	return esBalanceadoAux(a, talla);
}


//ej25
template <class T>
void caminoMenosPeligrosoAux(const Arbin<T>& mundo,int &minDragones,int numDragones,string &cadena) {
	if (esHoja(mundo)) {
		if (numDragones < minDragones) {
			minDragones = numDragones;
			cadena = mundo.raiz();
		}
	}
	else {
		if (mundo.raiz() == "Dragon") {
			numDragones++;
		}
		if (!mundo.hijoIz().esVacio()) {
			return caminoMenosPeligrosoAux(mundo.hijoIz(), minDragones, numDragones, cadena);
		}
		if (!mundo.hijoDer().esVacio()) {
			return caminoMenosPeligrosoAux(mundo.hijoDer(), minDragones, numDragones, cadena);
		}
	}
}

template <class T>
string caminoMenosPeligrosoAux(const Arbin<string>& a) {
	string iden_fin_camino;
	int minDragones = INT_MAX;
	int numDragones = 0;
	caminoMenosPeligrosoAux(a, minDragones, numDragones, iden_fin_camino);
	return iden_fin_camino;
}

//Ej28

template <class T>
bool esZurdo(const Arbin<T>& a) {
	int amin;
	return esZurdoAux(a, amin);
}

template <class T>
bool esZurdoAux(const Arbin<T>& a,int &amin) {
	if (a.esVacio()) {
		amin = 0;
		return true;
	}
	else {
		int aminIz, aminDer;
		if (esZurdoAux(a.hijoIz(), aminIz) && esZurdoAux(a.hijoDer(), aminDer) {

			amin=min(aminIz,aminDer)+1;
			return aminIz>=aminDer;
		}
		else{
			return false;
		}
	}
}

//recolectapares

template <class T>
Lista<T> recolectaPares(const Arbin<T>& a) {
	Lista<T> resul;
	recolectaParesAux(a, resul);
	return resul;
}


template <class T>
void  recolectaParesAux(const Arbin<T>& a,Lista <T> pares) {
	if (!a.esVacio()) {
		if (a.raiz() % 2 == 0) {
			pares.pon_final(a.raiz());
		}
		recolectaParesAux(a.hijoIz(),pares);
		recolectaParesAux(a.hijoDer(),pares);		
	}
}

//recolecta sumatorio

template <class T>
Lista<T> recolectaSumatorio(const Arbin<T>& a) {
	Lista<T> resul;
	recolectaSumatorioAux(a, resul,0);
	return resul;
}


template <class T>
void  recolectaSumatorioAux(const Arbin<T>& a, Lista <T> pares,int suma) {
	if (!a.esVacio()) {
		if (a.raiz()  == suma) {
			pares.pon_final(a.raiz());
		}
		recolectaSumatorioAux(a.hijoIz(), pares,suma+a.raiz());
		recolectaSumatorioAux(a.hijoDer(), pares,suma+a.raiz());
	}
}

//JUNIO 2020
void aux(const Arbin<int>& a, int& neutro, int& posi) {
	if (!a.esVacio()) {
		if (a.hijoDer().esVacio() && a.hijoIz().esVacio()) {
			neutro++;
			if (a.raiz() >= 0) {
				posi++;
			}
		}
		else {
			int posiI = 0, posiD = 0;
			aux(a.hijoIz(), neutro, posiI);
			/*if (a.raiz() >= 0) {
				posiI++;
			}*/
			aux(a.hijoDer(), neutro, posiD);
			/*if (a.raiz() >= 0) {
				posiD++;
			}*/
			if (a.raiz() >= 0)posi++;
			if (posiI == posiD) {
				neutro++;
			}
			posi += posiI + posiD;
		}
	}
}

unsigned int numero_neutros(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int neutro = 0, posi = 0;
	aux(a, neutro, posi);
	return neutro;
}



//EJ22

void numTramosNavegablesAux(const Arbin<int>& cuenca, int &caudal, int& numtramos) {
	if (cuenca.esVacio()) {
		caudal = 0;
	}
	else if (esHoja(cuenca)) {
		caudal = 1;
	}
	else {
		int caudalI,caudalD;
		numTramosNavegablesAux(cuenca.hijoIz(), caudalI, numtramos);
		numTramosNavegablesAux(cuenca.hijoDer(), caudalD, numtramos);

		if (caudalI >= 3) {
			numtramos++;
		}
		if (caudalD >= 3) {
			numtramos++;
		}
		caudal = max(caudalI, caudalD + cuenca.raiz(), 0);

	}
}

int numTramosNavegables(const Arbin<int> &cuenca) {
	int caudal;
	int numTramos = 0;
	numTramosNavegablesAux(cuenca,caudal,numTramos);
	return numTramos;
}

//EJ23

void tiempoAyudaAux(const Arbin<char>& a,int nivel,int &resul) {
	if (!a.esVacio()) {

		if (a.raiz()=='X') {
			resul += nivel * 2;
		}

		tiempoAyudaAux(a.hijoIz(),nivel+1,resul);
		tiempoAyudaAux(a.hijoDer(), nivel + 1, resul);
	}
}
int tiempoAyuda(const Arbin<char>& a) {
	int resul = 0;
	int nivel=0;
	tiempoAyudaAux(a, nivel, resul);
	return resul;
}




int main() {

	return 0;
}
