#ifndef UTIL_H
#define UTIL_H

#include "Edge.h"

bool comp(const Edge &e1, const Edge &e2);

inline double fastPow(double a, double b) {
  union {
    double d;
    int x[2];
  } u = { a };
  u.x[1] = (int)(b * (u.x[1] - 1072632447) + 1072632447);
  u.x[0] = 0;
  return u.d;
}

inline int summation(int n) {
	return (n * (n - 1)) / 2;
}

#endif // UTIL_H
