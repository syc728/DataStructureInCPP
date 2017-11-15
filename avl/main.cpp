#include "avl.h"
#include <iostream>

using namespace std;

int main()
{
    AVL<int>* avl;
    int a[] = {15,6,18,3,7,17,20,2,4,13,9};
    for(int i=0;i<sizeof(a)/sizeof(int);i++)
        avl = avl->Insert(avl, a[i]);
    avl->inOrder(avl);
    cout << endl;

    int deletei;
    while(cin >> deletei)
    {
        avl = avl->Delete(avl, deletei);
        avl->inOrder(avl);
        cout << endl;
        avl->preOrder(avl);
        cout << endl;
    }
    return 0;
}
