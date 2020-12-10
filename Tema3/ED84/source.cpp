
// Nombre y Apellidos

// Comentario general sobre la soluci¨®n,
// explicando c¨®mo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"  // propios o los de las estructuras de datos de clase
using namespace std;

//El primer int de pair significa la altura del hijo izquierdo
//El segundo int de pair significa la altura del hijo derecho
//Si los dos valen -1 significa que es NADA


pair<int, int> esComplete(bintree<char>const & arbol, int depth) {
    if (!arbol.left().empty() && !arbol.right().empty()) {
        pair<int, int> left = esComplete(arbol.left(), depth + 1);
        pair<int, int> right = esComplete(arbol.right(), depth + 1);

        if (left.first != -1 && left.second != -1 && right.first != -1 && right.second != -1)//Si no es caso NADA
            if (left.first == right.first && left.first == left.second)
                return right; //Caso Semicompleto
            else if (left.first == left.second && right.first == right.second && left.first - right.first == 1)
                return pair<int, int>(left.first, right.first);//caso Semicompleto
            else if (left.first - left.second == 1 && left.second == right.first && right.first == right.second)
                return left;//Caso Semicompleto
            else
                return pair<int, int>(-1, -1);//Caso NADA
        else
            return pair<int, int>(-1, -1);//Caso NADA
    }

    else if (!arbol.left().empty() && arbol.right().empty()) {
        if (arbol.left().right().empty() && arbol.left().left().empty())
            return pair<int, int>(depth + 1, depth); //caso Completo
        else
            return pair<int, int>(-1, -1); // caso NADA
    }

    else if (arbol.left().empty()&& arbol.right().empty())
        return pair<int, int>(depth, depth);

    //Si hijo izquierdo es null y hijo derecho no lo es, en este caso es NADA
    return pair<int, int>(-1, -1); 
}

void resuelveCaso() {
    // leer los datos de la entrada
    auto arbol = leerArbol('.');
    int depth = 1;

    auto sol = esComplete(arbol, depth);
    // escribir soluci¨®n
    if (sol.first == -1 && sol.second == -1)
        cout << "NADA" << endl;
    else if (sol.first - sol.second == 0)
        cout << "COMPLETO" << endl;
    else if (sol.first - sol.second == 1)
        cout << "SEMICOMPLETO" << endl;
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
