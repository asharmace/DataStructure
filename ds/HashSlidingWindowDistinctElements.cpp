#include <bits/stdc++.h>
using namespace std;
void countDistinct(int arr[], int size, int k)
{
    unordered_map<int,int> m;
    
    for (int i = 0; i < k; ++i) 
        m[arr[i]]++;
    int distinct = m.size();
    
    cout << distinct << endl;
    //for (auto a : m) cout << "\t" << a.first << " " << a.second << endl;
    for (int i = k ; i < size; ++i)
    {
        if (m[arr[i-k]] == 1)
        {
            //cout << "\terasing " <<  arr[i-k] << endl;
            m.erase(arr[i-k]);
            distinct--;
        }
        else
        {
            m[arr[i-k]]--;
        }
        
        m[arr[i]]++;
        if (m[arr[i]] == 1)
        {
            distinct++;
        }
        
        cout << distinct << endl;
        //for (auto a : m) cout << "\t" << a.first << " " << a.second << endl;
    }

}


int main()
{
    int arr[] =  {1, 2, 1, 3, 4, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    countDistinct(arr,size, k);
}
