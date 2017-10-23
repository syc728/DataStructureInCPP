#include <iostream>
#include "lqueue.h"

using namespace std;

int main()
{
    LinkedQueue<int> q;
    for(int i=0;i<10;i++)  
        q.Add(i);
    cout << q.Size() << endl;
    q.Print();
    return 0;
}