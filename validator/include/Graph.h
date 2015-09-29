#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "Edge.h"
#include "Vertex.h"
#include "UnionFind.h"

class Graph {

private:

	std::vector<Vertex> vertices;

	std::vector<Edge> edges;

	int totalCost;

	static int vertexMax;

	static int degreeMax;

	int edgeCounter;

public:

	Graph();

	~Graph();

	int getTotalCost() const;

	void setTotalCost(int totalCost);

	static int getVertexMax();

	static void setVertexMax(int value);

	static int getDegreeMax();

	static void setDegreeMax(int value);

	int getEdgeCounter() const;

	std::vector<Vertex> getVertices() const;

	void setVertices(std::vector<Vertex> vertices);

	std::vector<Edge> getEdges() const;

	void setEdges(std::vector<Edge> edges);

	void connect(Vertex &v1, Vertex &v2, int cost);

	void addEdge(Edge e);

	bool isCyclic();

	bool isConnected();

};

#endif
