/*
Ben believes a lot in tarot cards. He believes that they are lucky for him. He even decides to wear clothes according to the color predicted by a draw of a card. This irritates his wife, because sometimes he wears the same color t-shirt continuously if his cards so predict.

Now, his wife wants to go on a vacation with him, but she has a condition that she will only go if he wears a different color t-shirt on every day they are on a vacation. Ben really wants to please her, so he found out in advance the color predicted by his cards for the next N days. Now of these, he wants to find the longest vacation span he can get if he wears a different color t-shirt each day. Also, if there are multiple such occurrences of longest span, he wants to know the earliest such span because his wife will get angry is he delays for too long.

Input:

First line contains T which is the number of test cases.
Each test case contains 2 lines. 

First line of every test case contains an integer N where N is the number of days.
Second line of every test case contains the N colors which indicate the color of the T-Shirt Ben wore on each day (1-indexed).

Output:

For each test case, output a line containing 2 integers indicating the starting and ending day numbers of the largest span.

Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤105
1 ≤ color ≤ 109
Scoring:

1 ≤ N ≤ 10 : (30 pts)
1 ≤ N ≤ 103 : (30 pts)
Original Constraints : (40 pts)
Sample Input(Plaintext Link)
 2
5
1 2 3 4 5
6
1 2 1 3 1 5

Sample Output(Plaintext Link)
 1 5
2 4
Explanation
Case 1: As he can wear 5 different T-shirts on the next 5 days, he can go on a 5 day vacation from day 1 to day 5.

Case 2: The longest duration is of 3 days from [2,4] and [4,6] of which day 2 to day 4 comes earlier.

*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >>n;
		int arr[n];
		for (int j = 0 ; j < n; ++j)
		{
			cin >> arr[j];
		}
		
		//int arr2[n];
		int max= 0;
		int start = 0;
		for(int j = 0; j < n-1;)
		{
			int k = j;
			set<int> s;
			for (; k < n; ++k)
			{
				if (s.find(arr[k]) != s.end()) break;
				
				s.insert(arr[k]);
			}
            // cout << "DDD " ;
            // for(auto a: s)
                // cout << a <<" ";
            
            //cout << endl;
			
            if (k - j > max)
			{
				max = k - j ;
				start = j;
                //cout << "AAA " <<start +1 << " " << start + max << endl;
			}
            j += max -1;
            //cout << " New J " << j << endl;
		}
		
		cout << start +1 << " " << start + max << endl;
	}
    return 0;
}
