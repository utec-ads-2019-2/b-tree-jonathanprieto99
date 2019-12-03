#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int degree;

    public:
        BTree(unsigned int degree) : degree(degree), root(nullptr) {};

        void traverse()
        {
            if (root != nullptr){
                root->traverse();
            }
        }

        Node* search(int k)
        {
            if (root== nullptr){
                return nullptr;
            }
            else {
                return root->search(k);
            }
        }

        void insert(int k, T data);
};

#endif