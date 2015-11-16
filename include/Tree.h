#ifndef TREE_H
#define TREE_H

#include <vector>
#include "Edge.h"
#include "UnionFind.h"

class Tree {

private:

    std::vector<Edge> *tree;

    int *degree;

    UnionFind *uf;

    int _totalCost;

    static int vertexMax;

    static int degreeMax;

public:

    Tree();

    ~Tree();

    bool addEdge(Edge &e);

    void removeEdge();

    void update(Tree &t);

    std::vector<Edge>* getTree() const;

    void setTree(std::vector<Edge> *value);

    int *getDegree() const;

    int getDegree(int id) const;

    void setDegree(int *value);

    UnionFind *getUf() const;

    void setUf(UnionFind *value);

    int totalCost() const;

    void setTotalCost(int value);

    static int getVertexMax();

    static void setVertexMax(int value);

    static int getDegreeMax();

    static void setDegreeMax(int value);

    void reset();

private:

    void increaseDegree(int i, int j);

    void decreaseDegree(int i, int j);

};

#endif // TREE_H
