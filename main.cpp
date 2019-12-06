#include <iostream>
#include "btree.h"

using namespace std;

int main() {
    BTree<int> arbol(3);
    arbol.insert(10);
    arbol.insert(20);
    arbol.insert(5);
    arbol.insert(6);
    arbol.insert(12);
    arbol.insert(30);
    arbol.insert(7);
    arbol.insert(17);

    cout << "Traversal del arbol: ";
    arbol.recorrer();

    int k = 6;

    if (arbol.buscar(k) != nullptr){
        cout <<"Existe!"<<endl;
    }

    else{
        cout <<"No Existe!"<<endl;
    }

    k = 15;

    if (arbol.buscar(k) != nullptr){
        cout <<"Existe!"<<endl;
    }

    else{
        cout <<"No Existe!"<<endl;
    }

    return 0;
}