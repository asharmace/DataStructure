#include <iostream>
#include <unordered_set>

using namespace std;
#define MAX 100000
 
void printPairs(int arr[], int arr_size, int sum)
{
    unordered_set <int>mySet;
    for(int i = 0; i < arr_size; ++i)
    {
        auto it2 = mySet.find((sum - arr[i]));
        if (it2 != mySet.end())
        {
            cout << "Pairs are: " << arr[i] << " & " << *it2 << endl;
        }
        mySet.insert(arr[i]);
    }
}
 
/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    printPairs(A, arr_size, n);
 
    return 0;
}