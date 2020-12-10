
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int calcularAltura(int k) {
	int raiz;
	cin >> raiz;
	if (raiz == 0)
		return k;
	else {
		int res = 0;
		int altura = 0;
		for (int i = 0; i < raiz; i++) {
			altura = calcularAltura(k + 1);
			if (res < altura)
				res = altura;
		}

		return res;
	}
}

void resuelveCaso() {

	int altura = calcularAltura(1);

	// escribir solución
	cout << altura << endl;
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
