
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int becarios(int k) {
	int raiz;
	cin >> raiz;
	if (raiz == 0) {
		return (k <= 0);
	}
	else {
		int res = 0;
		for (int i = 0; i < raiz; i++)
			res += becarios(k - 1);
		return res;
	}
}

bool resuelveCaso() {
	int k;
	cin >> k;
	if (!cin)
		return false;
	int n = becarios(k);

	// escribir sol
	cout << n << endl;
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
