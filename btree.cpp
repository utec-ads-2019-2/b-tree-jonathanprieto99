#include <iostream>
#include "btree.h"

using namespace std;

template <typename T>
void BTree<T>::insert(int value) {
    if (root == nullptr)
    {
        root = new Node(this->degree, true);
        root->keys[0] = value;
        root->n = 1;
    }
    else
    {
        if (root->n == 2*-1)
        {
            Node newroot = new Node(this->degree, false);
            newroot->C[0] = root;
            newroot->splitnode(0, root);
            int i = 0;

            if (newroot->keys[0] < value){
                ++i;
            }

            newroot->C[i]->insertbasico(value);
            root = newroot;
        }
        else{
            root->insertbasico(value);
        }
    }
}