#include "HasCycle.h"

using namespace std;

bool findCycle(const Graph<bool> &G, Vertex Start, Vertex Current, stack<Vertex> &S, vector<Color> &color);

bool HasCycle(const Graph<bool> &G) {
	if (G.getNumberOfVertices() == 0) {
		cerr << "Graph is empty!" << endl;
		return false;
	}

	for (Vertex V : G.getVertices()) { // dla kazdego wierzcholka szukamy po kolei cyklu
		stack <Vertex> S; // stos z cyklem
		vector <Color> color(G.getNumberOfVertices(), Color::BLUE); // odwiedzone wierzcholki

		if (findCycle(G, V, V, S, color)) { // szukamy cyklu rekurencyjnie
			/*while (!S.empty()) { cout << S.top() << ", "; S.pop(); } // wypisujemy cykl
			cout << endl;*/
			return true;
		}
	}

	return false;
}

bool findCycle(const Graph<bool> &G, Vertex Start, Vertex Current, stack<Vertex> &S, vector<Color> &color) {
	color[Current] = Color::RED; // odwiedzamy obecny wierzcholek

	for (auto U : G.getNeighbours(Current)) {
		// dla grafu nieskierowanego, zeby nie wracac do poprzedniego
		if (!S.empty() && U.first == S.top()) continue;

		// dodajemy obecny wierzcholek na stos cyklu
		S.push(Current);

		// jesli to wierzcholek startowy to mamy cykl
		if (U.first == Start) return true;

		if (color[U.first] == Color::BLUE) { // jesli nie byl odwiedzony
			if (findCycle(G, Start, U.first, S, color)) { // szukamy cyklu
				return true;
			}
		}
		S.pop(); // usuwamy wierzcholek ze sciezki cyklu
	}
	return false;
}