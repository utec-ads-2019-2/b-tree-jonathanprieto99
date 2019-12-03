#include <iostream>
#include "node.h"

using namespace std;

template <typename T>

void Node<T>::traverse() {
    for (int i = 0; i < this->size; ++i) {
        if (this->isLeaf==false){
            childs[i]->traverse();
        }
        cout<<" "<<keys[i];
    }

    if (this->isLeaf==false){
        childs[i]->traverse();
    }
}

template <typename T>
Node<T> *Node<T>::search(int k) {
    int i=0;

    while(i<this->size and k>keys[i]){
        i++;
    }

    if(keys[i]==k){
        return this;
    }

    if(this->isLeaf==true){
        return nullptr;
    }

    return childs[i]->search(k);
}

