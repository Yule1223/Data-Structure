
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "treemap_eda.h"
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;//FIN DE ENTRADA
	string s;
	getline(cin, s);//Para saltar a la siguiente linea
	map<string, int> m;
	string clave;
	string valor;
	int num;

	for (int i = 0; i < n; i++) {
		getline(cin, clave);
		getline(cin, valor);

		if (valor == "CORRECTO")
			++m[clave];
		else
			--m[clave];

	}

	// escribir sol
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		if (itr->valor != 0)
			cout << itr->clave << ", " << itr->valor << endl;
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

	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
