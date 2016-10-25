#include <bits/stdc++.h>
using namespace std;
string maxThreePageSequence(const string& fileName)
{
    ifstream input;
    
    input.open(fileName);
    
    // TODO Erro Handling.
    string s;
    map<string, deque<string> > customerMap;
    map<string, int > pageCounterMap;
    
    getline(input, s);
    while (getline(input, s))
    {
        stringstream sstream(s);
        string key, value;
        getline(sstream, key, ',');
        getline(sstream, value, ',');
        
        auto it = customerMap.find(key);
        
        if (it == customerMap.end())
        {
            deque<string> s;
            s.push_back(value);
            customerMap.insert(make_pair(key, s));
        }
        else
        {
            deque<string>&s = it->second;
            s.push_back(value);
            stringstream newKey;
            
            if (s.size() > 3)
            {
                int i = 0;
                for (auto a = s.begin(); a != s.end(), i < 3; ++a, ++i)
                {
                    newKey <<  *a << ",";
                }    
                    cout << " i " << i << endl;
                s.pop_front();
            }
            cout << "Key = " << newKey.str() << endl;
            pageCounterMap[newKey.str()]++;
        }
    }

    for (auto a: customerMap)
    {
        cout << a.first << " " ;
        for (auto b: a.second)
        {
            cout << b << " " ;
        }
        cout << endl;
    }

    cout << "----------- " << endl;
    string maxSequence;
    int maxSequenceCount = 0;
    for (auto it: pageCounterMap)
    {
        cout << it.first << " " << it.second << "--------" << endl;
         if (it.second > maxSequenceCount)
         {
             maxSequence = it.first;
             maxSequenceCount = it.second;
         }
    }
    
    return maxSequence.substr(0, maxSequence.size() -1);
}

int main()
{
    cout << maxThreePageSequence("am.data") << endl;
}