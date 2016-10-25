#include <iostream>
#include <cstdio>
using namespace std;

int getOddOccurrence(int* arr, int size)
{
    int result = 0;
    for(int i = 0; i < size; ++i)
        result ^= arr[i];
        
    return result;
}

/* Diver function to test above function */
int main()
{
     int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getOddOccurrence(ar, n));
     return 0;
}