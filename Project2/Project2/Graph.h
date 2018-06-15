#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <queue>

typedef unsigned int Vertex;

enum Color {
	RED, // visited #1
	GREEN, // visited #2
	BLUE // not visited
};

class Graph {
public:
	Graph();
	~Graph();

	std::set<Vertex> getVertices() const;
	bool edgeExist(const Vertex &A, const Vertex &B) const;

	void addEdge(Vertex i, Vertex j);
	Vertex addVertex();

	size_t getNumberOfVertices() const;
	size_t getNumerOfEdges() const;

	std::vector <Vertex> getNeighbours(Vertex v) const;

protected:
	std::set <Vertex> V;
	std::vector <std::vector <bool>> E;
	Vertex vertexID = 0u;
};