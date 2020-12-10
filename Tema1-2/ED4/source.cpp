
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "polinomio.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	polinomio p;
	int coe;
	int expo;
	int nCasos = 0;

	// leer los datos de la entrada
	cin >> coe >> expo;
	if (!std::cin)  // fin de la entrada
		return false;

	while (!(coe == 0 && expo == 0)) {
		p.add(coe, expo);
		cin >> coe >> expo;
	}

	cin >> nCasos;
	int x;

	for (int i = 0; i < nCasos; i++) {
		cin >> x;
		// escribir sol
		cout << p.evaluar(x) << " ";
	}
	cout << endl;

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
