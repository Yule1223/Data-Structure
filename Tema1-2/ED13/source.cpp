
// Yule Zhang

#include <iostream>
#include <fstream>
using namespace std;

#include "deque_eda.h"

template <typename T>
class listaPlus : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
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
	int n , num;
	cin >> n;//Leer datos de entrada
	if (n == 0)
		return false;

	listaPlus<int> l;
	cin >> num;
	l.push_back(num);
	for (int i = 1; i < n;i++) {
		cin >> num;
		if (num > 0)
			l.push_back(num);
		else
			l.push_front(num);

	}

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
