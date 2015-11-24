#include <iostream>
#include <fstream>

using namespace std;

void foo(int a, int &menor) {
  if(a < menor || menor == 0) {
    menor = a;
  }
}

int main(int argc, char const *argv[]) {

  int r;
  double t;
  int menor = 0;
  double mediaTempo = 0.0;
  int i = 0;

  ifstream in("output.out");

  while(in >> r >> t) {
    foo(r, menor);
    mediaTempo += t;
    i++;
  }

  mediaTempo /= i;

  cout << "Menor: " << menor << endl;
  cout << "Tempo medio: " << fixed << mediaTempo << endl;

  return 0;
}
