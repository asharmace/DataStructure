#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	short K;
	double N;
    cin >> K;
    cin >> N;
    double count=0,  thresh = 0;
    int unit, incrementor;
    for (double i = 4; i < N ;i++)
    {
    	double curr = i;
        
        incrementor = fmod(curr,10);
	    while(curr > 0)
	    {
            unit = fmod(curr,10);
            if (unit == 4 || unit == 7)
	    	{
	    		thresh++;
                if (thresh > K)
	    		{
                    thresh = 0;
	    			count++;
	    		}
            }
	    	curr /= 10;
	    }
    }
    cout << fmod(count, 1000000007);
    return 0;
}
