#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
using namespace std;

condition_variable cond_var1;
mutex m1;
condition_variable cond_var2;
mutex m2;

int main() {
    int value = 100;
    bool notified = false;
    thread t1([&](){
        
        unique_lock<mutex> lock(m);
        while (!notified) {
            cond_var.wait(lock);
        }
      
        cout << "The value is " << value << endl;
        notified = false;
                notified = true;
        cond_var.notify_one();
    });

    thread t2([&]() {
        value = 20;
        
        notified = true;
        cond_var.notify_one();
        
    });

    reporter.join();
    assigner.join();
    return 0;
}