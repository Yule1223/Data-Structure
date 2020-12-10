#include <stdexcept> // std::domain_error 
#include <utility> // std::move
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

template <class T>
class set {
public:
	set(); // constructor 
	~set(); // destructor
	void insert(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	int size() const;
	void borrar();
	void print() const;
private:
	int contador;
	int capacidad;
	T* datos; // sin repeticiones 
	T consultar() const;
	void amplia();
};
template <class T>
set<T>::set() : contador(0), capacidad(8), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() { delete[] datos; }

template <class T>
void set<T>::insert(T e) {
	if (!contains(e)) {
		if (contador == capacidad)
			amplia();
		datos[contador] = e;
		++contador;
	}
}

template <class T>
bool set<T>::contains(T e) const {
	int i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}

template <class T>
void set<T>::amplia() {
	T* nuevos = new T[2 * capacidad];
	for (int i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	int i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta"); 
}

template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
int set<T>::size() const {
	return contador;
}

template<class T>
//Consultar el menor elemento
T set<T>::consultar() const {
	T menor;
	menor = datos[0];
	for (int i = 1; i < contador; i++) {
		if (datos[i] < menor)
			menor = datos[i];
	}
	return menor;
}

template<class T>
void set<T>::borrar() {
	T menor = consultar();
	erase(menor);
}

template<class T>
void set<T>::print() const {
	sort(datos, datos + contador);
	for (int i = 0; i < contador-1;i++) {
		cout << datos[i] << " ";
	}
	cout << datos[contador - 1] << '\n';
}
