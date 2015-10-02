#ifndef COSTMATRIX_H
#define COSTMATRIX_H

class CostMatrix {

private:

    int **matrix;
    int _size;

public:

    CostMatrix(int n);

    ~CostMatrix();

    int **getMatrix() const;

    void setMatrix(int **value);

    int getElement(int i, int j);

    void setElement(int i, int j, int x);

    int size();

};

#endif // COSTMATRIX_H
