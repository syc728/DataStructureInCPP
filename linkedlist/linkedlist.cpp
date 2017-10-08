#include "linkedlist.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedList<int> test;
    for(int i=1;i<=10;i++)
        test.insert(i,i);
    test.output();
    test.remove(4);
    test.output();
    cout << test.get(4) << endl;
    cout << test.find(5) << endl;
    test.output();
    cout << test.len() << endl;
    test.clear();
    cout << test.len() << endl;
    test.output();
    return 0;
}