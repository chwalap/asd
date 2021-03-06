#include "CountConsistenComponents.h"

using namespace std;

unsigned int CountConsistentComponents(const Graph<bool> &G) {
	if (G.getNumberOfVertices() == 0) {
		cerr << "Graph is empty!" << endl;
		return 0;
	}

	int numberOfConsistentComponents = 0;

	map <Vertex, Color> color;
	for (Vertex V : G.getVertices()) {
		color[V] = Color::BLUE; // all vertices not visited yet
	}

	for (Vertex V : G.getVertices()) {
		if (color[V] == Color::BLUE) { // jeszcze nie odwiedzony
			color[V] = Color::RED; // odwiedzony

			// zaczynajac od tego wierzcholka kolorujemy pozostale
			queue <Vertex> Q; // kolejka
			Q.push(V);

			// dopoki kolejka nie jest pusta
			while (!Q.empty()) {
				// bierzemy pierwszego wierzcholka
				Vertex V = Q.front();
				Q.pop();

				// po wszystkich sasiadach
				for (auto N : G.getNeighbours(V)) {
					if (color[N.first] == Color::BLUE) { // jesli jeszcze nieodwiedzony
						color[N.first] = Color::RED; // odwiedzony
						Q.push(N.first); // dodanie do kolejki
					}
				}
			}

			// po pokolorowaniu wszystkich wierzcholkow (posrednio albo bezposrednio) polaczonych z wierzcholkiem V
			numberOfConsistentComponents++;
		}
	}

	return numberOfConsistentComponents;
}
