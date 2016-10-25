#include <iostream>
#include <cstdio>

int pivotedBinarySearch(int *arr, int left, int right, int key)
{
    if (left > right) return -1;
    
    int mid = left + (right - left)/2;
    
    if (arr[mid] == key) return mid;
    
    if (arr[left] <= arr[mid])
    {
        if (key >= arr[left] && key <= arr[mid])
            return pivotedBinarySearch(arr, left, mid -1, key);
        
        return pivotedBinarySearch(arr, mid+1, right, key);
    }
    else
    {
        if (key >=arr[mid] && key <= arr[right])
            return pivotedBinarySearch(arr, mid+1, right, key);
    
        return pivotedBinarySearch(arr, left, mid -1, key);
    }
}


int main()
{
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 6;
   printf("Index: %d\n", pivotedBinarySearch(arr1,0, n-1, key));
   return 0;
}