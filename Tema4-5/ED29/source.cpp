
// Yule Zhang

// El coste es del orden(N) siendo n es el numero de capitulos
// Porque los accesos al diccionario es del coste constante y el resto de cosas que hacemos tb

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm> 
#include <unordered_map>
using namespace std;

void resuelveCaso() {
	int n;//Numero de capitulos emitidos de cada serie
	cin >> n;
	int valor;//Entrada
	unordered_map<int, int>map;
	auto maximo = 0;//Salida
	int p = 0;//Posicion donde empieza el ultimo tramo sin repeticiones

	for (int i = 0; i < n; i++) {
		cin >> valor;
		//Si el valor ya ha parecido y despues del ultimo comienzo del tramo
		if (map.count(valor) && map[valor] >= p)//Rompe el ultimo tramo
			p = map[valor] + 1;
		maximo = max(maximo, i - p + 1);
		map[valor] = i;//El capitulo se ha metido por la ultima vez en el momento i
	}
	// escribir sol
	cout << maximo << endl;
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
