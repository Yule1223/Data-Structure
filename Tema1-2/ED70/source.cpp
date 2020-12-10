
// Yule Zhang

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <typename T>
class listaPlus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void modifica() {
		if (this->nelems >= 2) {
			//el primer par lo hacemos por separado(cambia prim)
			Nodo* p = this->prim->sig;
			this->prim->sig = p->sig;
			p->sig = this->prim;
			this->prim = p;
			p = p->sig;//Ultimo intercambiado
			while (p->sig != nullptr && p->sig->sig != nullptr) {
				Nodo* q = p->sig->sig;
				p->sig->sig = q->sig;
				q->sig = p->sig;
				p->sig = q;
				p = p->sig->sig;
			}
		}
	}

	void print() const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			cout << aux->elem << ' ';
			aux = aux->sig;
		}
		cout << endl;
	}
};



bool resuelveCaso() {
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;

	listaPlus<int> l;
	int p;
	for (int i = 0; i < numElem; ++i) {
		cin >> p;
		l.push(p);
	}

	l.modifica();

	l.print();

	return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}