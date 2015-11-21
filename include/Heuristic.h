#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Edge.h"
#include "Tree.h"
#include "Vertex.h"
#include "CostMatrix.h"
#include "Chronometer.h"
#include "ISolution.h"
#include "Util.h"

class Heuristic : public ISolution {

private:

	Tree *bestTree;

	int solutions;

	double executionTime;

	CostMatrix *costMatrix;

	int escape; // Apos quantas iteracoes parar de executar -- parametro varia em relacao ao numero de vertices

	int iterationsWithoutChange; // Numero de iteracoes sem gerar uma solucao

public:

	Heuristic(CostMatrix *costMatrix);

	~Heuristic();

	virtual void findMinimum();

	virtual Tree* getBestTree();

	virtual int getSolutions();

	virtual double getExecutionTime();

private:

	int edges(int n);

	int initializeLinkVector(Edge link[]);

	void combinations(Edge link[], int length, int size, int startPosition, Tree &tree);

};

#endif //HEURISTIC_H
