
// Yule Zhang

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stack_eda.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	stack<char> pila;
	bool enc = true;
	string s;
	// leer los datos de la entrada
	getline(cin, s);
	if (!std::cin)  // fin de la entrada
		return false;
	for (auto i = 0; i < s.size() && enc; i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')
			pila.push(s[i]);
		else if ((s[i] == ']' || s[i] == '}' || s[i] == ')') && pila.empty())
			enc = false;
		else if (s[i] == ']') {
			if (pila.top() == '[')
				pila.pop();
			else enc = false;
		}
		else if (s[i] == '}') {
			if (pila.top() == '{')
				pila.pop();
			else enc = false;
		}
		else if (s[i] == ')') {
			if (pila.top() == '(')
				pila.pop();
			else enc = false;
		}
	}
	if (!pila.empty())
		enc = false;
	// escribir sol
	if (enc)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
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
