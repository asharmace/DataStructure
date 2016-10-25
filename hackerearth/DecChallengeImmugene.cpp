#include <iostream>
#include <sstream>
#include <cmath>
#include <set>
using namespace std;

template <class S>
auto powerset(const S& s)
{
    std::set<S> ret;
    ret.emplace();
    for (auto&& e: s) {
        std::set<S> rs;
        for (auto x: ret) {
            x.push_back(e);
            rs.insert(x);
        }
        ret.insert(begin(rs), end(rs));
    }
    return ret;
}

// void powerSet(unordered_set<string>& sset, string& s)
// {
    // unsigned long long pow_set_size = pow(2, s.size());
    // int counter, j;
 
    // /*Run from counter 000..0 to 111..1*/
    // for(counter = 0; counter < pow_set_size; counter++)
    // {
      // stringstream ss;
      // for(j = 0; j < s.size(); j++)
       // {
          // /* Check if jth bit in the counter is set
             // If set then pront jth element from set */
          // if(counter & (1<<j))
            // ss << s[j];
       // }
       // sset.insert(ss.str());
    // }
// }


int main()
{
    int N, Q;
    cin >> N >> Q;
    char s[N];
    cin >> s;
    while (Q--)
    {
    	int x;
    	char y;
    	cin >>x >> y;
    	unsigned long long result = 0;
    	
    	s[x-1] = y;
    	string temp(s);
        //cout << "New String " << temp << endl;
    	
        auto sset = powerset(temp);
        
        result = sset.size() % 1000000007;
        
        cout << result << endl;
    }
    return 0;
}