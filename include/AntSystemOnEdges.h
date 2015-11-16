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

class AntSystemOnEdges : public ISolution {

private:

	Tree *bestTree;

	double executionTime;

	CostMatrix *costMatrix;

	int numAnts;

	Ant *ants;

public:

	AntSystemOnEdges(CostMatrix *costMatrix);

	~AntSystemOnEdges();

	virtual void findMinimum();

	virtual Tree* getBestTree();

	virtual double getExecutionTime();

private:

	void setupAnts(Link link[], int length);

	void moveAnts();

	void updateTrails();

	void updateBest();

	int edges(int n);

	int initializeLinkVector(Edge link[]);

	void clearTrails();

	unsigned int nextRandom(int length);

	int selectNext();

};

#endif // ANT_SYSTEM_ON_ENDGES_H
