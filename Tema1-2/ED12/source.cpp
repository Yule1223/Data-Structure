
// Yule Zhang

#include <iostream>
#include <fstream>
using namespace std;

#include "deque_eda.h"

template <typename T>
class listaPlus : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void elegir(int salto) {
		Nodo* nodo = this->fantasma->sig;

		while (this->nelems > 1) {
			for (int i = 0; i < salto;i++) {
				nodo = nodo->sig;
				if (nodo == this->fantasma)
					nodo = nodo->sig;
			}
			//cout << nodo->elem << endl;
			
			nodo->ant->sig = nodo->sig;
			nodo->sig->ant = nodo->ant;
			nodo = nodo->sig;
			if (nodo == this->fantasma)
				nodo = nodo->sig;
			this->nelems--;

			//print();
		}


	}

	void print() {
		Nodo* start = this->fantasma->sig;
		while (start != this->fantasma) {
			cout << start->elem << " ";
			start = start->sig;
		}
		cout << endl;
	}
};



bool resuelveCaso() {
	int n, salto;
	cin >> n >> salto;//Leer datos de entrada
	if (n == 0 && salto == 0)
		return false;

	listaPlus<int> l;

	for (int i = 1; i <= n;i++) {
		l.push_back(i);
	}

	l.elegir(salto);
	cout << l.front() << endl;
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
