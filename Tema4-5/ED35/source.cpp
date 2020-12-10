#include <list>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

using DNI = string;

class carnet_puntos {
	//para cada conductor, cuantos puntos tiene y donde esta en la lista que le toca
	unordered_map<DNI, pair<int, list<DNI>::iterator>>conductores;

	//para cada numero de puntos, la lista de conductores con esos puntos
	//ordena colocando primero el que menos tiempo lleva con esos puntos
	vector<list<DNI>> por_puntos;

	//insert de list devuelve un iterator that points to the first of the newly inserted elements
	list<DNI>::iterator insertar_por_puntos(DNI c, int p) {
		auto& lista = por_puntos[p];
		return lista.insert(lista.begin(), c);
	}

public:
	carnet_puntos(): por_puntos(16){}//por_puntos es un vector [0...15]

	void nuevo(DNI conductor) {
		if (conductores.count(conductor) > 0)//Si el conductor ya existe
			throw domain_error("Conductor duplicado");
		conductores.insert({ conductor, {15, insertar_por_puntos(conductor, 15)} });
	}

	void quitar(DNI conductor, int puntos) {//O(1)
		auto it = conductores.find(conductor);
		if (it == conductores.end())
			throw domain_error("Conductor inexistente");
		auto& par = it->second;
		//par.first = puntos par.second = iterator de la lista de puntos
		if (par.first > 0 && puntos > 0) {
			por_puntos[par.first].erase(par.second);
			par.first = max(0, par.first - puntos);
			par.second = insertar_por_puntos(conductor, par.first);
		}
	}

	void recuperar(DNI conductor, int puntos) {//O(1)
		auto it = conductores.find(conductor);
		if (it == conductores.end())
			throw domain_error("Conductor inexistente");
		auto& par = it->second;
		//par.first = puntos par.second = iterator de la lista de puntos
		if (par.first < 15 && puntos > 0) {
			por_puntos[par.first].erase(par.second);
			par.first = min(15, par.first + puntos);
			par.second = insertar_por_puntos(conductor, par.first);
		}
	}

	int consultar(DNI conductor) const{
		auto it = conductores.find(conductor);
		if (it == conductores.end())
			throw domain_error("Conductor inexistente");
		return it->second.first;
	}

	int cuantos_con_puntos(int puntos) const{
		if(puntos > 15 || puntos < 0)
			throw domain_error("Puntos no validos");
		return (int)por_puntos[puntos].size(); //size() devuelve un numero sin signo
	}

	list<DNI> lista_por_puntos(int puntos) const{
		if (puntos > 15 || puntos < 0)
			throw domain_error("Puntos no validos");
		return por_puntos[puntos];
	}

};