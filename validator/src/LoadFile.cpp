#include "LoadFile.h"

std::string LoadFile::getPath() const
{
    return path;
}

void LoadFile::setPath(const std::string &value)
{
    path = value;
}

void LoadFile::readNetworkInfo()
{
    int n, d;
    std::ifstream in(path.c_str());
    if(in.is_open()) {
        in >> n >> d;
        Graph::setVertexMax(n);
        Graph::setDegreeMax(d);
    }
    in.close();
}

void LoadFile::readCostMatrix(CostMatrix *costMatrix)
{
    int n, d;
    int cX;
    std::ifstream in(path.c_str());
    if(in.is_open()) {
        in >> n >> d;
        for(int i = 0; i < costMatrix->size(); i++) {
            for(int j = i; j < costMatrix->size(); j++) {
                if(i == j) {
                    costMatrix->setElement(i, j, 0);
                } else {
                    in >> cX;
                    costMatrix->setElement(i, j, cX);
                    costMatrix->setElement(j, i, cX);
                }
            }
        }
    }
    in.close();
}

LoadFile::LoadFile(std::string path) {
    this->path = path;
}
