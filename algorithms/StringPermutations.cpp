#include <bits/stdc++.h>
using namespace std;

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void printPermutations(char str[], int l, int r)
{
    if (l == r)
        printf("%s\n", str);
    else
    {
        for(int i = l; i <= r; ++i)
        {
            swap(str[l], str[i]);
            printPermutations(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}



int main()
{
    char str[] = "abcd";
    printPermutations(str, 0, strlen(str) - 1);
}