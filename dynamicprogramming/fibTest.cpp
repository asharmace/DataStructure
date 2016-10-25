#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>

int fibresult[1000000];

using namespace std;
using namespace std::chrono;

int fibRec (int n) 
{
    if (n < 2)
        return 1;
    return fibRec(n-1) + fibRec(n-2);
}

void fibDP (int n) 
{
    fibresult[0] = 1;
    fibresult[1] = 1;
    for (int i = 2; i<n; i++)
       fibresult[i] = fibresult[i-1] + fibresult[i-2];
}

int main()
{
    int  n = 50;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    fibRec(n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took  " << time_span.count() << " seconds." << endl;

    t1 = high_resolution_clock::now();
    fibDP(n);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took  " << time_span.count() << " seconds." << endl;

    return 0;

}

