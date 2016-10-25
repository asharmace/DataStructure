#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 +7;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		vector <vector<int> > v(K, vector<int>(N));
		
		for(int i = 0; i < K; ++i)
			for(int j = 0; j < N; ++j)
				cin >> v[i][j];
				
		for(auto& a: v)
			sort(a.begin(), a.end());
			
		unsigned long long min = 0;
		for (int i = 0; i < K; ++i)
			min += v[i][0];
			
		unsigned long long result = 1;
        for(int j = 0; j < N; ++j)
		{
			unsigned long long sum = 0;
            for(int i = 0; i < K; ++i)
				sum += v[i][j];
				
			__int128 temp = result * sum;
			result = temp  % MOD;
		}
		if (K != 0)
		{
			result /= K;
		}
		
		cout << (result ^ min) << " " << (1 ^ K) << endl;	
	}
    return 0;	
}
