#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge {

private:

    Vertex initial;

    Vertex final;

    int id;

    int cost;

public:

    Edge();

    Edge(Vertex &initial, Vertex &final, int id, int cost);

    Vertex getInitial() const;

    void setInitial(const Vertex &value);

    Vertex getFinal() const;

    void setFinal(const Vertex &value);

    int getId() const;

    void setId(int value);

    int getCost() const;

    void setCost(int value);
};

#endif // EDGE_H
