#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<long long> sequence;

inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}
// n^3
long long maxSubSumN3()
{
    long long maxSum =0;
    for (long long i = 0; i < sequence.size(); i++)
        for (long long j = i; j < sequence.size(); j++)
        {
            long long thisSum = 0;
            for (long long k = i; k <= j; k++)
                thisSum += sequence[k];
                if (thisSum > maxSum) maxSum = thisSum;
        }
    return maxSum;
}

// n^2
long long maxSubSumN2()
{
    long long maxSum =0;
    for (long long i = 0; i < sequence.size(); i++)
    {
        long long thisSum = 0;
        for (long long j = i; j < sequence.size(); j++)
        {
            thisSum += sequence[j] ;
            if (thisSum > maxSum) maxSum = thisSum;
        }
    }
    return maxSum;
}

// n^logn
long long maxSubSumNlogn(long long left, long long right)
{
    long long maxSum = 0;
    if(left == right)
        return sequence[left]>0 ? sequence[left] : 0;
    
    int mid = (left + right) / 2;
    int leftSum = maxSubSumNlogn(left, mid);
    int rightSum = maxSubSumNlogn(mid+1, right);

    int maxleft = 0, lefttmp = 0;
    for(int i = mid; i >= left; i--){
        lefttmp += sequence[i];
        maxleft = max(maxleft, lefttmp);
    }

    int maxright = 0, righttmp = 0;
    for(int i = mid + 1;i <= right; i++){
        righttmp += sequence[i];
        maxright = max(maxright, righttmp);
    }
    maxSum = maxleft + maxright;

    maxSum = max(maxSum, leftSum);
    maxSum = max(maxSum, rightSum);

    return maxSum;
}

// n
long long maxSubSumN()
{
    long long maxSum = 0;
    long long tmp = 0;
    for(long long i = 0; i < sequence.size(); i++)
    {
        if(tmp > 0)
            tmp += sequence[i];
        else
            tmp = sequence[i];
        maxSum = max(tmp, maxSum);
    }
    return maxSum;
}

int main()
{
    const int maxSize = 10;
    ifstream infile(to_string(maxSize)+".txt");
    sequence.reserve(maxSize);
    long long tmp;
    while(infile >> tmp)
        sequence.push_back(tmp);
    clock_t begin_time = clock();
    long long res = maxSubSumN3();
    clock_t end_time = clock();
    cout << "N^3 Result: " << res << endl;
    cout << "N^3 Time: " << float(end_time - begin_time) / CLOCKS_PER_SEC << endl;

    begin_time = clock();
    res = maxSubSumN2();
    end_time = clock();
    cout << "N^2 Result: " << res << endl;
    cout << "N^2 Time: " << float(end_time - begin_time) / CLOCKS_PER_SEC << endl;

    begin_time = clock();
    res = maxSubSumNlogn(0, sequence.size()-1);
    end_time = clock();
    cout << "Nlogn Result: " << res << endl;
    cout << "Nlogn Time: " << float(end_time - begin_time) / CLOCKS_PER_SEC << endl;

    begin_time = clock();
    res = maxSubSumN();
    end_time = clock();
    cout << "N Result: " << res << endl;
    cout << "N Time: " << float(end_time - begin_time) / CLOCKS_PER_SEC << endl;
    return 0;
}