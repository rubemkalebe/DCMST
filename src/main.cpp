/*
 * main.cpp
 * 		by Rubem Kalebe (2014)
 *
 * Descrição ...
 *
 * Informações relevantes ...
 */

#include <iostream>
#include "funcoes.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

	int b;
	
	cout << "Valor para calcular o fatorial: ";
	cin >> b;
	
	cout << endl << "O fatorial de " << b << " = " << fatorial(b) << endl;
	
	return 0;

}