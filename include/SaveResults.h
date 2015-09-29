#ifndef SAVERESULTS_H
#define SAVERESULTS_H

#include "ISolution.h"

class SaveResults {

public:

	void writeToFile(ISolution *solver);

};

#endif //SAVERESULTS_H