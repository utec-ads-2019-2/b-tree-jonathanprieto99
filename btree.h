#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class BTree {

    public:

    Node<T> *root;
    int degree;

    explicit BTree(int _degree){
        root = nullptr;
        this->degree = _degree;
    }

    void recorrer(){
        if (root != NULL){
            root->recorrer();
        }
    }

    Node<T>* buscar(int k){

        if (root == nullptr){
            return nullptr;
        }

        else{
            root->buscar(k);
        }
    return nullptr;
    }


    void insert(int value);
};

#endif