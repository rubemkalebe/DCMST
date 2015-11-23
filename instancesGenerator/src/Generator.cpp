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

int** Generator::generateEuclideanDistances() {
  int **d = new int*[n];
  generatePoints();
  for(int i = 0; i < n; i++) {
    d[i] = new int[n];
    for(int j = i; j < n; j++) {
      d[i][j] = distance(v[i], v[j]);
    }
  }
  return d;
}

int** Generator::generateNonEuclideanDistances() {
  int **d = new int*[n];
  srand((unsigned int) time(NULL));

  for(int i = 0; i < n; i++) {
    d[i] = new int[n];
  }

  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      if(i == j) {
        d[i][j] = 0;
      } else {
        int x = (rand() % 100) + 1;
        d[i][j] = x;
        d[j][i] = x;
      }
    }
  }

  std::cout << "NEU\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << d[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  return d;
}
