#include <iostream>

using namespace std;

template <class T>
void output(T *a, int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <class T>
void selection(T *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[minPos])
                minPos = j;
        }

        if (minPos != i)
            swap(a[i], a[minPos]);
    }
}

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(a) / sizeof(a[0]);
    selection<int>(a, len);
    output<int>(a, len);
    return 0;
}