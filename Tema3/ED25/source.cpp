
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"// propios o los de las estructuras de datos de clase
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool esPrimo(int num) {
	if (num == 0 || num == 1 || num == 4) return false;
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void barrera(bintree<int>const& arbol, int& elem, int& depth, int& depthAct) {
	if (!arbol.empty() && !esPrimo(arbol.root())) {
		depthAct++;
		if (arbol.root() % 7 == 0 && (depthAct < depth || depth == 0)) {
			elem = arbol.root();
			depth = depthAct;
		}
		else {
			barrera(arbol.left(), elem, depth, depthAct);
			barrera(arbol.right(), elem, depth, depthAct);
		}
		depthAct--;
	}
}

void resuelveCaso() {
	auto arbol = leerArbol(-1);
	int depth = 0;
	int depthAct = 0;
	int elem = 0;

	if (!arbol.empty() && arbol.root() < 5000 && arbol.root() > 1) {
		barrera(arbol, elem, depth, depthAct);
	}
	// escribir solución
	if (depth == 0)
		cout << "NO HAY" << endl;
	else
		cout << elem << " " << depth << endl;
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
