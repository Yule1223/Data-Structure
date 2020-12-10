
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	char tipo;
	// leer los datos de la entrada
	cin >> tipo;
	if (!std::cin)  // fin de la entrada
		return false;
	if (tipo == 'N') {
		auto arbol = leerArbol(-1);
		auto min = arbol.minElem();
		cout << min << endl;
	}

	else {
		auto arbol = leerArbol(string("#"));
		auto min = arbol.minElem();
		cout << min << endl;
	}

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
