#include <iostream>

using namespace std;

template <typename T>
struct node
{
    T data;
    node* next;
    
    node():next(NULL){}
    node(T d): data(d), next(NULL) {}
};

template <typename T>
class LinkedList
{
  public:
    void insertNode(T data);
    void insertNode(T data, int index);
    void deleteNode(T data);
    void deleteNode(int index, T* data);
    void deleteNextHigherNode();
    void printList();
    int getSize();
    void reverseList();
    
    LinkedList(): head_(NULL), size_(0){}
    ~LinkedList()
    {
        while(head_)
        {
            deleteNode(0, NULL);
        }
    }
  private:
    node<T> *head_;
    int size_;
    
};

template <typename T>
void LinkedList<T>::insertNode(T data)
{
    node<T>* tmp = new node<T>(data);
    if (head_ == NULL)
    {
        head_ = tmp;
        size_++;
        return;
    }
    
    node<T>* curr = head_;
    while(curr->next != NULL) curr = curr->next;
    
    curr->next = tmp;
    size_++;
}

template <typename T>
void LinkedList<T>::insertNode(T data, int index)
{
    if (index < 0 || index > size_)
    {
        cout << "Index out of bound." << endl;
        return;
    }
    node<T>* tmp = new node<T>(data);
    if (head_ == NULL)
    {
        head_ = tmp;
        size_++;
        return;
    }
    
    int counter = 0;
    node<T>* curr = head_;
    while(curr->next != NULL && ++counter < index)
        curr = curr->next;

    tmp->next = curr->next;
    curr->next = tmp;
    size_++;
}

template <typename T>
void LinkedList<T>::deleteNode(T data)
{
    if (head_->data == data && head_->next == NULL)
    {
        delete(head_);
        head_ = NULL;
        size_--;
        return;
    }
    
    int counter = 0;
    node<T>* curr = head_;
    while(curr->next != NULL && curr->data != data)
    {
         curr = curr->next;
    }
    if (curr->next == NULL)
    {
        cout << data <<" does not exist in list" <<endl;
        return;
    }

    node<T>* temp = curr->next;
    curr->data = curr->next->data;
    curr->next = curr->next->next;
    delete(temp);
    size_--;
    
}

template <typename T>
void LinkedList<T>::deleteNode(int index, T* data)
{
    if (index < 0 || index > size_)
    {
        cout << "Index out of bound." << endl;
        return;
    }
    
    if (head_->next == NULL)
    {
        delete(head_);
        head_ = NULL;
        size_--;
        return;
    }
    
    int counter = 0;
    node<T>* curr = head_;
    while(++counter < index)
        curr = curr->next;

    node<T>* temp = curr->next;
    curr->data = curr->next->data;
    curr->next = curr->next->next;
    delete(temp);
    size_--;
    
}


template <typename T>
void LinkedList<T>::deleteNextHigherNode()
{
    // if (head_->next == NULL)
    // {
        // return;
    // }
    
    node<T>* curr = head_;
    while(curr->next != NULL)
    {
        if (curr->data < curr->next->data)
        {
            node<T>* temp = curr->next;
            curr->data = curr->next->data;
            curr->next = curr->next->next;
            delete(temp);
            size_--;
        }
        curr = curr->next;
    }
    
}


template <typename T>
void LinkedList<T>::printList()
{
    node<T>* curr = head_;
    
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }    
    
    cout << "NULL" << endl;
}

template <typename T>
int LinkedList<T>::getSize()
{
    return size_;
}

int main()
{
    
    LinkedList<int> ll;
    
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(4);

    
    ll.printList();
    cout << ll.getSize() << endl;
    
    ll.deleteNextHigherNode();
   
    ll.printList();
    cout << ll.getSize() << endl;
    
    
}