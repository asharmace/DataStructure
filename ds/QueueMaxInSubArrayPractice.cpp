#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    deque<int> dq(k);
    int i = 0;
    
    for (; i < k; ++i)
    {
        while (!dq.empty() && arr[i] <= arr[dq.back()])
            dq.pop_back();
            
        dq.push_back(i);
    }
    
    for(; i < n; ++i)
    {
        cout << arr[dq.front()] << " ";
        
        while (!dq.empty() && dq.front() <= i -k)
            dq.pop_front();
            
        while (!dq.empty() && arr[i] <= arr[dq.back()])
            dq.pop_back();
            
        dq.push_back(i);
    }
    cout << arr[dq.front()] << endl;
}


// Driver program to test above functions
int main()
{
    int arr[] = {12, 1, 78,15, 90, 57, 89, 56, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}