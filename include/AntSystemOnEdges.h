#ifndef ANT_SYSTEM_ON_ENDGES_H
#define ANT_SYSTEM_ON_ENDGES_H

#include "Ant.h"
#include "Edge.h"
#include "Tree.h"
#include "Vertex.h"
#include "CostMatrix.h"
#include "Chronometer.h"
#include "ISolution.h"
#include "Util.h"

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

	int solutions;

	int numAnts;

	vector<Ant*> ants;

	const int maxIterations = 500;//2000;

	const double alpha = 1.0;

	const double beta = 5.0;

	const double initialPheromone = 1.0;

	const double evaporationRate = 0.5;

	const double Q = 500.0;

	const double numAntFactor = 0.7;

	const double pr = 0.1;

  double *trails;

	double *probs;

public:

	AntSystemOnEdges(CostMatrix *costMatrix);

	~AntSystemOnEdges();

	virtual void findMinimum();

	virtual Tree* getBestTree();

	virtual int getSolutions();

	virtual double getExecutionTime();

private:

	void setupAnts(Edge link[], int length);

	void moveAnts(Edge link[]);

	void updateTrails();

	void updateBest();

	int edges(int n);

	int initializeLinkVector(Edge link[]);

	void clearTrails();

	unsigned int nextInt(int length);

	double nextDouble();

	int selectNext(Ant *a, Edge link[]);

	void probTo(Ant *a, Edge link[]);

};

#endif // ANT_SYSTEM_ON_ENDGES_H
