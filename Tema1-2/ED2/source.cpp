// Nombre y Apellidos
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>// propios o los de las estructuras de datos de clase
#include <string>

using namespace std;

#include "pelicula.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nCasos;
	// leer los datos de la entrada
	cin >> nCasos;
	if (nCasos == 0)
		return false;

	vector<peliculas>p(nCasos);

	for (auto i = 0; i < nCasos; i++) {
		horas h1;
		horas h2;
		horas h;
		cin >> h1 >> h2;
		h1.operator+(h2);
		p[i].time = h1;

		string str;
		getline(cin, str);
		p[i].name = str;
	}

	sort(p.begin(), p.end());

	// escribir sol
	for (auto i = 0; i < nCasos; i++) {
		cout << p[i].time << " " << p[i].name << endl;
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
