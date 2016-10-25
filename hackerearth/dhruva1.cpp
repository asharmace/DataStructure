#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N, Q;
	cin>> N;
	vector<pair <int, int> > v(N);
	for(int i =0; i < N; ++i)
	{
		std::cin >> v[i].second;
	}
	for(int i =0; i < N; ++i)
	{
		std::cin >> v[i].first;
	}
	sort(v.begin(), v.end());
	while (Q--)
	{
		int sum = 0, num;
		cin >> num;
		for (auto a = v.rbegin(); a != v.rbegin() + num ; ++a)
			sum += a->second;
			
		cout << sum << endl;
	}
    return 0;
}
