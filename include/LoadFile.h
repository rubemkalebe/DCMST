#ifndef LOADFILE_H
#define LOADFILE_H

#include <iostream>
#include <fstream>
#include "Tree.h"
#include "CostMatrix.h"

class LoadFile {

private:

    std::string path;

public:

    LoadFile(std::string path);

    std::string getPath() const;

    void setPath(const std::string &value);

    void readNetworkInfo();

    void readCostMatrix(CostMatrix *costMatrix);
};

#endif // LOADFILE_H
