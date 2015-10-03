#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include "Edge.h"
#include "Tree.h"
#include "SaveResults.h"

void SaveResults::writeAllResultsToFile(ISolution *solver) {
	std::string filename = std::string("results/") + typeid(*solver).name() + std::string(".out");
	std::ofstream out(filename.c_str());
	if(out.is_open()) {
		std::vector<Edge> *edges = solver->getBestTree()->getTree();
		out << "Menor custo: " << solver->getBestTree()->totalCost() << "\n";
		out << "Árvore de menor custo: ";
		for(Edge e : *edges) {
        	out << e.getInitial().getId() << "-" << e.getFinal().getId() << " ";
        }
        out << "\n";
        out << "Soluções válidas geradas: " << solver->getSolutions() << "\n";
        out << "Tempo total gasto na busca pela solução: " << solver->getExecutionTime() << "ms";
		out.close();
	}
}

void SaveResults::writeGraphDataToFile(ISolution *solver) {
	std::string filename = std::string("results/") + typeid(*solver).name() + std::string("Graph.out");
	std::ofstream out(filename.c_str());
	if(out.is_open()) {
		std::vector<Edge> *edges = solver->getBestTree()->getTree();
    out << solver->getBestTree()->totalCost() << "\n";
		for(Edge e : *edges) {
    	out << e.getInitial().getId() << " " << e.getFinal().getId() << "\n";
    }
		out.close();
	}
}
