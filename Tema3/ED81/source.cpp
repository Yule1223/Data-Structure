
// Nombre y Apellidos

// Comentario general sobre la soluci¨®n,
// explicando c¨®mo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase
using namespace std;

bool esSimetrico(bintree<char>const& left, bintree<char>const& right) {
    if (left.empty() && right.empty())
        return true;
    if ((left.empty() && !right.empty()) || !left.empty() && right.empty())
        return false;
    return esSimetrico(left.right(), right.left()) && esSimetrico(left.left(), right.right());
}

bool esSimetrico(bintree<char>const& arbol) {
    return esSimetrico(arbol.left(), arbol.right());
}

void resuelveCaso() {
    // leer los datos de la entrada
    auto arbol = leerArbol('.');
   
    bool simetrico = esSimetrico(arbol);
    // escribir soluci¨®n
    if (simetrico)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
