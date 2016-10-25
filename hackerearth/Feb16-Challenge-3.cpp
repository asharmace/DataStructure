#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > factors;

void init()
{
	for (int i = 2; i <= 30; ++i)
	{
		vector<int> temp;
		for (int j = 2; j <=i; ++j)
		{
			if (i % j == 0)
				temp.push_back(j);
		}
		factors[i] = temp; 
	}
}

bool isSafe(vector<bool>& board)
{
	// for(auto a: board)  cout << a <<" ";
    // cout << endl;
	for(auto a: board)
		if (a) return true;
		
	return false;
}

int main()
{
    int T;
    cin >> T;
    init();
    while (T--)
	{
    	bool turn = true;
    	int N;
    	cin >> N;
    	vector<bool> board(N, true);
    	board[0] = false;

        for (int i = N; i > 1; --i )
        {
            auto vec = factors[i];
            //cout << "\t\t\t\t" << i << endl;
            for (auto a : vec)
            {
                //cout << a << " ";
                board[a-1] = false;
            }
            //cout << endl;
            turn = !turn;
            if (!isSafe(board)) break;
        }
    	cout << (turn?1:2) << endl;
    }
    
    return 0;
}
