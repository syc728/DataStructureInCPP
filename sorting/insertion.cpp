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
void insertion(T *a, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            swap(a[j - 1], a[j]);
            j--;
        }
    }
}

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(a) / sizeof(a[0]);
    insertion<int>(a, len);
    output<int>(a, len);
    return 0;
}