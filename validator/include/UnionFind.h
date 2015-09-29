#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {

private:

    int *id;

    int *rank;

    int _size;

public:

    UnionFind(int n);

    ~UnionFind();

    void destroy();

    int findSet(int x);

    bool sameComponent(int x, int y);

    void make_union(int x, int y);

    int size();
};

#endif // UNIONFIND_H
