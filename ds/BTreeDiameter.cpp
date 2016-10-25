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

int diameter(node* root, int* dia)
{
    if (root == NULL)
        return 0;
    
    int left = diameter(root->left, dia);
    int right = diameter(root->right, dia);
    
    if (*dia < (left + right + 1))
        *dia = left + right + 1;
    
    return left>right? left+1: right + 1;
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
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  
  int dia = 0;
  
  diameter(root, &dia);
 
  printf("Diameter of the given binary tree is %d\n", dia);
 
  getchar();
  return 0;
}