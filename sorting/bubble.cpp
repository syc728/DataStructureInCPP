#include <iostream>
#include <vector>

using namespace std;

template<class T>
void output(T* a, int size)
{
    for(int i=0;i<size;i++)
        cout << a[i] << " ";
    cout << endl;
}

template<class T>
void bubblesort(T* a, int size)
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size-i;j++)
            if(a[j] > a[j+1])
                swap(a[j+1], a[j]);
}

int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1};
    int len = sizeof(a) / sizeof(a[0]);
    bubblesort<int>(a, len);
    output<int>(a, len);
    return 0;
}