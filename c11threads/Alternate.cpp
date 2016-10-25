#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

static const int MAX_COUNTS=20;
static const int INCREMENT=2;
std::mutex mtx;


class NumPrinter
{
    
    public:
        volatile int v;
        void operator()()const
        { 
            for(int i =0; i <MAX_COUNTS; i+= INCREMENT)
            { 
                std::lock_guard<std::mutex> guard(mtx);
                cout << v +i << " ";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
};

int main()
{
    NumPrinter n;
    n.v = 1;
    
    thread t(n);
    n.v =2;
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    thread t2(n);
    t.join();
    t2.join();
    return 0;
}