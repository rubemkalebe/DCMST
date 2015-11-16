#include "Ant.h"

Ant::Ant(int graphSize) {
    this->graphSize = graphSize;
    t = new Tree();
    visited = new int[(graphSize * (graphSize - 1)) / 2];
}

Ant::~Ant() {
  delete t;
}

bool Ant::visit(Edge e) {
  if(t.addEdge(e)) {
    visited[e.getId()] = true;
    return true;
  } else {
    return false;
  }
}

bool Ant::visited(int i) {
  return visited[i];
}

void Ant::reset() {
  t = new Tree();
  int n = (graphSize * (graphSize - 1)) / 2;
  for(int i = 0; i < n; i++) {
    visited[i] = false;
  }
}

Tree* Ant::getTree() {
  return t;
}

int Ant::getSolutionCost() {
  return t->totalCost();
}
