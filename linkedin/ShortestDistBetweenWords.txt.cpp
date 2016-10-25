#include <bits/stdc++.h>
using namespace std;

int dist(vector<string>& words, const string& a, const string& b)
{
    int size = words.size();
    int ret = size;
    int pos_a = -1; 
    int pos_b = -1;
    
    for(int i = 0; i < size; ++i)
    {
        if (words[i] == a)
        {
            pos_a = i;
            
            if (pos_b != -1)
                ret = min (ret, abs(pos_a - pos_b));
        }
        if (words[i] == b)
        {
            pos_b = i;
            
            if (pos_a != -1)
                ret = min (ret, abs(pos_a - pos_b));
        }
    }
    
    return (pos_a == -1 || pos_b == -1)? -1 : ret;

}




int main()
{
    vector<string> words = {"the", "quick", "brown", "fox", "quick"};
    
    
    cout << "the and fox " << dist(words, "the", "fox") << endl; 
    cout << "fox and the " << dist(words, "fox", "the") << endl; 
    cout << "the and brown " << dist(words, "the", "brown") << endl; 
    cout << "quick and brown " << dist(words, "quick", "brown") << endl; 
    cout << "quick and fox " << dist(words, "quick", "fox") << endl; 

    return 0;
}