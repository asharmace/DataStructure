#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
    private:
        int curSize;
    public:
        LRUCache(int l);
        void set(int, int) override;
        int  get(int) override;
};

LRUCache::LRUCache(int l)
{
        cp = l;
        head = tail = nullptr;
        curSize = 0;
       
}

void LRUCache::set(int key, int value)
{
    Node* it = head;
    bool found = false;
    // 1st search if key is present. update if it is
    while(it != tail)
    {
        if (it != nullptr && it->key == key)
        {
            found = true;
            break;
        }
        it = it->next;
    }
    

    if (found)
    {
        it->value = value;
        return;
    }

    // 2nd key is not present, insert it. delete last key if capacity is full
    Node *temp = new Node(nullptr, nullptr, key, value);
    
    if (head == nullptr)
    {
        head = temp;
        temp->next = tail;
        return;
    }
    
    temp->next = head;
    head = temp;
    if (curSize == cp)
    {
        Node* last = tail;
        tail = tail->prev;
        delete last;
    }
    else
    {
        curSize++;
    }
    
    
}

int LRUCache::get(int key)
{
    int value = -1;
    Node* it = head;
    bool found = false;
    // 1st search if key is present. update if it is
    while(it != tail)
    {
        if (it != nullptr && it->key == key)
        {
            found = true;
            break;
        }
        it = it->next;
    }

    if (found)
    {
        value = it->value;
    }
    return value;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
