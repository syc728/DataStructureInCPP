#include <iostream>
#include <string>
#include "stack.h"

const int MaxLength = 64;
using namespace std;

void printConversion(int n)
{
    // YOUR TASK
    Stack<string> s(MaxLength);
    while(n)
    {
        int res = n%2;
        s.Add(to_string(res));
        n /= 2;
    }

    while(!s.IsEmpty())
    {
        cout << s.Top();
        string x = "";
        s.Delete(x);
    }
}

int main(){
    int number;
    cout << "Type a positive integer to convert:" << endl;
    cin >> number;
    if(number > 0)
    {
        cout << endl << "The binary equivalent is ";
        printConversion(number);
        cout << "." << endl;
    }
    else
    {
        cout << endl << "The number is not positive" << endl;
    }
}