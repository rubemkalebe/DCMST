#include "OrderedOptimizedBacktracking.h"
#include <iostream>
#include <algorithm>

using namespace std;

int OrderedOptimizedBacktracking::edges(int n) {
	return (n * (n - 1)) / 2;
}

int OrderedOptimizedBacktracking::initializeLinkVector(Edge link[]) {
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

void OrderedOptimizedBacktracking::combinations(Edge link[], int length, int size, int startPosition, Tree &tree) {
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

OrderedOptimizedBacktracking::OrderedOptimizedBacktracking(CostMatrix *costMatrix) {
	solutions = 0;
	executionTime = 0;
	this->costMatrix = costMatrix;
	bestTree = new Tree();
}

OrderedOptimizedBacktracking::~OrderedOptimizedBacktracking() {
	delete bestTree;
}

void OrderedOptimizedBacktracking::findMinimum() {
	Edge link[edges(Tree::getVertexMax())]; // Número de rotas possíveis
													// equivalente ao somatório de 1...n
	Tree tree;
	int length = initializeLinkVector(link);
	std::sort(link, link+edges(Tree::getVertexMax()), comp);
	Chronometer::start();
	combinations(link, length, Tree::getVertexMax()-1, 0, tree); // Computa as combinações de arestas possíveis
	Chronometer::stop();
	executionTime = Chronometer::elapsedTime();
}

Tree* OrderedOptimizedBacktracking::getBestTree() {
	return bestTree;
}

int OrderedOptimizedBacktracking::getSolutions() {
	return solutions;
}

double OrderedOptimizedBacktracking::getExecutionTime() {
	return executionTime;
}
