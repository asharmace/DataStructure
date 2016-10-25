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

void printArray(int* arr, int arrayLen)
{
    for (int i = 0; i < arrayLen; i++)
        printf("%d ", arr[i]);
        
    printf("\n");
}

void printPathsRec(node* root, int* paths, int pathLen)
{
    if (root == NULL)
        return;
        
    paths[pathLen++] = root->data;
    
    if (root->left == NULL && root->right == NULL)
    {
        printArray(paths, pathLen);
    }
    else
    {
        printPathsRec(root->left, paths, pathLen);
        printPathsRec(root->right, paths, pathLen);
    }
}

void printPaths(node* root)
{
    const int MAX_ELEMENTS = 1000;
    int paths[MAX_ELEMENTS];
    
    printPathsRec(root, paths, 0);
}


/* Driver program to test above functions*/
int main()
{ 
  
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
  
  printPaths(root);
  return 0;
}