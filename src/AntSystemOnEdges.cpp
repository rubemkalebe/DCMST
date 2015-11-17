#include "AntSystemOnEdges.h"
#include <iostream>
#include <algorithm>
#include <cmath>

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
	probs = new double[n];
	for(int i = 0; i < numAnts; i++) {
		Ant *a = new Ant(size);
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

void AntSystemOnEdges::findMinimum() {
	Edge link[edges(Tree::getVertexMax())]; // Número de rotas possíveis
													// equivalente ao somatório de 1...n
	Tree tree;
	int length = initializeLinkVector(link);
	std::sort(link, link+edges(Tree::getVertexMax()), comp);
	//srand((unsigned int) time(NULL));
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
	//return random() % length;
	int x = random() % length;
	//cout << "rand: " << x << endl;
	return x;
}

double AntSystemOnEdges::nextDouble() {
	return ((double)(random())/(double)(RAND_MAX));
}

void AntSystemOnEdges::moveAnts(Edge link[]) {
	int currentIndex = 1;
	while(currentIndex < size - 1) { // numAnts armazena |V| e 1 aresta ja foi inserida
		//cout << endl;
		for(int i = 0; i < numAnts; i++) {
			//cout << "Move--Ant" << (i+1) << endl;
				int next;
				/*do {
					while((next = selectNext(ants[i], link)) && !(next > -1))
						;
					//cout << "next: " << next << endl;
					//cin.get();
				} while(!ants[i]->visit(link[next]));*/
				next = selectNext(ants[i], link);
				int n = edges(size);
				while(!ants[i]->visit(link[next])) {
					next += 1;
					next %= n;
				}
		}
		currentIndex++;
	}
}

int AntSystemOnEdges::selectNext(Ant *a, Edge link[]) {
	//cout << "func\n";
	if(nextDouble() < pr) {
		//cout << "rand\n";
		int n = edges(size);
		int next;
		do {
			next = nextInt(n);
		} while(a->visited(next));
		return next;
	}

	probTo(a, link);
	double r = nextDouble();
	//cout << "r: " << r << endl;
	int n = edges(size);
	double total = 0.0;
	for(int i = 0; i < n; i++) {
		total += probs[i];
		if(total >= r) {
			return i;
		}
	}
	return -1;
}

void AntSystemOnEdges::probTo(Ant *a, Edge link[]) {
	int n = edges(size);
	//int i = a->getTree().getTree()->back().getId();

	double denom = 0.0;
	for(int j = 0; j < n; j++) {
		if(!a->visited(j)) {
			denom += pow(trails[j], alpha) * pow(1.0 / link[j].getCost(), beta);
		}
	}

	for(int j = 0; j < n; j++) {
		if(a->visited(j)) {
			probs[j] = 0.0;
		} else {
			double numerator = pow(trails[j], alpha) * pow(1.0 / link[j].getCost(), beta);
			probs[j] = numerator / denom;
		}
	}
}

void AntSystemOnEdges::updateTrails() {
	int n = edges(size);

	// evaporation
	for(int i = 0; i < n; i++) {
		trails[i] *= evaporationRate;
	}

	// each ants contribution
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
		/*cout << endl;
		std::vector<Edge>* edges = ants[i]->getTree().getTree();
		cout << "Ant" << (i+1) << endl;
		for(Edge e : *edges) {
			cout << "Show-Edge: " << e.getInitial().getId() << " " << e.getFinal().getId() << endl;
		}*/


		if(ants[i]->getSolutionCost() < bestTree->totalCost()) {
			solutions++;
			bestTree->update(ants[i]->getTree());
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
