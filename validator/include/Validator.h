#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>

#include "Edge.h"
#include "Graph.h"
#include "CostMatrix.h"

class Validator {

private:

	Graph g;

public:

	Validator(const std::vector<Edge> &edges);

	bool isCyclic();

	bool isConnected();

	bool checkDegreeConstrained();

	bool checkGraphCost(CostMatrix *m, int cost);

};

#endif
