// NOMBRES Y APELLIDOS
// Yule Zhang E81
// David García Sanchez E30

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include "bintree_eda.h"
bool esPar(bintree<int>const& arbol) {
	if (arbol.empty())
		return true;
	return arbol.root() % 2 == 0;
}

int caminoPares(bintree<int>const& arbol, int& n) {
	if (arbol.empty()) {
		return 0;
	}
	int nI = 0, nD = 0;
	int left = caminoPares(arbol.left(), nI);
	int right = caminoPares(arbol.right(), nD);
	if (!esPar(arbol.left()))
		nI = 0;
	if (!esPar(arbol.right()))
		nD = 0;
	if (!esPar(arbol)) {
		n = max(nI, nD);
		return max(max(nI, nD), max(left, right));
	}
	else {
		n = 1 + max(nI, nD);
		return max(1 + nI + nD, max(left, right));
	}

}

void resuelveCaso() {
	int n;
	bintree<int> arbol = leerArbol(-1);
	cout << caminoPares(arbol, n) << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}