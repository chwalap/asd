#pragma once

#include "Graph.h"
#include <queue>

template <typename T>
Graph<T> MinClingTree(const Graph <T> &G) {
	Graph <T> H; // minimalne drzewo spinajace

	if (G.getNumberOfVertices() == 0) {
		return H;
	}

	// dodajemy pierwszy wierzcholek
	Vertex Current = G.getFirstVertex();
	H.addVertex(Current);

	// kolejka priorytetowa
	auto comp = [](const std::tuple<Vertex, Vertex, T> &lhs, const std::tuple<Vertex, Vertex, T> &rhs) { return std::get<2>(lhs) > std::get<2>(rhs); };
	std::priority_queue<std::tuple<Vertex, Vertex, T>, std::vector<std::tuple<Vertex, Vertex, T>>, decltype(comp)> PQ(comp);

	// dodajemy wszystkich sasiadow pierwszego wierzcholka
	for (auto N : G.getNeighbours(Current)) {
		std::tuple<Vertex, Vertex, T> V = std::make_tuple(Current, N.first, N.second);
		PQ.push(V);
	}

	while (!PQ.empty() && G.getNumberOfVertices() != H.getNumberOfVertices()) {
		// bierzemy najblizszy wierzcholek
		std::tuple<Vertex, Vertex, T> V = PQ.top();
		PQ.pop();

		// dodajemy do nowego grafu
		H.addVertex(std::get<1>(V));
		H.addEdge(std::get<0>(V), std::get<1>(V), std::get<2>(V));

		// dodajemy sasiedznie wierzcholki (nie dodajac juz tych z grafu H
		Current = std::get<1>(V);
		for (auto N : G.getNeighbours(Current)) {
			if (!H.doesEdgeExist(Current, N.first, N.second)) {
				std::tuple<Vertex, Vertex, T> V = std::make_tuple(Current, N.first, N.second);
				PQ.push(V);
			}
		}
	}

	return H;
}

