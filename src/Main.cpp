#include <iostream>
//#include "LoadFile.h"
#include "CostMatrix.h"
#include "Backtracking.h"

using namespace std;

int main(int argc, char **argv) {

	cout << "Hello\n";

	/*if(argc > 0) {
		LoadFile loader(argv[1]);
		loader.readNetworkInfo();
		CostMatrix costMatrix(Tree::getVertexMax());
		loader.readCostMatrix(costMatrix);
		ISolution *solver = new Backtracking(costMatrix);
		solver->findMinimum();
		/*WriteResultsToOUT writer = new WriteResultsToOUT();
		writer.writeToFile(best);*/
		/*System.out.println("Menor custo: " + best.getBest().totalCost());
		System.out.println("Soluções válidas: " + best.getSolutions());
		System.out.println("Tempo total gasto na busca pela solução: " +
        		best.getExecutionTime() + "ms");
		System.out.println("**Fim de execução**");	*/
	/*} else {
		cout << "Essa versão só funciona a partir da leitura de um arquivo! " <<
				"Caso não tenha um arquivo, você pode enviar o arquivo de teste padrão " <<
				"localizado em tests/in1.in" << endl;
	}*/

	return 0;
}