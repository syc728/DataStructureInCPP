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
void merge(T *a, int left, int mid, int right)
{
    if(a[mid + 1] >= a[mid])
        return;
    int len = right - left + 1;
    int *tmp = new int[len];

    int i = left, j = mid + 1;
    int cnt = 0;

    while(i <= mid && j <= right)
    {
        if(a[i] < a[j])
            tmp[cnt++] = a[i++];
        else
            tmp[cnt++] = a[j++];
    }

    while(i <= mid)
        tmp[cnt++] = a[i++];
    
    while(j <= right)
        tmp[cnt++] = a[j++];

    for(int k = left; k <= right; k++)
    {
        a[k] = tmp[k-left];
    }
    delete[] tmp;
}

template <class T>
void merge_sort(T *a, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1};
    int len = sizeof(a) / sizeof(a[0]);
    merge_sort<int>(a, 0, len-1);
    output<int>(a, len);
    return 0;
}