#include <iostream>
#include "Tree.h"

int Tree::vertexMax;
int Tree::degreeMax;

std::vector<Edge>* Tree::getTree() const
{
    return tree;
}

void Tree::setTree(std::vector<Edge> *value)
{
    tree = value;
}

int *Tree::getDegree() const
{
    return degree;
}

void Tree::setDegree(int *value)
{
    degree = value;
}

UnionFind *Tree::getUf() const
{
    return uf;
}

void Tree::setUf(UnionFind *value)
{
    uf = value;
}

int Tree::totalCost() const
{
    return _totalCost;
}

void Tree::setTotalCost(int value)
{
    _totalCost = value;
}

int Tree::getVertexMax()
{
    return vertexMax;
}

void Tree::setVertexMax(int value)
{
    vertexMax = value;
}

int Tree::getDegreeMax()
{
    return degreeMax;
}

void Tree::setDegreeMax(int value)
{
    degreeMax = value;
}

void Tree::increaseDegree(int i, int j)
{
    degree[i] += 1;
    degree[j] += 1;
}

void Tree::decreaseDegree(int i, int j)
{
    degree[i] -= 1;
    degree[j] -= 1;
}

Tree::Tree() {
    tree = new std::vector<Edge>();
    degree = new int[vertexMax];
    for(int i = 0; i < vertexMax; i++) {
        degree[i] = 0;
    }
    uf = new UnionFind(vertexMax);
    _totalCost = 0;
}

Tree::~Tree() {
    delete tree;
    delete [] degree;
}

bool Tree::addEdge(Edge &e)
{
    if(((degree[e.getInitial().getId()-1] < degreeMax) && (degree[e.getFinal().getId()-1] < degreeMax))
            && (!uf->sameComponent(e.getInitial().getId(), e.getFinal().getId()))) {
        tree->push_back(e);
        _totalCost += e.getCost();
        increaseDegree(e.getInitial().getId()-1, e.getFinal().getId()-1);
        uf->make_union(e.getInitial().getId(), e.getFinal().getId());
        return true;
    } else {
        return false;
    }
}

void Tree::removeEdge()
{
    decreaseDegree(tree->at(tree->size()-1).getInitial().getId()-1,
            tree->at(tree->size()-1).getFinal().getId()-1);
    _totalCost -= tree->at(tree->size()-1).getCost();
    tree->pop_back();
    delete uf;
    uf = new UnionFind(vertexMax);
    for(Edge e : *tree) {
        uf->make_union(e.getInitial().getId(), e.getFinal().getId());
    }
}

void Tree::update(Tree &t)
{
    delete tree;
    std::vector<Edge> *eTemp = t.getTree();
    tree = new std::vector<Edge>();
    for(Edge e : *eTemp) {
        tree->push_back(e);
    }
    int *vTemp = t.getDegree();
    for(int i = 0; i < vertexMax; i++) {
        degree[i] = vTemp[i];
    }
    this->uf = t.getUf();
    this->_totalCost = t.totalCost();
}

void Tree::reset() {
  tree = new std::vector<Edge>();
  degree = new int[vertexMax];
  for(int i = 0; i < vertexMax; i++) {
      degree[i] = 0;
  }
  uf = new UnionFind(vertexMax);
  _totalCost = 0;
}

int Tree::getDegree(int id) const {
    return degree[id-1];
}
