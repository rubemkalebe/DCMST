/*
 * funcoes.cpp
 * 		by Rubem Kalebe (2014)
 *
 * Descrição ...
 *
 * Informações relevantes ...
 */

#include "funcoes.hpp"

int fatorial(int x) {
	
	int a, fatx = 1;
	
	for (a = x; a > 1; a--) {
		fatx = fatx * a;
	}

	return fatx;

}
