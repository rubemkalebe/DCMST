#include "Generator.hpp"
#include <iostream>

void Generator::generatePoints() {
  const int min = 1;
  const int max = 100;
  srand((unsigned int) time(NULL));
  for(int i = 0; i < n; i++) {
    Point p((rand() % max + min), (rand() % max + min));
    std::cout << p.getX() << " " << p.getY() << "\n";
    v.push_back(p);
  }
}

int** Generator::generateDistances() {
  int **d = new int*[n];
  for(int i = 0; i < n; i++) {
    d[i] = new int[n];
    for(int j = i; j < n; j++) {
      d[i][j] = distance(v[i], v[j]);
    }
  }
  return d;
}
