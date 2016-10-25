#include <iostream>
#include <memory>
using namespace std;

class Test
{
    int x;
    public:
        Test() {cout << "Constructor" << endl;}
        ~Test() {cout << "Destructor" << endl;}
};

class Test2
{
    Test* t;
    public:
        Test2()
        {
            t = new Test;
            throw 5;
        }
};

int main()
{
    try 
    {
        Test2 t2;
    }
    catch(...)
    {
        cout << "caught " << endl;
    }
}