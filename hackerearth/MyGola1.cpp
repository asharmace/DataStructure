#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >>N;
		vector<long long> v(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> v[i];
		}
        
        vector <long long > v2(N, 0);
        bool found = false;
		for (int i = 0; i < N-1; ++i)
		{
			int j = i+1;
            set<int> s;
            s.insert(v[i]);
			for (; j < N; ++j)
			{   
                
				if (s.find(v[j]) != s.end())
                {  
                    break;
                }
                s.insert(v[j]);
			}
            v2[i] = j;
			
		}
		int maxStart = 0, maxEnd = 1, maxDays = 0;
        
        // for (auto a : v2)
            // cout << a << endl;

        for (int i = 0; i < N ; ++i)
        {
            if (v2[i] - i  > maxDays)
            {
                maxDays = v2[i] - i ;
                maxStart = i+1;
                maxEnd = v2[i];
            }
        }
		cout << maxStart << " " << maxEnd <<endl;
	}
    return 0;
}
