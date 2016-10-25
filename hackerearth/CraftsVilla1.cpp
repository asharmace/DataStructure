#include <iostream>
#include <cmath>
using namespace std;

unsigned nextNumber(unsigned x) 
{
	unsigned smallest, ripple, new_smallest, ones;
	
	if (x == 0) return 0;
	smallest     = (x & -x);
	ripple       = x + smallest;
	new_smallest = (ripple & -ripple);
	ones         = ((new_smallest/smallest) >> 1) - 1;
	return ripple | ones;
}

int getSum(int test)
{
	double result = 3;
	unsigned int start = 3;
	unsigned int next = nextNumber(start);
	
	while (next <= test)
	{
		result += next;
		next = nextNumber(next);
	}

	return (int)(fmod(result,1000000007)) ;
}

int main()
{
    int N ,test;
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
    	cin >> test;
    	cout << getSum(test);
    }
}
