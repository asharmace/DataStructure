#include <iostream>
#include <climits>

using namespace std;

static void mySwap(int* x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}

class MinHeap
{
    public:
        MinHeap(int cap): capacity(cap) 
        {
            count = -1;
            array = new int[capacity];
        }
        
        ~MinHeap()
        {
            delete array;
        }
        
        void heapify(int i);

        int parent(int i);
        int leftChild(int i);
        int rightChild(int i);
        void deleteKey(int i);       
        int extractMin();
        void decreaseKey(int i, int value);
        int getMin();
        void insertKey(int value);
    private:
        int capacity;
        int count;
        int* array;
    
};

int MinHeap::parent(int i)
{
    if (i < 0 || i > count) return -1;
    return (i - 1)/ 2;
}

int MinHeap::leftChild(int i)
{
    int l = i * 2 + 1;
    if ( i < 0 || l > count)
        return -1;
    return l;
}

int MinHeap::rightChild(int i)
{
    int r = i * 2 + 2;
    if ( i < 0 || r > count)
        return -1;
    return r;
}

int MinHeap::getMin()
{
    if(array) return array[0];
}

int MinHeap::extractMin()
{
    int min = array[0];
    
    array[0] =  array[count - 1];
    count--;
    heapify(0);
    
    return min;
}

void MinHeap::heapify(int i)
{
    int min = i;
    int left = leftChild(i);
    int right = rightChild(i);
    
    if (left != -1 && array[left] < array[i])
        min = left;
    
    if (right != -1 && array[right] < array[left])
        min = right;
    
    if (min != i)
    {
        mySwap(&array[min],&array[i]);
        heapify(min);
    }
}

void MinHeap::decreaseKey(int i, int value)
{
    if (i < 0 || i > count)
        return ;
    
    array[i] = value;
    
    while(i > 0)
    {
        int par = parent(i);
        if (array[par] > array[i])
            mySwap(&array[par], &array[i]);
        i = par;
        
    }
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MAX);
    extractMin();
}

void MinHeap::insertKey(int value)
{
    if(count==capacity-1)
    {   
        cout << "Heap Full" << endl;
        return;
    }
    count++;
    
    array[count] = value;
    int i = count;
    while (i != 0)
    {
        int par = parent(i);
        if (array[i] < array[par])
            mySwap(&array[i], &array[par]);
        i = par;
    }
}

// Driver program to test above functions
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}