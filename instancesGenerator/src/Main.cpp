#include <iostream>
#include <cstdlib>
#include "Generator.hpp"
#include "SaveInstance.hpp"

using namespace std;

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
  g.generatePoints();
  int **dd = g.generateDistances();

  SaveInstance s;
  s.save(dd, n, d, g);

  for(int i = 0; i < g.size(); i++) {
    delete [] dd[i];
  }

  delete [] dd;

  return 0;
}
