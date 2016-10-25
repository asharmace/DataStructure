#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

double get(double x)
{
    return x;
}

int main()
{
    cout << std::thread::hardware_concurrency() << endl;
    atomic<double> x(10.0);
    x = 15;
    
    cout << x << endl;
    
    cout << get(x) << endl;
    
}