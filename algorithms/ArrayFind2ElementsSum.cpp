#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool hasArrayTwoCandidates(int* array , int arr_size, int sum)
{
    qsort(array, arr_size, sizeof(int), compare);
    
    int l = 0, r = arr_size -1;
    
    while(l < r)
    {
        if(array[l] + array[r] == sum)
            return true;
        else if (array[l] + array[r] < sum)
            l++;
        else 
            r--;
    }
    return false;
}

/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, -8};
    int n = 16;
    int arr_size = 6;
    
    for ( int i = 0; i < 25; ++i)
    {
        if( hasArrayTwoCandidates(A, arr_size, i))
            printf("Array has two elements with sum %d\n", i);
        else
            printf("Array doesn't have two elements with sum %d\n", i);
    }
    return 0;
}
