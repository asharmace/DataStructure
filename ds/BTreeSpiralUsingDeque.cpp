// C++ implementation of a O(n) time method for spiral order traversal
#include <iostream>
#include <deque>
using namespace std;
 
// Binary Tree node
struct node
{
    int data;
    node *left, *right;
};
 
void printSpiral(node *root)
{
    if (root == NULL ) return;
    deque<node*> q;
    
    q.push_back(root);
    q.push_back(NULL);
    while(q.size() == 1 && q.front == NULL)
    {
        root = q.front();
        while(root != NULL)
        {
            q.pop_front();
            cout << root->data << " ";
            
            if (root->left) q.push_back(root->left);
            if (root->right) q.push_back(root->right);
            root = q.front();
        }
        cout << endl;
        if (!q.empty()) q.push_front(NULL);
        else break;
        root = q.back();
        while(root != NULL)
        {
            q.pop_back();
            cout << root->data << " ";
            
            if (root->left) q.push_front(root->left);
            if (root->right) q.push_front(root->right);
            root = q.back();
        }
        cout << endl;
    }
}
 
// A utility functiont to create a new node
node* newNode(int data)
{
    node* temp = new  node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return(temp);
}
 
int main()
{
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);
 
}