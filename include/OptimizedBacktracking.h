#ifndef OPTIMIZED_BACKTRACKING_H
#define OPTIMIZED_BACKTRACKING_H

#include "Edge.h"
#include "Tree.h"
#include "Vertex.h"
#include "CostMatrix.h"
#include "Chronometer.h"
#include "ISolution.h"

class OptimizedBacktracking : public ISolution {

private:

	Tree *bestTree;

	int solutions;

	double executionTime;

	CostMatrix *costMatrix;

public:

	OptimizedBacktracking(CostMatrix *costMatrix);

	~OptimizedBacktracking();

	virtual void findMinimum();

	virtual Tree* getBestTree();

	virtual int getSolutions();

	virtual double getExecutionTime();

private:

	int edges(int n);

	int initializeLinkVector(Edge link[]);

	void combinations(Edge link[], int length, int size, int startPosition, Tree &tree);

};

#endif //OPTIMIZED_BACKTRACKING_H
