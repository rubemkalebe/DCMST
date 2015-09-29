#include "Vertex.h"

Vertex::Vertex() {
    id = 0;
}

Vertex::Vertex(int id) {
    this->id = id;
}

int Vertex::getId() const {
    return id;
}

void Vertex::setId(int value) {
    id = value;
}
