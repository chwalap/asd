#include "GraphRank.h"

unsigned int GraphRank(const Graph<bool> &G) {
	unsigned int rank = 0u;

	for (Vertex V : G.getVertices()) {
		unsigned int N = static_cast<unsigned int>(G.getNeighbours(V).size());
		if (N > rank) rank = N;
	}
	return rank;
}
