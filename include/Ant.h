#ifndef ANT_H
#define ANT_H

#include "Tree.h"

#include <vector>

using std::vector;

class Ant {

private:

  Tree t;

  bool *(_visited);

  int graphSize;

public:

  Ant(int graphSize);

  ~Ant();

  bool visit(Edge e);

  bool visited(int i);

  void reset();

  Tree getTree();

  int getSolutionCost();

};

#endif // ANT_H
