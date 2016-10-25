#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char* str, int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n",  str);
    else
    {
        for (i = l; i <= r; ++i)
        {
            swap((str + l) , (str + i));
            permute(str, l+1, r);
            swap((str + l) , (str + i));
        }
    }
}


int main()
{
    char str[] =  "ABC";
    int len = strlen(str) - 1;
    
    permute(str, 0, len);
}