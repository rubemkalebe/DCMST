#include <iostream>
#include <fstream>
#include <vector>
#include "Edge.h"
#include "Tree.h"
#include "SaveResults.h"

void SaveResults::writeToFile(ISolution *solver) {
	std::string filename = "BestSolution.out";
	std::ofstream out(filename.c_str());
	if(out.is_open()) {
		std::vector<Edge> *edges = solver->getBestTree()->getTree();
		//std::cout << solver->getBestTree()->totalCost() << "\n";
		out << "Menor custo: " << solver->getBestTree()->totalCost() << "\n";
		out << "Árvore de menor custo: ";
		for(Edge e : *edges) {
        	out << e.getInitial().getId() << "-" << e.getFinal().getId() << " ";
        }
        out << "\n";
        out << "Soluções válidas geradas: " << solver->getSolutions() << "\n";
        out << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "ms";
		out.close();
		//delete edges;
	}
}