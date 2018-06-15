#include "IsBipartiteGraph.h"

using namespace std;

bool IsBipartiteGraph(const Graph<bool> &G) {
	if (G.getNumberOfVertices() == 0) {
		cerr << "Graph is empty!" << endl;
		return false;
	}

	queue <Vertex> Q; // kolejka
	Q.push(Vertex(0u)); // always first vertex
	vector <Color> color(G.getNumberOfVertices(), Color::BLUE); // all vertices not visited yet

	Color C = Color::RED;
	color[0] = C;

	while (!Q.empty()) { // dopoki kolejka nie jest pusta
						 // bierzemy pierwszy wierzcholek z kolejki
		Vertex V = Q.front();
		Q.pop();

		// zmianiamy kolor
		C = (color[V] == Color::RED ? Color::GREEN : Color::RED);

		//cout << "Jestem w wierzcholku: " << V << endl;

		// dla jego kazdego sasiada
		for (auto N : G.getNeighbours(V)) {
			if (color[N.first] == Color::BLUE) { // jesli jeszcze nie odwiedzilismy wierzcholka to dodajemy go do kolejki
				color[N.first] = C; // kolorujemy na inny kolor niz obecny
				Q.push(N.first); // dodajemy do kolejki
			}
		}
	}

	// sprawdzanie dwudzielnosci
	for (Vertex V : G.getVertices()) {
		if (color[V] == Color::BLUE) // jesli wierzcholek nie byl odwiedzony to graf nie moze byc dwudzielny
			return false;

		for (auto N : G.getNeighbours(V)) {
			if (color[V] == color[N.first]) { // jesli wierzcholek ma taki sam kolor jak jakikolwiek jego sasiad to graf nie jest dwudzielny
				cerr << V << " i " << N.first << " maja takie same kolory: " << color[N.first] << endl;
				return false;
			}
		}
	}

	return true;
}