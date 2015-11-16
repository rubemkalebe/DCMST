#ifndef ANT_SYSTEM_ON_ENDGES_H
#define ANT_SYSTEM_ON_ENDGES_H

#include "Ant.h"
#include "Edge.h"
#include "Tree.h"
#include "Vertex.h"
#include "CostMatrix.h"
#include "Chronometer.h"
#include "ISolution.h"

#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;

class AntSystemOnEdges : public ISolution {

private:

	Tree *bestTree;

	double executionTime;

	CostMatrix *costMatrix;

	int size;

	int numAnts;

	vector<Ant> ants;

	const int maxIterations = 2000;

	const double initialPheromone = 1.0;

	const double evaporationRate = 0.5;

	const double Q = 500.0;

	const double numAntFactor = 0.8;

  double *trails;

public:

	AntSystemOnEdges(CostMatrix *costMatrix);

	~AntSystemOnEdges();

	virtual void findMinimum();

	virtual Tree* getBestTree();

	virtual double getExecutionTime();

private:

	void setupAnts(Edge link[], int length);

	void moveAnts(Edge link[]);

	void updateTrails();

	void updateBest();

	int edges(int n);

	int initializeLinkVector(Edge link[]);

	void clearTrails();

	unsigned int nextRandom(int length);

	int selectNext();

};

#endif // ANT_SYSTEM_ON_ENDGES_H
