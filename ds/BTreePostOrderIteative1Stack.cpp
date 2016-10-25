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

void postOrder(node* root)
{
    if (root == NULL) return;
    
    stack<node*> s;
    
    do
    {
        while(root)
        {
            if (root->right) s.push(root->right);
            s.push(root);
            root = root->left;
        }
        
        root = s.top(); s.pop();
        
        if (!s.empty() && root->right && root->right == s.top())
        {
            s.pop();
            s.push(root);
            root = root->right;
        }
        else
        {
            if (root)
            {
                cout << root->data << " " ;
                root = NULL;
            }
        }
    } while(!s.empty());
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
 
  postOrder(root);
  printf("\n");
  
  return 0;
}