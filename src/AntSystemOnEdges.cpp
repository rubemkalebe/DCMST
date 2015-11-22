#include "AntSystemOnEdges.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

AntSystemOnEdges::AntSystemOnEdges(CostMatrix *costMatrix) {
	executionTime = 0.0;
	solutions = 0;
	this->costMatrix = costMatrix;
	this->numVertices = this->costMatrix->size();
	this->numAnts = (int) this->numVertices * numAntFactor;
	this->numPossibleEdges = summation(numVertices);
	bestTree = new Tree();
	trails = new double[numPossibleEdges];
	probs = new double[numPossibleEdges];
	Ant *a;
	for(int i = 0; i < numAnts; i++) {
		a = new Ant(numVertices);
		ants.push_back(a);
	}
}

AntSystemOnEdges::~AntSystemOnEdges() {
	delete bestTree;
	delete [] trails;
	delete [] probs;
	for(int i = 0; i < numAnts; i++) {
		delete ants[i];
	}
}

Tree* AntSystemOnEdges::getBestTree() {
	return bestTree;
}

double AntSystemOnEdges::getExecutionTime() {
	return executionTime;
}

int AntSystemOnEdges::initializeLinkVector(Edge link[]) {
	int countEdges = 0; // Índice da aresta
	for(int i = 0; i < numVertices; i++) {
		for(int j = i; j < numVertices; j++) {
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
	Edge link[numPossibleEdges];
	Tree tree;
	int length = initializeLinkVector(link);
	std::sort(link, link+numPossibleEdges, comp);
	Chronometer::start();

	// solve
	clearTrails();
	for(int iteration = 0; iteration < maxIterations; iteration++) {
		srand((unsigned int) time(NULL));
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
		ants[i]->reset();
		//cout << "Setup--Ant" << (i+1) << endl;
		while(!ants[i]->visit(link[nextInt(length)]))
			;
	}
}

unsigned int AntSystemOnEdges::nextInt(int length) {
	return random() % length;
}

double AntSystemOnEdges::nextDouble() {
	return ((double)(random())/(double)(RAND_MAX));
}

void AntSystemOnEdges::moveAnts(Edge link[]) {
	int currentIndex = 1;
	while(currentIndex < numVertices - 1) { // numAnts armazena |V| e 1 aresta ja foi inserida
		//cout << endl;
		for(int i = 0; i < numAnts; i++) {
			//cout << "Move--Ant" << (i+1) << endl;
				int next = selectNext(ants[i], link);
				while(!ants[i]->visit(link[next])) {
					next += 1;
					next %= numPossibleEdges;
				}
		}
		currentIndex++;
	}
}

int AntSystemOnEdges::selectNext(Ant *a, Edge link[]) {
	if(nextDouble() < pr) {
		int next;
		do {
			next = nextInt(numPossibleEdges);
		} while(a->visited(next));
		return next;
	}

	probTo(a, link);
	double r = nextDouble();
	double total = 0.0;
	for(int i = 0; i < numPossibleEdges; i++) {
		total += probs[i];
		if(total >= r) {
			return i;
		}
	}
	return 0; // nao eh pra chegar aqui, mas...
}

void AntSystemOnEdges::probTo(Ant *a, Edge link[]) {
	double denom = 0.0;
	for(int j = 0; j < numPossibleEdges; j++) {
		if(!a->visited(j)) {
			denom += fastPow(trails[j], alpha) * fastPow(1.0 / link[j].getCost(), beta);
		}
	}

	for(int j = 0; j < numPossibleEdges; j++) {
		if(a->visited(j)) {
			probs[j] = 0.0;
		} else {
			double numerator = fastPow(trails[j], alpha) * fastPow(1.0 / link[j].getCost(), beta);
			probs[j] = numerator / denom;
		}
	}
}

void AntSystemOnEdges::updateTrails() {
	// evaporation
	for(int i = 0; i < numPossibleEdges; i++) {
		trails[i] *= evaporationRate;
	}

	// each ant contribution
	for(int i = 0; i < numAnts; i++) {
		double contribution = Q / ants[i]->getSolutionCost();
		std::vector<Edge>* edges = ants[i]->getTree().getTree();
		for(Edge e : *edges) {
			trails[e.getId()] += contribution;
		}
	}
}

void AntSystemOnEdges::updateBest() {
	if(bestTree->totalCost() == 0) {
		solutions++;
		bestTree->update(ants[0]->getTree());
	}
	for(int i = 0; i < numAnts; i++) {
		if(ants[i]->getSolutionCost() < bestTree->totalCost()) {
			solutions++;
			bestTree->update(ants[i]->getTree());
		}
	}
}

void AntSystemOnEdges::clearTrails() {
	for(int i = 0; i < numPossibleEdges; i++) {
		trails[i] = initialPheromone;
	}
}

int AntSystemOnEdges::getSolutions() {
	return solutions;
}
