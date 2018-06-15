#include "GraphRank.h"

unsigned int GraphRank(const Graph &G) {
	int rank = 0;

	for (Vertex V : G.getVertices()) {
		unsigned int N = G.getNeighbours(V).size();
		if (N > rank) rank = N;
	}
	return rank;
}
