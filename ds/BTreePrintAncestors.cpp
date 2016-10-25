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

bool printAncestors(node* root, int data)
{
    if (root == NULL)
        return false;
        
    if (root->data == data)
        return true;
        
    if (printAncestors(root->left, data) || printAncestors(root->right, data))
    {
        printf("%d ", root->data);
        return true;
    }
    
    return false;
}

/* Driver program to test above functions*/
int main()
{
 
  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(7);
 
  printAncestors(root, 7);
 
  return 0;
}