#include <iostream>
#include <vector>
#include <cmath>
#include <cmath>
using namespace std;

int main()
{
	short K;
	int N;
    cin >> K;
    cin >> N;
    int count=0,  thresh = 0;

    int unit, digits = 0, tensMultiple = 0;
    
    while (N > 0)
    {
        if (N >= 1000000)
        {
            thresh += 2 * 600000;
            N -= 1000000;
        }
        else if (N >= 100000)
        {
            thresh += 2 * 50000;
            N -= 100000;
        } 
        else if (N >= 10000)
        {
            thresh += 2 * 4000;
            N -= 10000;
        } 
        else if (N >= 1000)
        {
            thresh += 2 * 300;
            N -= 1000;
        } 
        else if (N >= 100)
        {
            thresh += 2 * 20;
            N -= 100;
        }
        else if (N >= 10)
        {
            thresh += 2 * 1;
            N -= 10;
        }
        else if (N == 4 || N == 7)
        {
            thresh++;
            break;
        }
    }
    
    count = thresh / K;
    
    cout << count%1000000007;
    return 0;
}
