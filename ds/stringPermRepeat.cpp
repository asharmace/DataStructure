#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char* a, int l, int r)
{
    int i;
    if (l == r)
    {
        printf("%s\n", a);
    }
    else
    {
        for (i = l; i <= r; ++i)
        {
            swap(&a[i], &a[l]);
            permute(a, l+1, r);
            swap(&a[i], &a[l]);
        }
    }
}

int main()
{
    char myStr[] = "ABC";
    int len = strlen(myStr) -1;
    
    // permute(myStr, 0, len -1);
    permute(myStr, 0, len);
    return 0;
}