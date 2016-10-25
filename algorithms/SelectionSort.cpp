#include <iostream>
#include <cstdio>
using namespace std;

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minPos = i;
        for (int j = i; j < size; ++j)
        {
            if (arr[j] < arr[minPos])
                minPos = j;
        }
        swap(&arr[minPos], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}