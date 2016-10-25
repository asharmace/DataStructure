#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int>& v, int m)
{
    int result;
    make_heap(v.begin(), v.end());
    
    while(m--)
    {
        int max = v.front();
        pop_heap(v.begin(), v.end());
        v.pop_back();
        
        result += max;
        max--;
        if (max)
        {
            v.push_back(max);
            push_heap(v.begin(), v.end());
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
        
    cout << getMax(v, m) << endl;
}


