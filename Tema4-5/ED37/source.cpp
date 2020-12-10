#include <set>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

using profesor = string;
using alumno = string;

class autoEscuela {
	//para cada alumno, el profesor con el que esta matriculado y la puntuacion
	unordered_map<alumno, pair<int, profesor>> alumnos;

	//para cada profesor, el conjunto de alumnos que estan matriculados con el
	unordered_map<profesor, set<alumno>> profesores;

public:
	//El coste es del O(logA), siendo A es el numero de alumnos
	void alta(alumno const& a, profesor const& p) {
		auto itA = alumnos.find(a);
		if(itA == alumnos.end()){//si el alumno no estaba
			alumnos.insert({ 0, {0, p} });
			profesores[p].insert(a);//O(logA)
		}
		else {//si estaba
			profesores[itA->second.second].erase(a);//O(logA)
			itA->second.second = p;
			profesores[p].insert(a);
		}
	}

	//O(1), consulta a un diccionario no ordenado
	bool es_alumno(alumno const& a, profesor const& p) {
		auto itA = alumnos.find(a);
		return itA != alumnos.end() && itA->second.second == p;
	}

	//O(1), consulta a un diccionario no ordenado
	int puntuacion(alumno const& a) {
		auto itA = alumnos.find(a);
		if (itA == alumnos.end())
			throw domain_error("El alumno " + a + " no esta matriculado");
		else
			return itA->second.first;
	}

	//O(1), consulta y modificacion en un diccionario no ordenado
	void actualizar(alumno const& a, int puntos) {
		auto itA = alumnos.find(a);
		if (itA == alumnos.end())
			throw domain_error("El alumno " + a + " no esta matriculado");
		else
			itA->second.first += puntos;
	}

	//Coste lineal en el numero de alumnos, O(A), por el recorrido del conjunto asociado al profesor
	//Las consultas en el diccionario de alumnos para saber si la puntuacion de cada uno son del coste constante
	vector<alumno> examen(profesor const& p, int puntos) const{
		vector<alumno> res;
		auto itP = profesores.find(p);
		if (itP != profesores.end()) {
			for (alumno const& a : itP->second)
				if (alumnos.at(a).first >= puntos)
					res.push_back(a);
		}
		return res;
	}

	//O(logA) siendo A es el numero de alumnos, porque hay que borrarlo del conjunto asociado a su profesor
	void aprobar(alumno const& a) {
		auto itA = alumnos.find(a);//O(1)
		if (itA == alumnos.end())
			throw domain_error("El alumno " + a + " no esta matriculado");
		else {
			profesores[itA->second.second].erase(a);//O(logA)
			alumnos.erase(itA);//O(1)
		}
	}

};