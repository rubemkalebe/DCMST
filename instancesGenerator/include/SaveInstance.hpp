#ifndef SAVE_INSTANCE_HPP
#define SAVE_INSTANCE_HPP

#include <iostream>
#include "Generator.hpp"

class SaveInstance {

public:

  void save(std::string prefix, int **dd, int n, int d, Generator &g);

};

#endif // SAVE_INSTANCE_HPP
