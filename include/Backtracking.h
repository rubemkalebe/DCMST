#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "Edge.h"
#include "Tree.h"
#include "Vertex.h"
#include "CostMatrix.h"
#include "Chronometer.h"
#include "ISolution.h"

class Backtracking : public ISolution {

private:

	Tree *bestTree;

	int solutions;

	double executionTime;

	CostMatrix *costMatrix;

public:

	Backtracking(CostMatrix *costMatrix);
	//Backtracking();

	~Backtracking();

	virtual void findMinimum();

	virtual Tree* getBestTree();

	virtual int getSolutions();

	virtual double getExecutionTime();

private:

	int edges(int n);

	int initializeLinkVector(Edge link[]);

	void combinations(Edge link[], int length, int size, int startPosition, Tree &tree);

};

#endif //BACKTRACKING_H