#include <cstdio>
#include <iostream>

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

bool isBalanced(node* root, int* height)
{
    if (root == NULL) 
    {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    bool left = isBalanced(root->left, &lh);
    bool right = isBalanced(root->right, &rh);
    
    *height = lh>rh?lh+1:rh+1;
    
    if ((lh - rh >1) || (rh - lh > 1))
        return false;
    
    return left && right;
    
}

int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  struct node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(isBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");    
 
  return 0;
}