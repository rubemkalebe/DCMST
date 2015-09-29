#include "Vertex.h"

Vertex::Vertex() {
    id = 0;
    degree = 0;
}

Vertex::Vertex(int id, int degree) {
    this->id = id;
    this->degree = degree;
}

int Vertex::getId() const {
    return id;
}

void Vertex::setId(int value) {
    id = value;
}

int Vertex::getDegree() const {
	return degree;
}

void Vertex::increaseDegree() {
	degree++;
}

void Vertex::decreaseDegree() {
	if(degree - 1 >= 0) {
		degree--;
	}
}