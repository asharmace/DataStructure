#include<stdio.h>
#include<cstring>
#include<iostream>
#include<string.h>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<set>
#include<complex>
#include<list>

using namespace std;

// Find suffix of length k , like for number 23456 and k = 3 
//suffix is 456
long long int suffix_k(long long int n , int k){
    return (long long int)n % (long long int)pow((double)10 , k);	
}

//Number of digits in number
int count_digits(long long int n ){
    int k = 0;
    while(n>0){
        n/=10;
        k++;
    }
    return k ;
}

//Calculate power upto k digits 

long long int  power(long long int x,  long long int y ,  int k)
{
    long long int t;
    if( y == 0)
        return 1;
   	
   	else{
   	 t =  power(x, y/2,k);
    if(count_digits(t)>=k)
     t = suffix_k(t,k);
   	}
       
    if (y%2 == 0){ 
    return suffix_k(t*t,k);
    }
    else{
   	return suffix_k(x*suffix_k(t*t,k),k);
    
    }
}
 
void print_kth_digit(long long int x , long long int y , int k){
   long long int ans = 	power(x,y,k);
   long long int t   = ans ;
   int total_digits = 0;
   while(t>0){
   	t/=10;
   	++total_digits;
   }	
    if(total_digits<k)
    cout<<"0"<<endl;
    else
    cout<<(int)ans/(int)(pow((double)10 ,k-1))<<endl;

} 
 

int main()
{  
    int T,A,B,k;
    cin >> T;
    while(T--)
    {
        cin >> A >> B >> k;
        print_kth_digit(A,B,k);
    }
    return 0;
}