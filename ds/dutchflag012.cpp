#include <iostream>
using namespace std;

void printArray(int* arr, int size)
{
    for(int i =0; i<size; ++i)
        cout << arr[i] << ", ";
    
    cout <<endl;
}

void swap(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void sortArray(int* arr, int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;
    
    while(mid <= high)
    {
        switch (arr[mid])
        {
            case 0:
                swap(&arr[low++], &arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&arr[mid], &arr[high--]);
                break;
        }
    }
}

int main()
{
    int array[] = {0,1,0,1,1,1,1,2,2,2,2,1,1,0};
    // int array[] = {0,1,2,1,1,1,1,2,2,2,0,0,0,1,2};
    // int array[] = {0,1,2,1,1,1,1,2,2,2,0,0,0,1,2};
    // int array[] = {0,1,2,1,1,1,1,2,2,2,0,0,0,1,2};
    int size = sizeof(array)/ sizeof(array[0]);
    printArray(array, size);
    sortArray(array,size);
    printArray(array, size);
}
