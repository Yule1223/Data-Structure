
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "stack_eda.h"  // propios o los de las estructuras de datos de clase
using namespace std;

struct entrada {
	string s;
	int victima;
};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	stack<entrada> aux;
	stack<entrada> pila;
	entrada e;
	int n;

	// leer los datos de la entrada
	cin >> n;//numero de casos
	if (!std::cin)  // fin de la entrada
		return false;

	for (int i = 0; i < n; i++) {
		bool enc = false;
		cin >> e.s >> e.victima;

		while (!enc && !pila.empty()) {
			if (pila.top().victima > e.victima) {
				cout << pila.top().s << endl;
				enc = true;
			}
			else {
				pila.pop();
			}
		}
		if (!enc)
			cout << "NO HAY" << endl;
		pila.push(e);
	}
	cout << "---" << endl;
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
