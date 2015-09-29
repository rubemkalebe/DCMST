#include "Graph.h"

Graph::Graph() {
	this->edgeCounter = 0;
}

Graph::~Graph() {

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

std::vector<Vertex> Graph::getVertices() const {
	return vertices;
}

void Graph::setVertices(std::vector<Vertex> vertices) {
	this->vertices = vertices;
}

std::vector<Edge> Graph::getEdges() const {
	return edges;
}

void Graph::setEdges(std::vector<Edge> edges) {
	this->edges = edges;
}

void Graph::connect(Vertex &v1, Vertex &v2, int cost) {
	vertices.push_back(v1);
	vertices.push_back(v2);
	Edge e(v1, v2, ++edgeCounter, cost);
	edges.push_back(e);
}

void Graph::addEdge(Edge &e) {
	vertices.push_back(e.getInitial());
	vertices.push_back(e.getFinal());
	edges.push_back(e);
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
