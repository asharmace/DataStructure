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

void printKDistant(node* root, int k)
{
    if (root == NULL)
        return;
    
    if ( k == 0)
        printf("%d ", root->data);
        
    printKDistant(root->left, k-1);
    printKDistant(root->right, k -1);
    
}


/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8 
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  
 
  printKDistant(root, 2);
 
  return 0;
}