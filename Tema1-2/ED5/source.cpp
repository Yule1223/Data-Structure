
// Yule Zhang

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include "set.h"  // propios o los de las estructuras de datos de clase

using namespace std;

bool resuelveCaso() {
	char c;
	int k;
	// leer los datos de la entrada
	cin >> c >> k;
	if (!std::cin)  // fin de la entrada
		return false;
	if (c == 'N') {
		set<int>v;
		int n;
		cin >> n;
		while (n != -1) {
			v.insert(n);
			if(v.size() > k)
				v.borrar();
			cin >> n;
		}
		v.print();
	}
	else {
		set<string>s;
		string s1;
		cin >> s1;
		while (s1 != "FIN") {
			s.insert(s1);
			if (s.size() > k)
				s.borrar();
			cin >> s1;
		}
		s.print();
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
