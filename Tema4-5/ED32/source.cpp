
// Yule Zhang

// Comentario general sobre la soluci¨®n,
// explicando c¨®mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    string deporte, estudiante;
    cin >> deporte;
    if (!cin)
        return false;
    //para cada deporte, conjunto de alumnos apuntados
    unordered_map<string, unordered_set<string>> deportes;
    //para cada alumno, en que deporte esta apuntado(por primera vez)
    unordered_map<string, string> estudiantes;

    deportes.insert({ deporte, {} });//nuevo deporte

    while (cin >> estudiante && estudiante != "_FIN_") {
        if (isupper(estudiante[0])) {//otro deporte
            deporte = estudiante;
            deportes.insert({ deporte, {} });
        }
        else {//Si es estudiante
            auto [it, nuevo] = estudiantes.insert({ estudiante,deporte });
            if (nuevo)//Se ha insertado con exito
                deportes[deporte].insert(estudiante);
            else{//Si se habia insertado, fue en otro deporte?
                if (it->second != deporte)
                    deportes[it->second].erase(estudiante);
            }
        }
    }

    //Pasamos la informacion de los deportes a un vector para ordenar
    vector<pair<string, int>> resumen;//<deporte, numero de apuntados>
    for (auto const& [dep, estuds] : deportes)
        resumen.push_back({ dep, estuds.size() });

    //Ordenamos teniendo en cuenta el numero de apuntados a cada equipo
    sort(resumen.begin(), resumen.end(), [](pair<string, int>const& a, pair<string, int>const& b) {
        return (a.second > b.second || (a.second == b.second && a.first < b.first));
    });

    // escribir sol
    for (auto par : resumen) {
        cout << par.first << " " << par.second << endl;
    }
    cout << "---" << endl;
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
