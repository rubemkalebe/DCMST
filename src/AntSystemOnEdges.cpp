#include "AntSystemOnEdges.h"
#include <iostream>
#include <algorithm>

using namespace std;

AntSystemOnEdges::AntSystemOnEdges(CostMatrix *costMatrix) {
	executionTime = 0.0;
	solutions = 0;
	this->costMatrix = costMatrix;
	bestTree = new Tree();
	this->size = this->costMatrix->size();
	this->numAnts = (int) this->size * numAntFactor;
	int n = ((size * (size - 1)) / 2);
	trails = new double[n];
	for(int i = 0; i < numAnts; i++) {
		Ant a(size);
		ants.push_back(a);
	}
}

AntSystemOnEdges::~AntSystemOnEdges() {
	delete bestTree;
	delete trails;
}

Tree* AntSystemOnEdges::getBestTree() {
	return bestTree;
}

double AntSystemOnEdges::getExecutionTime() {
	return executionTime;
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

/*bool comp(const Edge &e1, const Edge &e2) {
	return e1.getCost() < e2.getCost();
}*/

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
		moveAnts(link);
		updateTrails();
		updateBest();
	}

	Chronometer::stop();
	executionTime = Chronometer::elapsedTime();
}

void AntSystemOnEdges::setupAnts(Edge link[], int length) {
	for(int i = 0; i < numAnts; i++) {
		ants[i].reset();
		while(!ants[i].visit(link[nextRandom(length)]))
			;
	}
}

unsigned int AntSystemOnEdges::nextRandom(int length) {
	return rand() % length;
}

void AntSystemOnEdges::moveAnts(Edge link[]) {
	int currentIndex = 1;
	while(currentIndex < size - 1) { // numAnts armazena |V| e 1 aresta ja foi inserida
		for(int i = 0; i < numAnts; i++) {
			while(!ants[i].visit(link[selectNext()]))
				;
		}
		currentIndex++;
	}
}

int AntSystemOnEdges::selectNext() {
	return 0;
}

void AntSystemOnEdges::updateTrails() {
	int n = edges(size);

	// evaporation
	for(int i = 0; i < n; i++) {
		trails[i] *= evaporationRate;
	}

	// each ants contribution
	for(int i = 0; i < numAnts; i++) {
		double contribution = Q / ants[i].getSolutionCost();
		std::vector<Edge>* edges = ants[i].getTree().getTree();
		for(Edge e : *edges) {
			trails[e.getId()] += contribution;
		}
	}
}

void AntSystemOnEdges::updateBest() {
	if(bestTree->totalCost() == 0) {
		solutions++;
		bestTree->update(ants[0].getTree());
	}
	for(int i = 0; i < numAnts; i++) {
		if(ants[i].getSolutionCost() < bestTree->totalCost()) {
			solutions++;
			bestTree->update(ants[i].getTree());
		}
	}
}

void AntSystemOnEdges::clearTrails() {
	int n = edges(size);
	for(int i = 0; i < n; i++) {
		trails[i] = initialPheromone;
	}
}

int AntSystemOnEdges::getSolutions() {
	return solutions;
}
