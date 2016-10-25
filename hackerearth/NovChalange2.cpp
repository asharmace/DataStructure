#include <iostream>
//#include <algorithm>
using namespace std;

int main()
{
    short N, i, max, min, maxI, maxI2, extra = 2;
    cin >> N;
    short Y[N], Z[1001] = {0};
    for (i = 0; i < N; ++i)
    {
    	cin >> Y[i];
    }
    
    for (i = 0; i < N; ++i)
    {
    	Z[Y[i] + 1]++;
    }
    
    max= min = Y[0];
    for(i = 1; i <N; ++i)
    {
		if (Y[0] < min)
			min = Y[0];
		else if (Y[0] > max)
			max = Y[0];
	}
    
    maxI= maxI2 = Z[0];
    for(i = 1; i <N; ++i)
    {
    	if (Z[i] > Z[maxI2])
    	{
    		if (Z[i] > Z[maxI])
    		{
    			maxI2 = maxI;
    			maxI = i;
    		}
    		else
    		{
    			maxI2 = i;
    		}
    	}
    }

    cout << min << " " << max << " " << maxI << " " << maxI2 << endl;
	if (min == maxI || max == maxI)
		extra--;
	else if (min == maxI2 || max == maxI2)
		extra--;
    cout << min << " " << max << " " << maxI << " " << maxI2 << endl;

    cout << Z[maxI] + Z[maxI2] + extra << endl;
    return 0;
}
