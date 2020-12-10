
// Yule Zhang

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <typename T>
class listaPlus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void insertar(listaPlus<T>& other, int& pos) {
		if (pos == 0) {
			Nodo* nodo = other.ult;
			nodo->sig = this->prim;
			this->prim = other.prim;
		}
		else {
			Nodo* nodo = this->prim;

			for (int i = 0; i < pos - 1; i++) nodo = nodo->sig;
			Nodo* aux2 = other.ult;
			aux2->sig = nodo->sig;
			nodo->sig = other.prim;

			if (pos == this->size())	this->ult = other.ult;
		}
		this->nelems += other.nelems;
		other.prim = other.ult = nullptr;
		other.nelems = 0;
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
	if (!cin)
		return false;

	listaPlus<int> l;
	int p;
	for (int i = 0; i < numElem; ++i) {
		cin >> p;
		l.push(p);
	}
	int m, pos;
	cin >> m >> pos;
	listaPlus<int>other;

	for (int j = 0; j < m; j++) {
		cin >> p;
		other.push(p);
	}
	l.insertar(other, pos);
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
