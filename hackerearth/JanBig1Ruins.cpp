#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
   	int T;
   	cin >> T;
   	while (T--)
   	{
   		long long x, y, n;
   		cin >> x >> y >> n;
   		if (n == 2)
   		{
   			cout << x + y << endl;
   		}
   		else
   		{
	   		long long counter = 3;
	   		long long h1 = x;
	   		long long h2 = y;
	   		long long h3 = abs(h1 - h2);
	
	   		long long sum = h1 + h2 + h3;
	   		//cout << sum << endl;
	   		
	   		while(h3 != 0 && counter < n)
	   		{
	   			h1 = h2;
	   			h2 = h3;
	   			h3 = abs(h1 - h2);
	   			sum += h3;
	            counter++;
	            //cout << counter << " " << sum << endl;
	   		}
	        __int128 remaining;
	        if (counter  != n)
	        {
	            remaining = n - counter;
	            int last = remaining % 3;
	            remaining -= last;
	            remaining /= 3;
	            //cout << "AAA " << (long)remaining << " " << last << endl;
	
	            //sum -= h3;
	            sum += ( 2* h2) * remaining;
	            sum += last * h3;
	        }
	   		
	   		cout << sum << endl;
   		}
   	}
    return 0;
}
