#include "CostMatrix.h"

int **CostMatrix::getMatrix() const {
    return matrix;
}

void CostMatrix::setMatrix(int **value) {
    matrix = value;
}

int CostMatrix::getElement(int i, int j) {
    return matrix[i][j];
}

void CostMatrix::setElement(int i, int j, int x) {
    matrix[i][j] = x;
}

int CostMatrix::size() {
    return _size;
}

CostMatrix::CostMatrix(int n) {
    if(n > 0) {
        this->_size = n;
        matrix = new int*[n];
        for(int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
    }
}

CostMatrix::~CostMatrix() {
    for(int i = 0; i < _size; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}
