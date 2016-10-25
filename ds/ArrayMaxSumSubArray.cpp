#include <iostream>
using namespace std;

int maxSubArraySum(int* arr, int size)
{
    int maxSum = arr[0];
    int sumTillNow = arr[0];
    int start =0, end = 0;
    for (int i = 1; i < size; ++i)
    {
        sumTillNow += arr[i];
        if (maxSum < sumTillNow)
        {
            maxSum = sumTillNow;
            end = i;
            start = currStart;
        }
        if (sumTillNow < 0)
        {
            sumTillNow = 0;
            currStart = i+1;
        }
            
    }
    return maxSum;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is \n" << max_sum << endl;
    return 0;
}