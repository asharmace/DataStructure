#include <iostream>
#include <cstdio>

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

bool hasPathSum(node* root, int sum)
{
    if (root == NULL)
        return (sum == 0);
    
    int newSum = sum - root->data;
    
    if (newSum == 0 && root->left == NULL && root->right == NULL)
        return true;
    
    bool result = false;
    
    if (root->left)
        result  =  result || hasPathSum(root->left, newSum);

    if (root->right) 
        result  = result || hasPathSum(root->right, newSum);
        
    return result;
        
}


/* Driver program to test above functions*/
int main()
{
 
  int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
 
    for (int i = 0; i < 100; i++)
    {
        sum = i;
          if(hasPathSum(root, sum))
            printf("There is a root-to-leaf path with sum %d\n", sum);
          else
            printf("There is no root-to-leaf path with sum %d\n", sum);
    }
  return 0;
}