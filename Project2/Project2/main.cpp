#include <iostream>

#include "Graph.h"
#include "IsBipartiteGraph.h"
#include "CountConsistenComponents.h"
#include "HasCycle.h"
#include "GraphRank.h"

using namespace std;

int main() {
	Graph G;
	for (int i = 0; i < 8; ++i)
		G.addVertex();

	G.addEdge(0, 4);
	G.addEdge(0, 3);
	G.addEdge(1, 4);
	G.addEdge(2, 3);
	
	//G.addEdge(4, 2); // wyzszy stopien grafu (4)
	//G.addEdge(4, 3);
	
	//G.addEdge(1, 2); // jest cykl albo go nie ma

	G.addEdge(5, 6); // dwie spojne skladowe + trzecia sam wierzcholek 7

	cout << "Graf G z " << G.getNumberOfVertices() << " wierzcholkami i " << G.getNumerOfEdges() << " krawedziami" << endl;
	cout << "Graf G " << (IsBipartiteGraph(G) ? "jest" : "nie jest") << " dwudzielny" << endl;
	cout << "Graf G ma " << CountConsistentComponents(G) << " spojnych skladowych" << endl;
	cout << "Graf G " << (HasCycle(G) ? "ma cykl" : "nie ma cyklu") << endl;
	cout << "Stopien grafu G: " << GraphRank(G) << endl;

	getchar();

	return 0;
}