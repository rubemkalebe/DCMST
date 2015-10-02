#include "Backtracking.h"
#include <iostream>

using namespace std;

int Backtracking::edges(int n) {
	return (n * (n - 1)) / 2;
}

int Backtracking::initializeLinkVector(Edge link[]) {
	int countEdges = 0; // Índice da aresta
	for(int i = 0; i < Tree::getVertexMax(); i++) {
		for(int j = i; j < Tree::getVertexMax(); j++) {
			if(i != j) {
				Vertex v1(i+1);
				Vertex v2(j+1);
				Edge e(v1, v2, countEdges, costMatrix->getElement(i, j));
				link[countEdges++] = e;
			}
		}
	}
	return countEdges;
}

void Backtracking::combinations(Edge link[], int length, int size, int startPosition, Tree &tree) {
	if(size == 0) {
		if((solutions == 0) || (tree.totalCost() < bestTree->totalCost())) {
			bestTree->update(tree);
		}
		solutions++;
		return;
	}
	for(int i = startPosition; i <= length - size; i++) {
		if(tree.addEdge(link[i])) {
			combinations(link, length, size-1, i+1, tree);
			tree.removeEdge();
		} else {
			combinations(link, length, size, i+1, tree);
			return;
		}
	}
}

Backtracking::Backtracking(CostMatrix *costMatrix) {
	solutions = 0;
	executionTime = 0;
	this->costMatrix = costMatrix;
	bestTree = new Tree();
}

Backtracking::~Backtracking() {
	delete bestTree;
}

void Backtracking::findMinimum() {
	Edge link[edges(Tree::getVertexMax())]; // Número de rotas possíveis
													// equivalente ao somatório de 1...n
	Tree tree;
	Chronometer::start();
	int length = initializeLinkVector(link);
	combinations(link, length, Tree::getVertexMax()-1, 0, tree); // Computa as combinações de arestas possíveis
	Chronometer::stop();
	executionTime = Chronometer::elapsedTime();
}

Tree* Backtracking::getBestTree() {
	return bestTree;
}

int Backtracking::getSolutions() {
	return solutions;
}

double Backtracking::getExecutionTime() {
	return executionTime;
}
