#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MinStack
{
    private:
        stack<T> stackOrig;
        stack<T> stackMin;
    
    public:
        void push(T ele)
        {
            stackOrig.push(ele);
            if (stackMin.empty() || ele < stackMin.top())
            {
                stackMin.push(ele);
            }
        }
        
        void pop()
        {
            if (stackOrig.top() == stackMin.top())
                stackMin.pop();
            stackOrig.pop();
        }
        
        T top()
        {
            return stackOrig.top();
        }
        
        T getMin()
        {
            return stackMin.top();
        }
        
        int size()
        {
            return stackOrig.size();
        }
};


int main()
{
    MinStack<int> ms;
    int arr[] = {20, 15, 18, 16, 14, 12, 25, 30, 13};
    
    for( auto a: arr)
    {
        ms.push(a);
        cout << ms.top() << " " << ms.getMin() << endl;
    }
    cout << endl;
    int size = ms.size();
    for (int i = 0; i < size; ++i)
    {
        cout << ms.top() << " " << ms.getMin() << endl;
        ms.pop();
    }
    
    cout << ms.size() << endl;
}