#include <iostream>
#include "btree.h"


using namespace std;

int main() {
    BTree<int> arbol(3);
    arbol.insert(12);
    arbol.insert(15);
    arbol.insert(7);
    arbol.insert(9);
    arbol.insert(2);
    arbol.insert(13);
    arbol.insert(2);
    arbol.insert(1);
    arbol.insert(14);
    arbol.insert(6);

    cout << "Traversal del arbol: ";
    arbol.recorrer();

    int k = 2;

    if (arbol.buscar(k) != nullptr){
        cout <<"Existe: "<<k<<", en el arbol-b!"<<endl;
    }

    else{
        cout <<"No Existe: "<<k<<", en el arbol-b!"<<endl;
    }

    k = 11;

    if (arbol.buscar(k) != nullptr){
        cout <<"Existe: "<<k<<", en el arbol-b!"<<endl;
    }

    else{
        cout <<"No Existe: "<<k<<", en el arbol-b!"<<endl;
    }

    return 0;
}