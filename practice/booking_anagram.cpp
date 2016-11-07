#include <bits/stdc++.h>
using namespace std;

void printAnagrams(const vector<string>& v)
{
	unordered_map<string, vector<string> >m;
	for(auto a: v)
	{
		string s ;
		remove_copy_if(a.begin(), a.end(),            
                      std::back_inserter(s), //Store output           
                       std::ptr_fun<int, int>(&std::isspace)  
                      );
		sort(s.begin(), s.end());
		m[s].push_back(a);
	}
	cout << "Printing anagramsssss:-" << endl; 
	for(auto a: m)
	{
		for (auto b: a.second)
			cout << b << ","; 
		cout << endl;
	}
}
 
int main() 
{
	vector<string> v = {"pear", "amleth", "dormitory", "tinsel", "dirty room", "hamlet", "listen", "silent"};

	printAnagrams(v);
 
	return 0;
}
