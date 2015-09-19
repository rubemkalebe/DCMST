#include "EuclideanDistance.hpp"

int quad(int x) {
  return double(x*x);
}

int distance(Point p, Point q) {
  return sqrt(quad(q.getX() - p.getX()) + quad(q.getY() - p.getY()));
}
