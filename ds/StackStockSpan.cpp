#include <iostream>
#include <stack>

using namespace std;

void calculateSpan(int price[], int n, int S[])
{
    stack <int> st;
    st.push(0);
    S[0] = 1;
    
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
            
        S[i] = (st.empty())? i + 1 : i - st.top();
        
        st.push(i);
    }
}

// A utility function to print elements of array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
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