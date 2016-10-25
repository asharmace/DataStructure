#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

mutex mtx1;
mutex mtx2;

condition_variable cv1;
condition_variable cv2;
bool t1 = true;
bool t2 = false;

void function1()
{
    for (int i = 0; i < 10; i += 2)
    {
        unique_lock<mutex> lock1(mtx1);
        cv1.wait(lock1, []{return t1;});
        //lock1.unlock();
        cout << i << " " ;
        t1 = !t1;
        t2 = !t2;
        cv2.notify_one();
    }
}


void function2()
{
    for (int i = 1; i < 10; i += 2)
    {
        unique_lock<mutex> lock2(mtx1);
        cv2.wait(lock2, []{return t2;});
        //lock2.unlock();
        cout << i << " ";
        t1 = !t1;
        t2 = !t2;
        cv1.notify_one();
    }
}

int main()
{

    thread t1(function1);
    thread t2(function2);
    
    t1.join();
    t2.join();
}
