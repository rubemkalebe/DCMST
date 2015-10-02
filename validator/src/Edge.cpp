#include <iostream>
#include "Edge.h"

Vertex Edge::getInitial() const {
    return initial;
}

void Edge::setInitial(Vertex value) {
    initial = value;
}

Vertex Edge::getFinal() const {
    return final;
}

void Edge::setFinal(Vertex value) {
    final = value;
}

int Edge::getId() const {
    return id;
}

void Edge::setId(int value) {
    id = value;
}

int Edge::getCost() const {
    return cost;
}

void Edge::setCost(int value) {
    cost = value;
}

Edge::Edge() {
    id = 0;
    cost = 0;
}

Edge::Edge(Vertex &initial, Vertex &final, int id, int cost) {
    this->initial = initial;
    this->final = final;
    this->id = id;
    this->cost = cost;
}
