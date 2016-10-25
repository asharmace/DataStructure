#include <iostream>
using namespace std;

int main()
{
	int N,M,i, j, k, cont, count = 0, param1, param2, param3, param4;
	strin s;
	cin >> N >> M;
	
	int A[N];
	for (i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	
	for (i = 0 ; i < M; ++i)
	{
		getline(cin, s, " ");
		
        param1 = atoi(s[0]);
		if (param1 == 0)
		{
			cin >> param2 >> param3  >> param4;
				for (j = param2; j <=param3; ++j)
						A[j] = param4;
		}
		
		else if (param1 == 1)
		{
			cin >> param2 >> param3;
			count = 0;
			for (j = param2; j < param3;)
			{
				cont = 1;
				k = j;
				
				while (A[k++] == A[j])
					cont++;
					
				count += cont * (cont + 1) / 2;
			}
			
			cout << count << endl;
		}
	}
	return 0;
}
