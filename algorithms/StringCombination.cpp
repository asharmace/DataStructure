#include <bits/stdc++.h>
using namespace std;

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void printAllPermutaions(char* s, int l, int r)
{
    if (l == r)
        printf("%s\n",s);
    else
    {
        for(int i = l; i <= r; ++i)
        {
            swap(s[l], s[i]);
            printAllPermutaions(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    char s[] = "abc";
    printAllPermutaions(s,0,strlen(s) -1);
}  