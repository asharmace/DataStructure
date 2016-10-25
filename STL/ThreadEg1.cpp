#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void f1(int& i, string s)
{
        cout << "From Thread " << i << " " << s << endl;
        this_thread::sleep_for(chrono::seconds(1));
        i++;
}

int main()
{
    int i = 0;
    thread t(f1, std::ref(i), "Hello");
    t.join();
    cout << i<< endl;
    cout << "thread ended" <<endl;

}
