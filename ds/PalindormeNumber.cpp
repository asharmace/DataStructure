#include <bits/stdc++.h>
using namespace std;

bool areAll9s(vector<int>& v)
{
    for(auto a: v) if (a != 9) return false;
    return true;
}

void nextSmallestPalindromeUtil(vector<int>& v)
{
    int mid = v.size()/2;
    int l = mid -1;
    int r = (v.size()%2)?mid+1:mid;
    bool leftSmaller = false;
    
    while (l >= 0 && v[l] == v[r]) l--, r++;
    
    if (l < 0 || v[l] < v[r]) leftSmaller = true;
    
    while (l >= 0)
    {
        v[r] = v[l];
        l--;
        r++;
        cout << " AAAAAA ";
        for (auto a: v) cout << a;
        cout << endl;
    }
    
    if(leftSmaller)
    {
        int carry = 1;
        l = mid -1;
        
        if (v.size() % 2 == 1)
        {
            v[mid] += carry;
            carry = v[mid]/10;
            v[mid] %= 10;
            r = mid + 1;
            
            cout << " BBBBB ";
            for (auto a: v) cout << a;
            cout << endl;
        }
        else
            r = mid;
            
        while (l >= 0)
        {
            v[l] += carry;
            carry = v[l]/10;
            v[l] %= 10;
            v[r] = v[l];
            r++;
            l--;
            cout << " CCCCC ";
            for (auto a: v) cout << a;
            cout << endl;
        }
    }
    
}

void nextSmallestPalindrome(vector<int>& v)
{
    if (areAll9s(v))
    {
        for (auto a: v) cout << a;
        cout << endl << endl;
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