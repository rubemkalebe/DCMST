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

    std::string path;

    CostMatrix *matrix;

public:

    LoadFile(std::string path);

    std::string getPath() const;

    void setPath(const std::string &value);

    void readNetworkInfo();

    void readCostMatrix(CostMatrix *costMatrix);

    std::vector<Edge> readEdgesList(std::string resultsPath);
};

#endif // LOADFILE_H
