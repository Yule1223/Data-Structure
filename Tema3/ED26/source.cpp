
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "bintree_eda.h"// propios o los de las estructuras de datos de clase
using namespace std;

struct sol {
	bool ok;
	int min, max;
};


sol esArbolBinario(bintree<int> const& arbol) {
	sol s;
	if (arbol.empty())
		s.ok = true;
	else {
		sol iz = esArbolBinario(arbol.left());
		sol dr = esArbolBinario(arbol.right());

		if (!arbol.left().empty())
			s.min = iz.min;
		else
			s.min = arbol.root();
		if (!arbol.right().empty())
			s.max = dr.max;
		else
			s.max = arbol.root();

		bool ordenado = (arbol.left().empty() || iz.max < arbol.root()) && (arbol.right().empty() || dr.min > arbol.root());
		s.ok = iz.ok && dr.ok && ordenado;
	}
	return s;
}

bool esBinario(bintree<int>const& arbol) {
	return esArbolBinario(arbol).ok;
}

void resuelveCaso() {
	auto arbol = leerArbol(-1);

	// escribir solución
	if (esBinario(arbol))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
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
