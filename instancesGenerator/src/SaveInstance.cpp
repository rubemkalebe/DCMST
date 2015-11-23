#include "SaveInstance.hpp"

#include <iostream>
#include <fstream>

void SaveInstance::save(std::string prefix, int **dd, int n, int d, Generator &g) {
  std::string path = "../instances/" + prefix + "n" + std::to_string(n);
  path += "d" + std::to_string(d) + ".in";
  std::ofstream out(path);

  out << n << ' ' << d << "\n";
  for(int i = 0; i < g.size(); i++) {
    for(int j = i; j < g.size(); j++) {
      if(dd[i][j] != 0) out << dd[i][j] << ' ';
    }
    if(i < g.size()-1) out << std::endl;
  }

  out.close();
}
