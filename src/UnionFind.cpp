#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind(int n) {
    _size = n+1;
    id = new int[n+1];
    rank = new int[n+1];

    // Make set
    for(int i = 0; i < n+1; i++) {
        id[i] = i;
        rank[i] = 0;
    }
}

void UnionFind::destroy() {
    delete [] id;
    delete [] rank;
}

UnionFind::~UnionFind() {
    destroy();
}

int UnionFind::findSet(int x) {
    /*while(x != id[x]) {
        id[x] = id[id[x]];  // Path compression by halving (reduz a altura para metade)
        x = id[x];
    }
    return x;*/
    int root = x;
        while (root != id[root])
            root = id[root];
        while (x != root) {
            int newp = id[x];
            id[x] = root;
            x = newp;
        }
        return root;
}

bool UnionFind::sameComponent(int x, int y) {
    return findSet(x) == findSet(y);
}

int UnionFind::size() {
    return _size;
}

void UnionFind::make_union(int x, int y) {
    int i = findSet(x);
    int j = findSet(y);
    if(i == j) {
        return;
    }
    /* Faz a raiz da árvore com menor número de elementos apontar para a raiz da
       árvore com maior número de elementos. */
    if (rank[i] < rank[j]) {
        id[i] = j;
    } else if (rank[i] > rank[j]) {
        id[j] = i;
    } else {
        id[j] = i;
        rank[i]++;
    }
    _size--;
}
