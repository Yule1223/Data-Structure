//
//  stack_eda.h
//
//  Implementaci¨®n del TAD pila con array din¨¢mico
//
//  Estructuras de Datos
//  Facultad de Inform¨¢tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef stack_eda_h
#define stack_eda_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <class T>
class stack {
protected:
    static const int TAM_INICIAL = 10; // tama?o inicial del array din¨¢mico

    // n¨²mero de elementos en la pila
    int nelems;

    // tama?o del array
    int capacidad;

    // puntero al array que contiene los datos (redimensionable)
    T* array;

public:

    // constructor: pila vac¨ªa
    stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

    // destructor
    ~stack() {
        libera();
    }

    // constructor por copia
    stack(stack<T> const& other) {
        copia(other);
    }

    // operador de asignaci¨®n
    stack<T>& operator=(stack<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // apilar un elemento
    void push(T const& elem) {
        array[nelems] = elem;
        ++nelems;
        if (nelems == capacidad)
            amplia();
    }

    // consultar la cima
    T const& top() const {
        if (empty())
            throw std::domain_error("la pila vacia no tiene cima");
        return array[nelems - 1];
    }

    // desapilar el elemento en la cima
    void pop() {
        if (empty())
            throw std::domain_error("desapilando de la pila vacia");
        --nelems;
    }

    // consultar si la pila est¨¢ vac¨ªa
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tama?o de la pila
    int size() const {
        return nelems;
    }

protected:

    void libera() {
        delete[] array;
    }

    // this est¨¢ sin inicializar
    void copia(stack const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia() {
        T* viejo = array;
        capacidad *= 2;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }
};

#endif // stack_eda_h