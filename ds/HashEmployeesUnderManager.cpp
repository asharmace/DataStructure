#include <bits/stdc++.h>
using namespace std;
void getManagerCount(unordered_map<string, string>& dataSet)
{
    unordered_map<string, int> empCount;
    for (auto a: dataSet)
    {
        auto b = empCount.find(a.second);
        if (b == empCount.end())
        {
            empCount.insert(make_pair(a.second, 1));
        }
        else
        {
            empCount[a.second] = (b->second) + 1;
        }
    }
    
    for (auto a : dataSet)
    {
        auto b = empCount.find(a.first);
        if (b == empCount.end())
        {
            cout << a.first << " 0" << endl ;
        }
        else
        {
            cout << b->first << " " << b->second << endl ;
        }
    }

}

int main()
{
    unordered_map<string, string> dataSet;
    dataSet.insert(make_pair("A", "C"));
    dataSet.insert(make_pair("B", "C"));
    dataSet.insert(make_pair("C", "F"));
    dataSet.insert(make_pair("D", "E"));
    dataSet.insert(make_pair("E", "F"));
    dataSet.insert(make_pair("F", "F"));
     
    getManagerCount(dataSet);
}