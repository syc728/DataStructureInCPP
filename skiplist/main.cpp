#include "skiplist.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand((unsigned)time(NULL));

    skipList<int,int> *s = new skipList<int, int>(4);

    for(int i=0;i<16;i++)
        s->insertNode(i, i);
    s->display();
    
    s->deleteNode(15);
    s->display();

    std::cout << s->findKey(15) << std::endl;
    std::cout << s->findKey(0) << std::endl;

    //delete s;

    return 0;
}