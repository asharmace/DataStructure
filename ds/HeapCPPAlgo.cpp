#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int arr [] = {15, 35, 24, 30, 23};
    vector<int> v( arr, arr+5);
    
    make_heap(v.begin(), v.end());
    
    for (auto a: v) cout << a << " ";
    cout << endl;
    pop_heap(v.begin(), v.end());
    for (auto a: v) cout << a << " ";
    cout << endl;
    v.pop_back();
    for (auto a: v) cout << a << " ";
    cout << endl;
    
    
}