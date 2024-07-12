#include <iostream>
#include "lista.h"
using namespace std;

Lista<int> inter(Lista<int> l1, Lista<int> l2) {
	Lista<int> auxi;

	Lista <int>::ConstIterator It1 = l1.cbegin();
	Lista <int>::ConstIterator It2 = l2.cbegin();

	while (It1!=l1.cend() && It2!=l2.cend()) {
		if (It1.elem() == It2.elem()) {
			auxi.pon_final(It1.elem());
			It1.next();
			It2.next();
		}
		else if (It1.elem() > It2.elem()) {
			It2.next();
		}
		else {
			It1.next();
		}
	}

	return auxi;
}
int main() {

}