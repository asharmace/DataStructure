#include <bits/stdc++.h>
using namespace std;

bool areAll9s(vector<int>& v)
{
    for (auto a: v) if (a != 9) return false;
    
    return true;
}

void nextSmallestPalindromeUtil(vector<int>& v)
{
    int size = v.size(), l, r;
    l =  size/2 -1;
    r = (size%2 == 0)? size/2: size/2 +1;
    
    while(l >=0 && v[l] == v[r]) l--, r++;
    
    if (l < 0 || v[l] < v[r])
    {
        l =  size/2 -1;
        r = (size%2 == 0)? size/2: size/2 +1;
        
        int carry = 1;
        while (l >= 0)
        {
            v[l] += carry;
            carry = v[l]/10;
            v[l] %= v[l];
            v[r] = v[l];
            r++;
            l--;
        }
    }
    else
    {
        while (l >= 0)
        {
            v[r] = v[l];
            r++;
            l--;
        }
    }
    
}

void nextSmallestPalindrome(vector<int>& v)
{
    if (areAll9s(v))
    {
        cout << 1;
        for(int i = 1; i < v.size(); ++i) cout << 0;
        cout << 1 << endl;
    }
    else
    {
        nextSmallestPalindromeUtil(v);
        for (auto a: v) cout << a;
        cout << endl;
    }
}


int main()
{
    long num = 94187978322L;
    vector<int> v;
    auto it = v.begin();
    while(num > 0)
    {
        it = v.insert(it, num%10);
        num /= 10;
    }
    nextSmallestPalindrome(v);
}