/*
The fight between Batman and Superman just got dirty. Superman tried to trick Batman and locked him inside an N x N grid. This gird is really special. It has values at each of its cell which is some positive integer.

Superman gave Batman a serious headache inside the grid. He gave him an integer K and ordered him to tell count of such K x K matrix which when summed equals a perfect cube. Only if Batman gives the correct answer will the grid open and let Batman out.

Batman being not so good at coding turns to you for help. Its time for you to prove that you are a real Batman Fan by helping him out.

Input:

The first line contains 2 integers N and K . This is followed up by an N x N matrix.

Output:

Print number of such K X K matrix whose sum is a perfect cube.

Constraints :

N ≤ 1000

K ≤ N

All values in matrix ≤ 109
Sample Input
(Plaintext Link)

3 2
5 69 2 
42 9 9 
5 8 1 

Sample Output
(Plaintext Link)

3

Explanation

The 3 2X2 matrices whose sum equals a perfect cube are:

    (1,1) to (2,2)

    (2,1) to (3,2)

    (2,2) to (3,3)

*/


#include <bits/stdc++.h>
using namespace std;


int main()
{
    set<long long> cubes;
    for (int i = 0; i < 10000; ++i)
    {
        cubes.insert(1L *i * i * i);
    }
    
    int N, K;
    cin >> N >> K;
    int arr[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
            
    int count = 0;
    long long sum = 0;
    // count first K+K
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
            sum += arr[i][j];
    cout << sum << endl;
    for (int i = 1; i < K; ++i)
    {
        long long currSum = sum;
        
        for (int j = 1; j < K; ++j)
        {
            cout << i << " "  << j << " " <<  arr[i][j] << " "  << arr[i][j-K] << endl; 
            currSum += arr[i][j];
            currSum -= arr[i][j-K];
        } 
        cout  << currSum << endl;
        //sum = currSum;
    }
    
    return 0;
}
