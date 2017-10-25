#include <iostream>
#include "Chain.h"

using namespace std;

int main()
{
    Chain<int> cl;
    for(int i=0;i<10;i++)
    {
        cl = cl.Insert(i, i);
    }
    
    cl.Output(cout);
    cout << endl;
    return 0;
}