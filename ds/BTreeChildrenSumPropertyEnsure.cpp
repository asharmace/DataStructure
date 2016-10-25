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

void inOrder(node* root)
{
    if (root == NULL)
        return;
    
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void incrementData(node* root, int num)
{
    if (root->left != NULL)
    {
        root->left->data = root->left->data + num;
        incrementData(root->left, num);
    }
    else if (root->right != NULL)
    {
        root->right->data = root->right->data + num;
        incrementData(root->right, num);
    }
    
}

void convertTree(node* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    
    convertTree(root->left);
    convertTree(root->right);
    
    int left = 0, right = 0;
    
    if (root->left)
        left = root->left->data;
    
    if (root->right)
        right = root->right->data;
    
    int diff = left + right - root->data ;
    
    if (diff > 0)
        root->data = root->data + diff;
    else if (diff < 0)
        incrementData(root, -diff);
}

/* Driver program to test above functions */
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  inOrder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion  ");
  inOrder(root);
 
  return 0;
}