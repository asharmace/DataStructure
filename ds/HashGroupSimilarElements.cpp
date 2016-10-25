#include <bits/stdc++.h>
using namespace std;
void groupElements(int arr[], int size)
{
    vector<int> uniqueArr(size, 0);
    int uniqueIndex = 0;
    unordered_map<int, int> m;
    
    for (int i = 0; i < size; ++i)
    {
        if (m.find(arr[i]) == m.end())
        {
            uniqueArr[uniqueIndex] = arr[i];
            uniqueIndex++;
        }
        m[arr[i]]++;
    }
    
    for (int i = 0; i < uniqueIndex; ++i)
    {
        auto it = m.find(uniqueArr[i]);
        for (int j =0; j < it->second; ++j)
            cout << it->first << " ";
    }
    cout << endl;

}

/* Driver program to test above function */
int main()
{
    int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    groupElements(arr, n);
    return 0;
}