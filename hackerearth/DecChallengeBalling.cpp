#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

unsigned long long powerSet(vector<int>& v)
{
    unsigned long long pow_set_size = pow(2, v.size());
    unsigned long long counter, j, result = 0;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      unsigned long long i =1L;
      for(j = 0; j < v.size(); j++)
      {
          if(counter & (1<<j))
          {
            result = (result + (v[j] * i) % 1000000007 )% 1000000007;
            i++;
          }
      }
    }
    return result;
}


int main(int argc, char* argv[])
{
    //int T;
    //cin >> T;

    // int temp;
    vector<int> v;
    
    int T = atoi(argv[1]);
    
    for(int i = 1 ; i < T; ++i)
        v.push_back(i);
    
    // while (T--)
    // {
    	// cin >> temp;
        // v.push_back(temp);
    // }
    cout << powerSet(v) << endl;
    return 0;
}
  