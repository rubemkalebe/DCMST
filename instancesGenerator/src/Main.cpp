#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Generator.hpp"

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

  string path = "../instances/n" + to_string(n);
  path += "d" + to_string(d) + ".in";
  ofstream out(path);

  out << n << ' ' << d << "\n";
  for(int i = 0; i < g.size(); i++) {
    for(int j = 0; j < g.size(); j++) {
      if(dd[i][j] != 0) out << dd[i][j] << ' ';
    }
    if(i < g.size()-1) out << endl;
  }

  for(int i = 0; i < g.size(); i++) {
    delete [] dd[i];
  }

  delete [] dd;

  return 0;
}
