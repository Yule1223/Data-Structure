
// Yule Zhang

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>//Para leer las palabras de la linea
using namespace std;

//El coste es O(NlogN) siendo n es el numero de palabras

bool resuelveCaso() {
	int n;//Numero de lineas
	cin >> n;
	if (n == 0)
		return false;
	cin.ignore();//Quitar el salto de linea detras de n

	map<string, vector<int>> refs;
	//Tambien estaria bien si utilizamos set<int> pero set es del orden O(logN)
	//En este caso como el numero de linea se inserta ordenado, nos vale con comparar el numero insertado es mayor que el ultimo numero

	string linea, palabra;
	for (int i = 1; i <= n; i++) {
		getline(cin, linea);
		stringstream lin(linea);

		while (lin >> palabra) {
			if (palabra.length() > 2) {

				for (char& c : palabra) c = tolower(c);//a minusculas

				//La operacion corchete tiene coste LogN, asi no necesitamos acceder al valor cada vez
				vector<int>& apariciones = refs[palabra];

				if (apariciones.empty() || apariciones.back() != i)
					apariciones.push_back(i);
			}
		}
	}
	// escribir sol
	for (auto cv : refs) {
		cout << cv.first;
		for (auto numlin : cv.second) {
			cout << " " << numlin;
		}
		cout << endl;
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
