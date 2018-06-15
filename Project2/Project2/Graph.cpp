#include "Graph.h"

using namespace std;

Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::addEdge(Vertex i, Vertex j) {
	if (i >= vertexID || j >= vertexID) {
		cerr << "Can't create an edge for these vertices: " << i << ", " << j << endl;
		return;
	}

	// w zaleznosci czy chcemy graf skierowany czy nie to ustawiamy w 1, albo 2 strony
	E[i][j] = true;
	E[j][i] = true;
}

Vertex Graph::addVertex() {
	V.insert(vertexID++);

	E.push_back(std::vector<bool>(vertexID, false));
	for (unsigned int j = 0; j < vertexID - 1; ++j) {
		E[j].push_back(false);
	}
	return vertexID - 1;
}

std::vector <Vertex> Graph::getNeighbours(Vertex v) const {
	if (V.find(v) == V.end()) {
		cerr << "Vertex " << v << " does not exsit!" << endl;
	}

	std::vector <Vertex> n;
	for (unsigned int i = 0; i < E[v].size(); ++i) {
		if (E[v][i]) {
			n.push_back(Vertex(i));
		}
	}
	return n;
}

set<Vertex> Graph::getVertices() const {
	return V;
}

bool Graph::edgeExist(const Vertex &A, const Vertex &B) const {
	if (A >= E.size() && B >= E.size())
		return false;
	return E[A][B];
}

size_t Graph::getNumberOfVertices() const {
	return V.size();
}

size_t Graph::getNumerOfEdges() const {
	int edges = 0;
	for (auto i : E)
		for (auto j : i)
			if (j) edges++;
	return edges / 2; // bo mamy kazda krawedz podwojnie (nieskierowany graf)
}
