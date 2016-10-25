#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(int i)
{
    cout << i << endl;
}


void printMyPairs(pair<int, string> p)
{
    cout << p.first <<  " - " << p.second << endl;
}

int main()
{
    vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    
    for_each(myVec.begin(), myVec.end(), print);
    map <int, string> myMap;
    myMap.insert(make_pair(1, "Ashutosh"));
    myMap.insert(make_pair(2, "Ashutosh2"));
    myMap.insert(make_pair(3, "Ashutosh3"));
    
    for_each(myMap.begin(), myMap.end(), printMyPairs);
    // for_each(myMap.begin(), myMap.end(), printPairs);
    return 0;
}