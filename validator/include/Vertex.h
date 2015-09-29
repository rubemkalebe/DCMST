#ifndef VERTEX_H
#define VERTEX_H

class Vertex {

private:

    int id;

    int degree;

public:

    Vertex();

    Vertex(int id, int degree);

    int getId() const;

    void setId(int value);

    int getDegree() const;

    void increaseDegree();

    void decreaseDegree();

};

#endif // VERTEX_H
