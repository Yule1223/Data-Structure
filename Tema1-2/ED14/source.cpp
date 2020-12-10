
// Yule Zhang

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "deque_eda.h"
#include "stack_eda.h"

bool noEsVocal(char c) {
	return c != 'a' && c != 'o' && c != 'e' && c != 'i' && c != 'u' && c != 'A' && c != 'O' && c != 'E' && c != 'I' && c != 'U';
}

bool resuelveCaso() {
	
	string s;
	getline(cin,s);//Leer datos de entrada
	if (!cin)
		return false;

	deque<char> l;
	//Segunda fase
	if (s.size() % 2 == 0) {
		for (int i = s.size() - 1; i >= 0;i -= 2) {
			l.push_back(s[i]);
			l.push_front(s[i - 1]);
		}
	}

	else {
		for (int i = s.size() - 1; i >= 0;i -= 2) {
			l.push_front(s[i]);
			if (i - 1 >= 0)
				l.push_back(s[i - 1]);
		}
	}

	//Primera fase
	string resultado;
	stack<char> pila;
	
	while (!l.empty()) {
		if (noEsVocal(l.front())) {//No es vocal se cambian
			pila.push(l.front());
			l.pop_front();
		}
		else {//Si es vocal
			while (!pila.empty()) {
				resultado.push_back(pila.top());
				pila.pop();
			}
			resultado.push_back(l.front());
			l.pop_front();
		}
	}
	while (!pila.empty()) {
		resultado.push_back(pila.top());
		pila.pop();
	}
	cout << resultado << endl;
	
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
