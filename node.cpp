#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
void Node<T>::recorrer() {
    int i;
    for (i = 0; i < this->size; ++i) {
        if (!this->isLeaf){
            childs[i]->traverse();
        }
        cout<<" "<<keys[i];
    }

    if (!this->isLeaf){
        childs[i]->traverse();
    }
}

template <typename T>
Node<T>* Node<T>::buscar(int k) {
    int i=0;

    while(i< this->size and k>keys[i]){
        i++;
    }

    if(keys[i]==k){
        return this;
    }

    if(this->isLeaf){
        return nullptr;
    }

    return childs[i]->buscar(k);
}

template <typename T>
void Node<T>::insertbasico(int k)
{
    int i = this->actualsize-1;

    if (this->isLeaf){
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            --i;
        }
        keys[i+1] = k;
        this->actualsize = this->actualsize+1;
    }
    else{

        while (i >= 0 && keys[i] > k){
            i--;
        }

        if (this->childs[i+1]->actualsize == 2*this->size-1)
        {
            splitnode(i+1, this->childs[i+1]);
            if (keys[i+1] < k){
                i++;
            }
        }

        this->childs[i+1]->insertbasico(k);
    }
}

template <typename T>
void Node<T>::splitnode(int i, Node *y)
{
    Node *z = new Node(y->size, y->isLeaf);
    z->actualsize = this->size - 1;

    for (int j = 0; j < this->size-1; ++j){
        z->keys[j] = y->keys[j+this->size];
    }

    if (!y->isLeaf){
        for (int j = 0; j < this->size; ++j){
            z->childs[j] = y->childs[j+this->size];
        }
    }

    y->actualsize = this->size - 1;

    for (int j = this->actualsize; j >= i+1; --j){
        this->childs[j+1] = this->childs[j];
    }

    this->childs[i+1] = z;
    for (int j = this->actualsize-1; j >= i; --j){
        keys[j+1] = keys[j];
    }

    keys[i] = y->keys[this->size-1];
    this->actualsize = this->actualsize + 1;
}

