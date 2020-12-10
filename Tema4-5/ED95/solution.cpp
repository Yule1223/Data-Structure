
// solución de ALBERTO VERDEJO

/*
 
 Para guardar la información sobre los avisos de forma que podamos
 contestar a las preguntas eficientemente, utilizamos un diccionario
 no ordenado (ya que no vamos a necesitar recorrer las claves en
 orden), donde las claves son los nombres de los sensores que han
 enviado algún aviso, y a cada sensor se le asocia un vector con
 los momentos en los que ha avisado, del más antiguo al más reciente.
 
 Para contestar a la pregunta <sensor, k> buscamos el sensor en el
 diccionario. Si no está o el tamaño del vector asociado es menor
 que k, entonces no se ha producido tal aviso. En caso contrario,
 la respuesta a la pregunta es la hora que se encuentra en la
 posición k-1 de ese vector.
 
 Ya que las operaciones utilizadas del diccionario y de los vectores
 tienen coste constante, la construcción del diccionario a partir
 de la entrada tiene coste O(N), donde N es el número de avisos,
 y conseguir la respuesta a las M preguntas tiene coste O(M), por lo
 que el coste total del algoritmo es O(N + M).
 
 */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

bool resuelveCaso() {
   int N, M; // número de avisos y de preguntas
   cin >> N >> M;
   if (!cin)
      return false;
   
   unordered_map<string, vector<string>> avisos; // < sensor, vector<horas> >
   
   // leemos los avisos y guardamos la información en el diccionario
   string sensor, hora;
   for (int i = 0; i < N; ++i) {
      cin >> sensor >> hora;
      avisos[sensor].push_back(hora);
   }
   
   // leemos y contestamos a las preguntas
   int k;
   for (int i = 0; i < M; ++i) {
      cin >> sensor >> k;
      if (i) cout << ' ';
      auto it = avisos.find(sensor);
      if (it == avisos.end() || it->second.size() < k)
         cout << "--";
      else
         cout << it->second[k-1];
   }
   cout << '\n';
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
} // main
