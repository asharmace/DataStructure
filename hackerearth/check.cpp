#include<stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

void getAllSubstrings(vector<string>& substrings, const std::string& str)
{
    const size_t size = str.size();
    substrings.push_back("");
    stringstream ss;
    for (size_t i = 1; i < std::pow(2.0, (double)size); ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (i & (1 << j)) 
            {
                ss << str[j];
            }
        }
        substrings.push_back(ss.str());
        ss.str("");
        std::cout << ' ';
    }
}

int main()
{   
    string str = "bab";
    vector<string>subStrings;
    
    // substrings(subStrings, str);

    getAllSubstrings(subStrings, str);
    for (int i = 0 ; i < subStrings.size() ; ++i)
        cout << i << " " << subStrings[i]<< endl;
    return 0;
}
