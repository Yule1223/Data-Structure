#include <list>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

using cancion = string;
using artista = string;

class iPud {
	struct infoSong {
		artista autor;
		int duracion;
		list<cancion>::iterator enPlaylist;
		list<cancion>::iterator enRecientes;
	};

	unordered_map<cancion, infoSong> canciones;

	list<cancion> playlist;
	int duracionPlaylist;
	list<cancion> recientes;//ordena de mas reciente al menos

public:
	//int no se inicializan por defecto, las listas y diccionarios si
	iPud() : duracionPlaylist(0){}

	void addSong(cancion S, artista A, int D) {//O(1)
		if (!canciones.insert({ S, {A, D, playlist.end(), recientes.end()} }).second)//insesrt.second del diccionario devuelve bool
			throw invalid_argument("addSong");
	}

	void addToPlaylist(cancion S) {//O(1)
		auto itS = canciones.find(S);
		if (itS == canciones.end())
			throw invalid_argument("addToPlaylist");
		infoSong& info = itS->second;
		if (info.enPlaylist == playlist.end()) {
			info.enPlaylist = playlist.insert(playlist.end(), S);//devuelve el iterator
			duracionPlaylist += info.duracion;
		}
	}

	cancion current() const {//O(1)
		if (playlist.empty())
			throw invalid_argument("current");
		return playlist.front();
	}

	void play() {//O(1)
		if (!playlist.empty()) {
			//se extrae la primera cancion
			string tocando = playlist.front();
			playlist.pop_front();
			//recuperamos la informacion de la cancion y la actualizamos
			infoSong& info = canciones[tocando];
			//deja de estar en el playlist
			info.enPlaylist = playlist.end();
			//se descuenta la duracion de la lista
			duracionPlaylist -= info.duracion;
			//si estaba entre las recientes, se elimina
			if (info.enRecientes != recientes.end()) {
				recientes.erase(info.enRecientes);
			}
			//se anade al comienzo de las recientes
			info.enRecientes = recientes.insert(recientes.begin(), tocando);
		}
	}

	int totalTime() {//O(1)
		return duracionPlaylist;
	}

	list<cancion> recent(int N) {//O(N)
		list<cancion> res;
		for (cancion const& c : recientes) {
			res.push_back(c);
			if (res.size() == N) break;
		}
		return res;
	}

	void deleteSong(cancion S) {//O(1)
		auto itS = canciones.find(S);
		if (itS != canciones.end()) {
			infoSong& info = itS->second;
			//si esta en la playlist se elimina
			if (info.enPlaylist != playlist.end()) {
				playlist.erase(info.enPlaylist);
				duracionPlaylist -= info.duracion;
			}
			//si habia sido reproducida, se elimina de las recientes
			if (info.enRecientes != recientes.end()) {
				recientes.erase(info.enRecientes);
			}
			canciones.erase(itS);
		}
	}

};