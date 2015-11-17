#include <iostream>
#include "LoadFile.h"
#include "CostMatrix.h"
#include "SaveResults.h"
#include "Backtracking.h"
#include "OptimizedBacktracking.h"
#include "OrderedOptimizedBacktracking.h"
#include "AntSystemOnEdges.h"

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
		saver->writeAllResultsToFile(solver);
		saver->writeGraphDataToFile(solver);
		cout << "--Backtracking--" << endl;
		cout << "Menor custo: " << solver->getBestTree()->totalCost() << endl;
		cout << "Arvore: ";
		std::vector<Edge> *edges = solver->getBestTree()->getTree();
		for(Edge e : *edges) {
			cout << e.getInitial().getId() << "-" << e.getFinal().getId() << " ";
		}
		cout << endl;
		cout << "Soluções válidas: " << solver->getSolutions() << endl;
		cout << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "s" << endl;
		cout << "**Fim de execução**" << endl;

		/*solver = new OptimizedBacktracking(costMatrix);
		solver->findMinimum();
		saver->writeAllResultsToFile(solver);
		saver->writeGraphDataToFile(solver);
		cout << "\n--Backtracking com otimizacao--" << endl;
		cout << "Menor custo: " << solver->getBestTree()->totalCost() << endl;
		cout << "Arvore: ";
		edges = solver->getBestTree()->getTree();
		for(Edge e : *edges) {
			cout << e.getInitial().getId() << "-" << e.getFinal().getId() << " ";
		}
		cout << endl;
		cout << "Soluções válidas: " << solver->getSolutions() << endl;
		cout << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "s" << endl;
		cout << "**Fim de execução**" << endl;

		solver = new OrderedOptimizedBacktracking(costMatrix);
		solver->findMinimum();
		saver->writeAllResultsToFile(solver);
		saver->writeGraphDataToFile(solver);
		cout << "\n--Backtracking com otimizacao e ordenacao do espaco de busca--" << endl;
		cout << "Menor custo: " << solver->getBestTree()->totalCost() << endl;
		cout << "Arvore: ";
		edges = solver->getBestTree()->getTree();
		for(Edge e : *edges) {
			cout << e.getInitial().getId() << "-" << e.getFinal().getId() << " ";
		}
		cout << endl;
		cout << "Soluções válidas: " << solver->getSolutions() << endl;
		cout << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "s" << endl;
		cout << "**Fim de execução**" << endl;*/

		solver = new AntSystemOnEdges(costMatrix);
		solver->findMinimum();
		saver = new SaveResults();
		saver->writeAllResultsToFile(solver);
		saver->writeGraphDataToFile(solver);
		cout << "--Ant system--" << endl;
		cout << "Menor custo: " << solver->getBestTree()->totalCost() << endl;
		cout << "Arvore: ";
		edges = solver->getBestTree()->getTree();
		for(Edge e : *edges) {
			cout << e.getInitial().getId() << "-" << e.getFinal().getId() << " ";
		}
		cout << endl;
		cout << "Soluções válidas: " << solver->getSolutions() << endl;
		cout << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "s" << endl;
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
