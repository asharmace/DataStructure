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

void doubleTree(node* root)
{
    if (root == NULL)
        return;
        
        
    doubleTree(root->left);
    doubleTree(root->right);
    
    node* n = newNode(root->data);
    n->left = root->left;
    root->left = n;

}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left); 
  printf("%d ", node->data);
  printInorder(node->right);
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
  
  printf("Inorder traversal of the original tree is \n");
  printInorder(root);
 
  doubleTree(root);
   
  printf("\n Inorder traversal of the double tree is \n");  
  printInorder(root);
    
  getchar();
  return 0;
}