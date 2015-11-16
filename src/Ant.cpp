#include "Ant.h"

Ant::Ant(int graphSize) {
    this->graphSize = graphSize;
    int n = ((graphSize * (graphSize - 1)) / 2);
    _visited = new bool[n];
}

Ant::~Ant() {
  delete _visited;
}

bool Ant::visit(Edge e) {
  if(t.addEdge(e)) {
    _visited[e.getId()] = true;
    return true;
  } else {
    return false;
  }
}

bool Ant::visited(int i) {
  return _visited[i];
}

void Ant::reset() {
  t.reset();
  int n = (graphSize * (graphSize - 1)) / 2;
  for(int i = 0; i < n; i++) {
    _visited[i] = false;
  }
}

Tree Ant::getTree() {
  return t;
}

int Ant::getSolutionCost() {
  return t.totalCost();
}
