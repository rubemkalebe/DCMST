#ifndef ISOLUTION_H
#define ISOLUTION_H

#include "Tree.h"

class ISolution {

public:

	virtual Tree *getBestTree() = 0;

	virtual int getSolutions() = 0;

	virtual double getExecutionTime() = 0;

	virtual void findMinimum() = 0;

	virtual ~ISolution(){};

};

#endif //ISOLUTION_H