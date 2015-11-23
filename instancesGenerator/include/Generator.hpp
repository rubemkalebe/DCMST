#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <cstdlib>
#include <ctime>
#include <vector>
#include "Point.hpp"
#include "EuclideanDistance.hpp"

class Generator {

private:

  std::vector<Point> v;
  int n;

public:

  Generator(int n) {
    this->n = n;
  }

  std::vector<Point> getV() {
    return v;
  }

  int size() {
    return n;
  }

  void generatePoints();

  int** generateEuclideanDistances();

  int** generateNonEuclideanDistances();

};

#endif //GENERATOR_HPP
