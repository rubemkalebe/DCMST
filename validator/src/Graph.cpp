#include "Graph.h"

#include <iostream>

int Graph::vertexMax;
int Graph::degreeMax;

Graph::Graph() {
	this->edgeCounter = 0;
	degrees = new int[vertexMax];
	for(int i = 0; i < vertexMax; i++) {
      degrees[i] = 0;
  }
}

Graph::~Graph() {
	delete [] degrees;
}

int Graph::getTotalCost() const {
	return totalCost;
}

void Graph::setTotalCost(int totalCost) {
	this->totalCost = totalCost;
}

int Graph::getVertexMax(){
	return vertexMax;
}

void Graph::setVertexMax(int value) {
	vertexMax = value;
}

int Graph::getDegreeMax() {
	return degreeMax;
}

void Graph::setDegreeMax(int value) {
	degreeMax = value;
}

int Graph::getEdgeCounter() const {
	return edgeCounter;
}

std::vector<Edge> Graph::getEdges() const {
	return edges;
}

void Graph::setEdges(std::vector<Edge> edges) {
	this->edges = edges;
}

void Graph::setDegrees(int *v) {
	this->degrees = v;
}

int* Graph::getDegrees() const {
	return degrees;
}

void Graph::increaseDegree(int i) {
	degrees[i] += 1;
}

void Graph::decreaseDegree(int i) {
	if(degrees[i] - 1 >= 0) {
		degrees[i] -= 1;
	}
}

void Graph::connect(Vertex &v1, Vertex &v2, int cost) {
	Edge e(v1, v2, ++edgeCounter, cost);
	edges.push_back(e);
	increaseDegree(e.getInitial().getId()-1);
	increaseDegree(e.getFinal().getId()-1);
}

void Graph::addEdge(Edge &e) {
	edges.push_back(e);
	edgeCounter++;
	increaseDegree(e.getInitial().getId()-1);
	increaseDegree(e.getFinal().getId()-1);
}

bool Graph::isCyclic() {
	UnionFind uf(vertexMax);
	for(int i = 0; i < edgeCounter; i++) {
		if(uf.sameComponent(edges.at(i).getInitial().getId(), edges.at(i).getFinal().getId())) {
			return true;
		}
	}
	return false;
}

bool Graph::isConnected() {
	UnionFind uf(vertexMax);
	int cont = 0;
	for(int i = 0; i < edgeCounter; i++) {
		if(!uf.sameComponent(edges.at(i).getInitial().getId(), edges.at(i).getFinal().getId())) {
			cont++;
		}
		uf.make_union(edges.at(i).getInitial().getId(), edges.at(i).getFinal().getId());
	}
	if(cont == vertexMax - 1) {
		return true;
	} else {
		return false;
	}
}
