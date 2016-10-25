#include <bits/stdc++.h>
using namespace std;

bool canPairs(int arr[], int size, int k)
{
    if (size&1) return false;
    
    unordered_map<int, int> freq;
    for(int i = 0; i < size; ++i)
        freq[arr[i]%k]++;
        
    for(int i = 0; i < size; ++i)
    {
        int rem = arr[i] % k;
        if (rem *2 == k)
        {
            if (freq[rem] %2 != 0)
                return false;
        }
        
        else if (freq[rem] != freq[k-rem])
            return false;
    }
}

/* Driver program to test above function */
int main()
{
    int arr[] =  {92, 75, 65, 48, 45, 35};
    int k = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    canPairs(arr, n, k)? cout << "True": cout << "False";
    return 0;
}