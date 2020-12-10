
#ifndef PELICULAS_H
#define PELICULAS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <string>
#include <algorithm>

#include "horas.h"

using namespace std;

class peliculas {
private:
	string nombre;
	horas h;
public:
	// constructora
	peliculas() {}

	// observadoras
	horas time{};
	string name{};

	// operador de comparación
	bool operator<(peliculas const& p) const {
		return time < p.time || (time == p.time && name < p.name);
	}

};

#endif