#include <iostream>
#include <stack>
using namespace std;

// A utility function to print elements of array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
}
 
 
void calculateSpan(int* price, int days, int *span)
{
    span[0] = 1;
    stack<int> myStack;
    
    myStack.push(0);
    
    for (int i =1; i <days; ++i)
    {
        while(myStack.empty() != true && price[i] >= price[myStack.top()])
            myStack.pop();
    
        span[i] = (myStack.empty())? i+1 : i - myStack.top();
      
        myStack.push(i);
    }
}



// Driver program to test above function
int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
 
    // Fill the span values in array S[]
    calculateSpan(price, n, S);
 
    // print the calculated span values
    printArray(S, n);
 
    return 0;
}