
#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

//template<class T> 
class complejo {
private:
	float RR;
	float II;
	bool check(float real, float imaginaria) {
		return (real >= -2.00 && real <= 2.00 && imaginaria >= -2.00 && imaginaria <= 2.00);
	}
public:
	// constructora
	complejo(float real, float imaginaria) {
		if (check(real, imaginaria)) { RR = real, II = imaginaria;}
		else throw domain_error("hora incorrecta");
	}

	// observadoras
	float real() const { return RR; }
	float imaginaria() const { return II; }

	// operador de comparacion
	void operator+(complejo const &c) {
		RR += c.RR;
		II += c.II;
	}

	void operator*(complejo const &c) {
		float R, I;
		R = RR * c.RR - II * c.II;
		I = RR * c.II + c.RR * II;
		RR = R;
		II = I;
	}

	float mod() {
		return sqrt(RR * RR + II * II);
	}
};

#endif