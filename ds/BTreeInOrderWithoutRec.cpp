#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int i)
{
    node* temp = new node();
    temp->data = i;
    temp->left = temp->right = NULL;
    
    return temp;
}

void inOrder(node* root)
{
    if (root == NULL)
        return;
    
    stack<node*> myStack;
    bool done = false;
    
    node* curr = root;
    
    while (!done)
    {
        if (curr != NULL)
        {
            myStack.push(curr);
            curr = curr->left;
        }
        else
        {
            if(!myStack.empty())
            {
               curr = myStack.top();
               myStack.pop();
               printf("%d ", curr->data);
               curr = curr->right;
            }
            else 
            {
                done = true;
            }
        }
    }
}

void morrisTraversal(node* root)
{
    if (root == NULL)
        return;
        
    node* curr = root, *pre;
    
    while(curr)
    {
        if (curr->left == NULL)
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
                
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }        
    }
}

/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  inOrder(root);
  printf("\n");
  
  morrisTraversal(root);
  printf("\n");
 
  return 0;
}