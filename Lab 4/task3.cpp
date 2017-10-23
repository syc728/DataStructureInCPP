#include <iostream>

using namespace std;

int binarySearchItr(int * a, int from, int to, int k)
{
    while(from < to)
    {
        int mid = (from + to) / 2;
        if(a[mid] == k)
            return mid;
        else if(a[mid] > k)
            to = mid - 1;
        else
            from = mid + 1;
    }
    return -1;
}

int binarySearchRec(int * a, int from, int to, int k)
{
    if(from > to)
        return -1;
    int mid = (from + to) / 2;
    if(a[mid] == k)
        return mid;
    if(a[mid] > k)
        return binarySearchRec(a, from, mid-1, k);
    else
        return binarySearchRec(a, mid+1, to, k);
}

int main() 
{
    int arr[6] = {1, 2, 6, 8 ,9, 12};
    const int num1 = 9;
    const int num2 = 7;

    int pos1 = binarySearchItr(arr, 0, 5, num2);
    int pos2 = binarySearchRec(arr, 0, 5, num1);
    if(pos1 != -1)
        cout << endl << num1 << " is in position " << pos1 << endl;
    else
        cout << endl << num1 << " is not in the array" << endl;
    if(pos2 != -1)
        cout << endl << num2 << " is in position " << pos2 << endl;
    else
        cout << endl << num2 << " is not in the array" << endl;
    return 0;
}