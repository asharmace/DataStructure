#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


int numOfSwaps(const char* c, int len)
{
	int result = 0;
	int oIndex = 0;
    
    for_each(c, c+len, [&oIndex](char c){
                            if(c == 'O') 
                                oIndex++; 
                         });
    
    cout << oIndex << endl;
    return 0;
    
	// for(int i = 0; i < len; ++i)
	// {
		// c
	// }
}



int main()
{
    int T;
    cin >>T;
    assert(T >=1 && T<=10);
	
	string oz;
    
    for(int i = 0; i < T; ++i)
    {
    	cin >> oz;	
    	int len = oz.size() ;
    	
    	assert(len >= 1 && len <= 1000000);
    	const char* c = oz.c_str();
    	
    	cout << numOfSwaps(c, len) <<endl;
    }
    
    return 0;
}
