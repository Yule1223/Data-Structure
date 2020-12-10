
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string linea;
	int valor;
	vector<int> pre;
	vector<int> in;
	getline(cin, linea);
	stringstream ss(linea);
	if (!std::cin)  // fin de la entrada
		return false;

	while (ss >> valor) {
		pre.push_back(valor);
	}

	getline(cin, linea);
	stringstream mm(linea);
	while (mm >> valor) {
		in.push_back(valor);
	}

	bintree<int> arbol;
	arbol = arbol.reconstruccion(pre, 0, pre.size() - 1, in, 0, in.size() - 1);

	// escribir sol
	auto v = arbol.postorder();
	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
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
