#ifndef LOADFILE_H
#define LOADFILE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Edge.h"
#include "Graph.h"
#include "CostMatrix.h"

class LoadFile {

private:

    std::string instancePath;

    std::string resultsPath;

    CostMatrix *matrix;

public:

    LoadFile(std::string instancePath, std::string resultsPath);

    std::string getInstancePath() const;

    void setInstancePath(const std::string &value);

    std::string getResultsPath() const;

    void setResultsPath(const std::string &value);

    void readNetworkInfo();

    void readCostMatrix(CostMatrix *costMatrix);

    std::vector<Edge> readEdgesList();

    int readGraphCost();
};

#endif // LOADFILE_H
