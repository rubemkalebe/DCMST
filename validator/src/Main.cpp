#include <iostream>
#include "Graph.h"
#include "LoadFile.h"
#include "CostMatrix.h"

using namespace std;

int main(int argc, char **argv) {

	if(argc == 3) {
		string pathInstance(argv[1]);
		LoadFile loader(pathInstance);
		loader.readNetworkInfo();
		CostMatrix *costMatrix = new CostMatrix(Graph::getVertexMax());
		loader.readCostMatrix(costMatrix);

		cout << "Menor custo: " << solver->getBestTree()->totalCost() << endl;
		cout << "Soluções válidas: " << solver->getSolutions() << endl;
		cout << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "ms" << endl;
		cout << "**Fim de execução**" << endl;
		delete costMatrix;
	} else {
		cout << "Essa versão só funciona a partir da leitura de um arquivo! " <<
				"Caso não tenha um arquivo, você pode enviar algum arquivo de teste padrão " <<
				"localizado na pasta instances/" << endl;
		cout << "\nExemplo de execução: \"./Main instances/n5d2.in\"" << endl;
	}

	return 0;
}
