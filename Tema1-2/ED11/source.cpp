
// Yule Zhang

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <typename T>
class listaPlus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void mezclar(listaPlus<T> & l1, listaPlus<T> & l2) {
		if (l1.nelems == 0) {//Si l1 es vacia
			this->prim = l2.prim;
			this->ult = l2.ult;
		}
		else if (l2.nelems == 0) {//Si l2 es vacia
			this->prim = l1.prim;
			this->ult = l1.ult;
		}
		else {//Si ni l1 ni l2 son vacias
			Nodo* nodo1 = l1.prim;
			Nodo* nodo2 = l2.prim;
			if (nodo1->elem <= nodo2->elem) {
				this->prim = nodo1;
				nodo1 = nodo1->sig;
			}
			else {
				this->prim = nodo2;
				nodo2 = nodo2->sig;
			}
			Nodo* nodo = this->prim;
			while (nodo1 != nullptr && nodo2 != nullptr) {
				if (nodo1->elem <= nodo2->elem) {
					nodo->sig = nodo1;
					nodo1 = nodo1->sig;
					nodo = nodo->sig;
				}
				else {
					nodo->sig = nodo2;
					nodo2 = nodo2->sig;
					nodo = nodo->sig;
				}
			}
			while (nodo1 != nullptr) {
				nodo->sig = nodo1;
				nodo1 = nodo1->sig;
				nodo = nodo->sig;
			}
			while (nodo2 != nullptr) {
				nodo->sig = nodo2;
				nodo2 = nodo2->sig;
				nodo = nodo->sig;
			}
		}
		this->nelems = l1.nelems + l2.nelems;
		l1.prim = l1.ult = nullptr;
		l2.prim = l2.ult = nullptr;
		l1.nelems = l2.nelems = 0;
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



void resuelveCaso() {
	int n;
	cin >> n;//Leer datos de entrada

	listaPlus<int> l1;//Primera lista
	listaPlus<int> l2;//Segunda lista

	while (n != 0) {
		l1.push(n);
		cin >> n;
	}

	int m;
	cin >> m;
	while (m != 0) {
		l2.push(m);
		cin >> m;
	}

	listaPlus<int> l;//Lista final
	l.mezclar(l1, l2);
	l.print();
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
