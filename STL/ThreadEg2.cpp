#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <conditional_variable>
using namespace std;

std::mutex mtx;

void f(int i, bool flag)
{
    while(i <10)
    {
        this_thread::sleep_for(chrono::seconds(1));
        cout << i << endl;
        i += 2;
    }
}

int main()
{
    thread t1(f, 1, true);
    thread t2(f, 2, false);
    
    t1.join();
    t2.join();
    
}


    
