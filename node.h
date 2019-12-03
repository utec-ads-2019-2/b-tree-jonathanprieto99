#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include "btree.h"
using namespace std;

template <typename T>
class Node: {
private:
    unsigned int size; //Tamano del nodo
    int actualsize; //Tamano Actual del nodo
    vector<unsigned int> keys; //Vector con las llaves
    vector<Node<T>*> childs; //Vector de punteros a los nodos hijo
    bool isLeaf; //Es hoja o no

public:
    Node(unsigned int size, bool isLeaf) : size(size), isLeaf(isLeaf) {
        keys.resize(size - 1);
        childs.resize(size);
        actualsize=0;
    }

    void insertNonFull(int k);

    void splitChild(int i, Node *y);

    void traverse();

    Node *search(int k);

    friend class BTree;
};

#endif