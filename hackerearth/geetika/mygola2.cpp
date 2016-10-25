/*
Two sweet dogs, Bernard and Havanese, play the following game.
There are P sticks, each of exactly Q meters in length. The dogs move in turns. For each move a dog chooses a stick and splits it into two or more equal parts each having integer length greater than or equal to S meters. Each resulting part is also a stick. The dog that can't make a move loses. Thus, the other dog wins.
Bernard makes the first move. Now you have to determine the winner if players play in the optimal way.

Input :
First line of Input contains number of test cases T. Each test case contains three integers P, Q and S.

Output :
For each test case print "Bernard", if Bernard wins, or "Havanese", if Havanese wins. You should print everything without the quotes.

Constraint: 
1 ≤ T ≤ 10
1 ≤ P,Q,S ≤ 109

Sample Input(Plaintext Link)
 2
1 15 4
4 9 5
Sample Output(Plaintext Link)
 Bernard
Havanese
*/

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string answer[2] = {"Bernard", "Havanese"};

	for (int i = 0; i < t; ++i)
	{
		int p, q, s;
		cin >> p >> q >> s;
		int winner  = 1;
		while(true)
		{
			if (s * 2 > q)
			{
				break;
			}
			else if (q % s == 0)
			{
				break;
			}
			else
			{
				int x = s;
				while (q % x != 0) x--;
                if (x == 1) break;
				q /= x;
			}
			winner = 1- winner;
		}
        cout << answer[winner] << endl;
	}
    return 0;
}
