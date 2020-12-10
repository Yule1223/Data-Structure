
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

bintree<int> reconstruccion(vector<int>const& pre, int preStart, int preEnd) {
	if (preStart > preEnd)
		return {};
	bintree<int> Iz;
	bintree<int> Dr;

	int i;
	for (i = preStart + 1; i <= preEnd; i++) {
		if (pre[i] > pre[preStart])
			break;//i = comienzo del hijo derecho
	}
	Iz = reconstruccion(pre, preStart + 1, i - 1);
	Dr = reconstruccion(pre, i, preEnd);

	bintree<int> arbol(Iz, pre[preStart], Dr);
	return arbol;
}

bool resuelveCaso() {
	string linea;
	int valor;
	vector<int> pre;
	getline(cin, linea);
	stringstream ss(linea);
	if (!std::cin)  // fin de la entrada
		return false;
	while (ss >> valor) {
		pre.push_back(valor);
	}
	auto arbol = reconstruccion(pre, 0, pre.size() - 1);
	auto v = arbol.postorder();

	// escribir sol
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
