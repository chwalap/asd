#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>

typedef unsigned int Vertex;

enum Color {
	RED, // visited #1
	GREEN, // visited #2
	BLUE // not visited
};

template <typename T>
class Graph {
public:
	Graph() {}
	~Graph() {}

	std::set<Vertex> getVertices() const {
		return V;
	}

	std::map <Vertex, std::vector <std::pair<Vertex, T>>> getEdges() const {
		return E;
	}

	void addEdge(Vertex i, Vertex j, const T &value = T()) {
		if (V.find(i) == V.end() || V.find(j) == V.end()) {
			std::cerr << "Can't create an edge for these vertices: " << i << ", " << j << std::endl;
			return;
		}

		// w zaleznosci czy chcemy graf skierowany czy nie to ustawiamy w 1, albo 2 strony
		E[i].push_back(std::pair<Vertex, T>(j, value));
		E[j].push_back(std::pair<Vertex, T>(i, value));
	}

	void addVertex(Vertex v) {
		V.insert(v);
	}

	size_t getNumberOfVertices() const {
		return V.size();
	}

	Vertex getFirstVertex() const {
		if (V.size() > 0) return *V.begin();
		return Vertex(0); // lepiej byloby cos rzucic
	}

	size_t getNumerOfEdges() const {
		size_t edges = 0;
		for (Vertex v : V)
			edges += getNeighbours(v).size();
		return edges / 2; // bo mamy kazda krawedz podwojnie (nieskierowany graf)
	}

	std::vector <std::pair <Vertex, T>> getNeighbours(Vertex v) const {
		if (V.find(v) == V.end()) {
			std::cerr << "Vertex " << v << " does not exsit!" << std::endl;
		}
		if (E.find(v) != E.end()) {
			return E.at(v);
		}
		else {
			return std::vector <std::pair <Vertex, T>>();
		}
	}

	bool doesEdgeExist(Vertex A, Vertex B, T value = T()) const {
		if (E.find(A) == E.end()) return false;
		return std::find(E.at(A).begin(), E.at(A).end(), make_pair(B, value)) != E.at(A).end();
	}

	template<typename T>
	friend std::ostream & operator<< (std::ostream &cout, const Graph<T> &G);

protected:
	std::set <Vertex> V;
	std::map <Vertex, std::vector <std::pair<Vertex, T>>> E;
	Vertex vertexID = 0u;
};

template<typename T>
std::ostream & operator<< (std::ostream &cout, const Graph<T> &G) {
	cout << "Wierzcholki: ";
	for (Vertex V : G.getVertices()) {
		cout << V << " ";
	}
	cout << endl;
	cout << "Krawedzie (podwojne): " << endl;
	for (auto &e : G.getEdges()) {
		for (auto &t : e.second) {
			cout << e.first << "->" << t.first << ": " << t.second << endl;
		}
	}
	return cout;
}
