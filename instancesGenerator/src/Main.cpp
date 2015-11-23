#include <iostream>
#include <cstdlib>
#include "Generator.hpp"
#include "SaveInstance.hpp"

using namespace std;

void freeMemory(int **dd, int size) {
  for(int i = 0; i < size; i++) {
    delete [] dd[i];
  }
  delete [] dd;
}

int main(int argc, char **argv) {

  int n, d;

  if(argc == 3) {
    n = atoi(argv[1]);
    d = atoi(argv[2]);
  } else {
    cout << "Send n and d as parameter!\n";
    return 1;
  }

  Generator g(n);
  SaveInstance s;

  int **dd = g.generateEuclideanDistances();
  s.save("[EUC]", dd, n, d, g);
  freeMemory(dd, g.size());

  dd = g.generateNonEuclideanDistances();
  s.save("[NEU]", dd, n, d, g);
  freeMemory(dd, g.size());

  return 0;
}
