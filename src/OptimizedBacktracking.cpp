#include "OptimizedBacktracking.h"
#include <iostream>

using namespace std;

int OptimizedBacktracking::edges(int n) {
	return (n * (n - 1)) / 2;
}

int OptimizedBacktracking::initializeLinkVector(Edge link[]) {
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

void OptimizedBacktracking::combinations(Edge link[], int length, int size, int startPosition, Tree &tree) {
	if(size == 0) {
		if((solutions == 0) || (tree.totalCost() < bestTree->totalCost())) {
			bestTree->update(tree);
		}
		solutions++;
		return;
	}
	for(int i = startPosition; i <= length - size; i++) {
		if((solutions == 0 || tree.totalCost() + link[i].getCost() < bestTree->totalCost()) && tree.addEdge(link[i])) {
			combinations(link, length, size-1, i+1, tree);
			tree.removeEdge();
		} else {
			combinations(link, length, size, i+1, tree);
			return;
		}
	}
}

OptimizedBacktracking::OptimizedBacktracking(CostMatrix *costMatrix) {
	solutions = 0;
	executionTime = 0;
	this->costMatrix = costMatrix;
	bestTree = new Tree();
}

OptimizedBacktracking::~OptimizedBacktracking() {
	delete bestTree;
}

void OptimizedBacktracking::findMinimum() {
	Edge link[edges(Tree::getVertexMax())]; // Número de rotas possíveis
													// equivalente ao somatório de 1...n
	Tree tree;
	int length = initializeLinkVector(link);
	Chronometer::start();
	combinations(link, length, Tree::getVertexMax()-1, 0, tree); // Computa as combinações de arestas possíveis
	Chronometer::stop();
	executionTime = Chronometer::elapsedTime();
}

Tree* OptimizedBacktracking::getBestTree() {
	return bestTree;
}

int OptimizedBacktracking::getSolutions() {
	return solutions;
}

double OptimizedBacktracking::getExecutionTime() {
	return executionTime;
}
