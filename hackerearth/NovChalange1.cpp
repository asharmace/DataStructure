#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N,M,i, j, k, cont, count = 0, eventType, start, end, newValue;
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	
	// BOXES
	int A[N];
	for (i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	
	//EVENTS
	for (i = 0 ; i < M; ++i)
	{
		cin>>eventType >> start >>end ;
		
		if (eventType == 1)
		{
			count = 0;
			if (end - start ==1)
				count++;
			else
			{
				for (j = start-1; j < end;)
				{
					cont = 1;
					k = j+ 1;
					
					while (A[k++] == A[j])
						cont++;
						
					count += (cont * (cont + 1)) / 2;
					j += cont;
				}
			}
			cout << count <<endl;
		}
		else if (eventType == 0)
		{
			cin >> newValue;
            for (j = start-1; j <end; ++j)
				A[j] = newValue;
		}
		
	}
	return 0;
}
