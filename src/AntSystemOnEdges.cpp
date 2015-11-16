#include "AntSystemOnEdges.h"
#include <iostream>
#include <algorithm>

using namespace std;

AntSystemOnEdges::AntSystemOnEdges(CostMatrix *costMatrix) {
	executionTime = 0.0;
	this->costMatrix = costMatrix;
	bestTree = new Tree();
	this->numAnts = this->costMatrix->size();
	ants = new Ant[numAnts];
}

AntSystemOnEdges::~AntSystemOnEdges() {
	delete bestTree;
}

Tree* AntSystemOnEdges::getBestTree() {
	return bestTree;
}

int AntSystemOnEdges::getSolutions() {
	return solutions;
}

double AntSystemOnEdges::getExecutionTime() {
	return executionTime;
}

bool comp(const Edge &e1, const Edge &e2) {
	return e1.getCost() < e2.getCost();
}

int AntSystemOnEdges::edges(int n) {
	return (n * (n - 1)) / 2;
}

int AntSystemOnEdges::initializeLinkVector(Edge link[]) {
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

void AntSystemOnEdges::findMinimum() {
	Edge link[edges(Tree::getVertexMax())]; // Número de rotas possíveis
													// equivalente ao somatório de 1...n
	Tree tree;
	int length = initializeLinkVector(link);
	std::sort(link, link+edges(Tree::getVertexMax()), comp);
	Chronometer::start();

	// solve
	clearTrails();
	for(int iteration = 0; iteration < maxIterations; iteration++) {
		setupAnts(link, length);
		moveAnts();
		updateTrails();
		updateBest();
	}

	Chronometer::stop();
	executionTime = Chronometer::elapsedTime();
}

void AntSystemOnEdges::setupAnts(Link link[], int length) {
	for(int i = 0; i < numAnts; i++) {
		ants[i].clear();
		while(!ants[i].visit(link[nextRandom(length)]))
			;
	}
}

unsigned int nextRandom(int length) {
	return rand() % length;
}

void AntSystemOnEdges::moveAnts() {
	int currentIndex = 1;
	while(currentIndex < numAnts - 2) { // numAnts armazena |V| e 1 aresta ja foi inserida
		for(int i = 0; i < numAnts; i++) {
			while(!ants[i].visit(link[selectNext()]))
				;
		}
		currentIndex++;
	}
}

int AntSystemOnEdges::selectNext() {

}

void AntSystemOnEdges::updateTrails() {

}

void AntSystemOnEdges::updateBest() {

}

void AntSystemOnEdges::clearTrails() {

}
