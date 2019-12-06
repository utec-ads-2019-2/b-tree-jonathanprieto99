#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
void Node<T>::recorrer() {
    int i;
    for (i = 0; i < this->actualsize; ++i) {
        if (!this->isLeaf){
            this->childs[i]->recorrer();
        }
        cout<<" "<<this->keys[i];
    }

    if (!this->isLeaf){
        this->childs[i]->recorrer();
    }
}

template <typename T>
Node<T>* Node<T>::buscar(int k) {
    int i=0;

    while(i< this->actualsize and k>keys[i]){
        ++i;
    }

    if(this->keys[i]==k){
        return this;
    }

    if(this->isLeaf){
        return nullptr;
    }

    return this->childs[i]->buscar(k);
}

template <typename T>
void Node<T>::insertbasico(int k)
{
    int i = this->actualsize-1;

    if (this->isLeaf){
        while (i >= 0 && this->keys[i] > k)
        {
            this->keys[i+1] = this->keys[i];
            --i;
        }
        this->keys[i+1] = k;
        ++this->actualsize;
    }
    else{

        while (i >= 0 && this->keys[i] > k){
            --i;
        }

        if (this->childs[i+1]->actualsize == 2*this->size-1)
        {
            splitnode(i+1, this->childs[i+1]);
            if (this->keys[i+1] < k){
                ++i;
            }
        }

        this->childs[i+1]->insertbasico(k);
    }
}

template <typename T>
void Node<T>::splitnode(int i, Node *y)
{
    Node<T> *z = new Node<T>(y->size, y->isLeaf);
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
        this->keys[j+1] = this->keys[j];
    }

    this->keys[i] = y->keys[this->size-1];
    ++this->actualsize;
}

