#include <iostream>
#include <cstdio>

using namespace std;

int binarySearch(int* arr, int start, int end, int element)
{
    if (start >= end)
        return -1;
    
    int mid = (start +  end)/2;
    if (element < arr[mid])
        return binarySearch(arr, start, mid, element);
    else if(element > arr[mid])
        return binarySearch(arr, mid, end, element);
    else 
        return mid;
}

int main(void)
{
   int arr[] = {2, 3, 4, 7, 10, 40, 50};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}