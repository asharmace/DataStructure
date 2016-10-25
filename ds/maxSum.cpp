#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])

void printArray(int* arr, int size)
{
    for(int i =0; i<size; ++i)
        cout << arr[i] << ", ";
    
    cout <<endl;
}

void findMaxSum(int* arr, int size)
{
    int maxSum = arr[0];
    int currSum = arr[0];
    int startPos = 1;
    int newStartPos = 1;
    int endPos = 1;
    
    for(int i =1; i<size; ++i)
    {
        if (currSum < 0)
        {
            currSum = 0;
            newStartPos = i +1;
        }
        
        currSum += arr[i];
        
        if (currSum > maxSum)
        {
            maxSum = currSum;
            startPos = newStartPos;
            endPos = i +1;
        }
    }    
    cout << "max sum = " << maxSum  <<", startPos = " << startPos <<", endPos = " << endPos << endl;
    cout << "Subarray :- " << endl << "\t" <<arr[startPos-1];
    for (int i = startPos; i < endPos; ++i)
        cout << "," << arr[i];
    
    cout << endl;
    
}

int main()
{
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (rand() %100) * ((rand() % 2 == 0)?1:-1);
    }
    
    printArray(arr, ARRAY_SIZE(arr));
    findMaxSum(arr, ARRAY_SIZE(arr));
    
    
    
}