#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

class polinomio {
private:
	vector<vector<int>>v;
	int cont = 0;//contador
public:
	//constructura
	polinomio() {}

	// observadoras

	// operador de comparación


	//metodos
	//metodo para anadir un monomio al polinomio

	void add(int c, int e) {
		bool enc = false;//Si exponente ya existe en el vector
		for (int i = 0; i < cont; i++) {
			if (e == v[i][0]) {
				v[i][1] += c;
				enc = true;
			}
		}
		if (!enc) {
			vector<int>m(2);
			v.push_back(m);

			v[cont][0] = e;
			v[cont][1] = c;
			sort(v.begin(), v.end());
			cont++;
		}
	}

	//metodo para evaluar el polinomio
	int evaluar(int valor) {
		int suma = 0;
		for (int i = 0; i < cont; i++) {
			suma += (v[i][1] * pow(valor, v[i][0]));
		}
		return suma;
	}
};

#endif