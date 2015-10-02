#include "Validator.h"

#include <iostream>

Validator::Validator(const std::vector<Edge> &edges) {
  for(Edge e : edges) {
    g.addEdge(e);
  }
}

bool Validator::isCyclic() {
  return g.isCyclic();
}

bool Validator::isConnected() {
  return g.isConnected();
}

bool Validator::checkDegreeConstrained() {
  int *v = g.getDegrees();
  for(int i = 0; i < g.getVertexMax(); i++) {
    if(v[i] > g.getDegreeMax()) {
      return false;
    }
  }
  return true;
}

bool Validator::checkGraphCost(CostMatrix *m, int cost) {
  int total = 0;
  for(Edge e : g.getEdges()) {
    total += m->getElement(e.getInitial().getId()-1, e.getFinal().getId()-1);
  }
  return total == cost;
}
