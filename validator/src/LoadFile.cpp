#include "LoadFile.h"

std::string LoadFile::getInstancePath() const
{
    return instancePath;
}

void LoadFile::setInstancePath(const std::string &value)
{
    this->instancePath = value;
}

std::string LoadFile::getResultsPath() const {
  return resultsPath;
}

void LoadFile::setResultsPath(const std::string &value) {
  this->resultsPath = value;
}

void LoadFile::readNetworkInfo()
{
    int n, d;
    std::ifstream in(instancePath.c_str());
    if(in.is_open()) {
        in >> n >> d;
        Graph::setVertexMax(n);
        Graph::setDegreeMax(d);
    }
    in.close();
}

void LoadFile::readCostMatrix(CostMatrix *costMatrix)
{
    this->matrix = costMatrix;
    int n, d;
    int cX;
    std::ifstream in(instancePath.c_str());
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

std::vector<Edge> LoadFile::readEdgesList() {
  int u, v, cost;
  std::ifstream in(resultsPath.c_str());
  std::vector<Edge> edges;
  if(in.is_open()) {
    int i = 0;
    in >> cost;
    while(in >> u >> v) {
      Vertex v1(u);
      Vertex v2(v);
      Edge e(v1, v2, i, matrix->getElement(u-1, v-1));
      edges.push_back(e);
      i++;
    }
  }
  in.close();
  return edges;
}

LoadFile::LoadFile(std::string instancePath, std::string resultsPath) {
    this->instancePath = instancePath;
    this->resultsPath = resultsPath;
}

int LoadFile::readGraphCost() {
  int cost;
  std::ifstream in(resultsPath.c_str());
  if(in.is_open()) {
    in >> cost;
  }
  in.close();
  return cost;
}
