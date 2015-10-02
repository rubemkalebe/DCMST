#include <iostream>
#include "Graph.h"
#include "LoadFile.h"
#include "CostMatrix.h"
#include "Validator.h"

using namespace std;

int main(int argc, char **argv) {

	if(argc == 3) {
		string pathInstance(argv[1]);
		string pathResults(argv[2]);
		LoadFile loader(pathInstance, pathResults);
		loader.readNetworkInfo();
		CostMatrix *costMatrix = new CostMatrix(Graph::getVertexMax());
		loader.readCostMatrix(costMatrix);

		Validator v(loader.readEdgesList());

		v.isCyclic() ? (cout << "(1) O grafo CONTEM ciclo\n") : (cout << "(1) O grafo eh aciclico\n");
		v.isConnected() ? (cout << "(2) O grafo eh conexo\n") : (cout << "(2) O grafo NAO eh conexo\n");
		v.checkDegreeConstrained() ? (cout << "(3) O grafo obedece as restricoes de grau\n")
				: (cout << "(3) O grafo NAO obedece as restricoes de grau\n");
		v.checkGraphCost(costMatrix, loader.readGraphCost()) ? (cout << "(4) O custo encontrado esta correto\n")
				: (cout << "(4) O custo encontrado NAO esta correto\n");

		delete costMatrix;
	} else {
		cout << "Essa versão so funciona a partir da leitura de dois arquivos: um da instancia e outro com os resultados!\n";
		cout << "\nExemplo de execucao: \"./Main ../instances/n5d2.in ../Graph.out\"" << endl;
	}

	return 0;
}
