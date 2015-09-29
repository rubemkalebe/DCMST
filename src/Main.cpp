#include <iostream>
#include "LoadFile.h"
#include "CostMatrix.h"
#include "SaveResults.h"
#include "Backtracking.h"

using namespace std;

int main(int argc, char **argv) {

	if(argc == 2) {
		string path(argv[1]);
		LoadFile loader(path);
		loader.readNetworkInfo();
		CostMatrix *costMatrix = new CostMatrix(Tree::getVertexMax());
		loader.readCostMatrix(costMatrix);
		ISolution *solver = new Backtracking(costMatrix);
		solver->findMinimum();
		SaveResults *saver = new SaveResults();
		saver->writeToFile(solver);
		cout << "Menor custo: " << solver->getBestTree()->totalCost() << endl;
		cout << "Soluções válidas: " << solver->getSolutions() << endl;
		cout << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "ms" << endl;
		cout << "**Fim de execução**" << endl;
		delete costMatrix;
		delete solver;
		delete saver;
	} else {
		cout << "Essa versão só funciona a partir da leitura de um arquivo! " <<
				"Caso não tenha um arquivo, você pode enviar algum arquivo de teste padrão " <<
				"localizado na pasta instances/" << endl;
		cout << "\nExemplo de execução: \"./Main instances/n5d2.in\"" << endl;
	}

	return 0;
}
