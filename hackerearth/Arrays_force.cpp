#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,A0, A1, N, MOD, next;
    cin >> T;
    
    for(int x = 0; x < T; ++x)
    {
	    cin >> A0 >> A1 >> N >> MOD;
	    
	    vector<int> array;
		
		array.push_back(A0);
		array.push_back(A1);
		
		for (int i = 2; i < N; ++i)
	    {
	    	array.push_back((array[i-2] + array[i-1]) % MOD);
	    }
		unordered_map<int, unsigned long long> myMap;
		
		for (int i = 0; i < N; ++i)
	    {
	    	auto it = myMap.find(array[i]);
	    	if (it == myMap.end())
	    	{
	    		myMap.insert(make_pair(array[i], 1));
	    	}
	    	else
	    	{
	    		myMap[array[i]] = it->second+ 1;
	    	}
	    }
	    int count = 0;
        unsigned long long result = 0;
	    
	    for (auto it = myMap.begin(); it != myMap.end(); ++it)
	    {
			result = result + (it->second) * (it->second);
	    }

	    cout << result ;
	    cout << endl;
	}
    return 0;
}
