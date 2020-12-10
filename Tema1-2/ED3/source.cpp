
// YULE ZHANG

// Comentario general sobre la soluci¨®n,
// explicando c¨®mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>  // invalid_argument
#include "complejo.h"  // propios o los de las estructuras de datos de clase

using namespace std;

void resuelveCaso() {
    float real, imaginaria;
    int numIter;
    // leer los datos de la entrada
    cin >> real >> imaginaria >> numIter;
    if (numIter < 100 || numIter > 500)
        throw domain_error("Numero incorrecto");
    complejo c(real, imaginaria);
    complejo z(0,0);
    bool stop = false;
    for (int i = 0; i < numIter && !stop;i++) {
        z.operator*(z);
        z.operator+(c);
        
        auto res = z.mod();
        if (res > 2.0)
            stop = true;
    }
   // cout << res << '\n';
    // escribir soluci¨®n
    if (!stop)
        cout << "SI\n";
    else
        cout << "NO\n";
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
