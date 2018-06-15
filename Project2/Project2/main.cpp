#include <iostream>

#include "Graph.h"
#include "IsBipartiteGraph.h"
#include "CountConsistenComponents.h"
#include "HasCycle.h"
#include "GraphRank.h"
#include "MinClingTree.h"

using namespace std;

int main() {
	Graph <bool> G;
	for (Vertex i = 0u; i < 8u; ++i)
		G.addVertex(i);

	G.addEdge(0, 4, true);
	G.addEdge(0, 3, true);
	G.addEdge(1, 4, true);
	G.addEdge(2, 3, true);
	
	G.addEdge(4, 2, true); // wyzszy stopien grafu (4)
	G.addEdge(4, 3, true);
	
	G.addEdge(1, 2, true); // jest cykl albo go nie ma

	G.addEdge(5, 6, true); // dwie spojne skladowe + trzecia sam wierzcholek 7

	cout << "Graf G z " << G.getNumberOfVertices() << " wierzcholkami i " << G.getNumerOfEdges() << " krawedziami" << endl;
	cout << "Graf G " << (IsBipartiteGraph(G) ? "jest" : "nie jest") << " dwudzielny" << endl;
	cout << "Graf G ma " << CountConsistentComponents(G) << " spojnych skladowych" << endl;
	cout << "Graf G " << (HasCycle(G) ? "ma cykl" : "nie ma cyklu") << endl;
	cout << "Stopien grafu G: " << GraphRank(G) << endl;

	Graph <int> GG; // graf wazony
	for (Vertex i = 0u; i < 9u; ++i)
		GG.addVertex(i);

	// min drzewo
	GG.addEdge(0, 1, 1);
	GG.addEdge(1, 4, 1);
	GG.addEdge(4, 3, 1);
	GG.addEdge(4, 7, 1);
	GG.addEdge(7, 8, 1);
	GG.addEdge(8, 5, 1);
	GG.addEdge(5, 2, 1);
	GG.addEdge(6, 7, 1);

	//dodatkowe krawedzie
	GG.addEdge(0, 8, 5);
	GG.addEdge(1, 8, 2);
	GG.addEdge(6, 6, 3);
	GG.addEdge(3, 2, 4);
	GG.addEdge(7, 6, 5);
	GG.addEdge(8, 4, 7);

	cout << "Minimalne drzewo spinajace grafu G: " << endl << MinClingTree<int>(GG) << endl;

	getchar();

	return 0;
}