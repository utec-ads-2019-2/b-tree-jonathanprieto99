#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include "btree.h"
using namespace std;

//class BTree;

template <typename T>
class Node{

public:
    unsigned int size; //t
    int actualsize; //n
    vector<unsigned int> keys; //*keys
    vector<Node<T>*> childs; //C
    bool isLeaf; //leaf


    Node(unsigned int size, bool isLeaf) : size(size), isLeaf(isLeaf) {
        keys.resize(size - 1);
        childs.resize(size);
        actualsize=0;
    }

    void insertbasico(int k);

    void splitnode(int i, Node<T> *y);

    void recorrer();

    Node<T>* buscar(int k);

};

#endif