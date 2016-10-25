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

bool isSumProperty(node* root)
{
    if (root == NULL)
        return true;
    
    if (root->left == NULL && root->right == NULL)
        return true;
    
    int left =0, right = 0;
    if (root->left != NULL)
        left = root->left->data;
    
    if (root->right != NULL)
        right = root->right->data;
    
    return root->data == left + right && isSumProperty(root->left) && isSumProperty(root->right);
}

/* Driver program to test above function */
int main()
{
  struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
 
  return 0;
}