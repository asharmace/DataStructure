#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
using namespace std;

void getAllSubstrings(vector<string>& substrings, const std::string& str)
{
    const size_t size = str.size();
    stringstream ss;
    for (size_t i = 1; i < std::pow(2.0, (double)size); ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (i & (1 << j)) 
            {
                ss << str[j];
            }
        }
        substrings.push_back(ss.str());
        // cout << ss.str() << endl;
        ss.str("");
    }
}

int countSubstrings(string& a, string& b)
{
    int result = 0;
    vector<string>subStringsMin;
     string stringMax;
    
    if (a.size() < b.size())
    {
        getAllSubstrings(subStringsMin, a);
        stringMax = b;
    }
    else
    {
        getAllSubstrings(subStringsMin, b);
        stringMax = b;
    }
    // if (a == b)
        // return subStringsMin.size();
        
    for (int i = 0 ; i < subStringsMin.size(); ++i)
    {
      std::size_t found = stringMax.find_first_of(subStringsMin[i]);
      while (found!=std::string::npos)
      {
        result++;
        found=stringMax.find_first_of(subStringsMin[i],found+1);
      }
    }
    return result;
}

int main()
{
	int N, M;
	vector<string>NStrings;
	vector<string>MStrings;
	string input;
	
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> input;
		NStrings.push_back(input);
	}

	cin >> M;
	for(int i = 0; i < M; ++i)
	{
		cin >> input;
		MStrings.push_back(input);
	}
	
	int count = 0;
	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			count += countSubstrings(NStrings[i], MStrings[j]);
            cout << count << endl;
		}
	}
	
	cout << count << endl;
    
    // vector<string> ans;
    // string a("ab");
    
    // getAllSubstrings(ans, a);
    
    
}
