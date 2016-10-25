#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{

    vector<int> myVec;
    map<int, int> myMap;
    
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    
    myMap.insert(make_pair(1,10));
    myMap.insert(make_pair(2,20));
    myMap.insert(make_pair(3,30));
    myMap.insert(make_pair(4,40));
    
    if (find(myVec.begin(),myVec.end(), 3) != myVec.end())
        cout << "3 is present in myVec" << endl;
        
    if (myMap.find(3) != myMap.end())
        cout << " value at 3 is " << endl; //<< find(myMap.begin(), myMap.end(), 3)->second << endl;
    
    return 0;
     
}