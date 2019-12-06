#include <iostream>
#include "btree.h"

using namespace std;

template <typename T>
void BTree<T>::insert(int value) {
    if (root == nullptr)
    {
        root = new Node<T>(this->degree, true);
        root->keys[0] = value;
        root->actualsize = 1;
    }
    else
    {
        if (root->actualsize == 2*this->degree-1)
        {
            Node<T> *newroot = new Node<T>(this->degree, false);
            newroot->childs[0] = root;
            newroot->splitnode(0F, root);
            int i = 0;

            if (newroot->keys[0] < value){
                ++i;
            }

            newroot->childs[i]->insertbasico(value);
            root = newroot;
        }
        else{
            root->insertbasico(value);
        }
    }
}