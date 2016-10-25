#include<bits/stdc++.h>
using namespace std;

void printKthDigit(long long a, long long b, int k)
{
    int result = 1;
    long long mod = pow(10,k);
    
    while(b--)
    {
        result =  (result * a) % mod;
    }
    mod /= 10;
    cout << (result / mod ) << endl;
}

int main()
{
    int T,A,B,k;
    cin >> T;
   while(T--)
   {
        cin >> A >> B >> k;
        printKthDigit(A,B,k);
   }
}