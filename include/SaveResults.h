#ifndef SAVERESULTS_H
#define SAVERESULTS_H

#include "ISolution.h"

class SaveResults {

public:

	void writeAllResultsToFile(ISolution *solver);

	void writeGraphDataToFile(ISolution *solver);

};

#endif //SAVERESULTS_H
