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

void printArray(int array[], int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        printf("%d ", array[i]);
    
    printf("\n");
}


void printPathsRec(node* root, int paths[], int pathLen)
{
    if (root == NULL)
        return;

    paths[pathLen] =  root->data;
    pathLen++;
    if (root->left == NULL &&  root->right == NULL)
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
    const int PATH_LEN = 1000;
    int paths[PATH_LEN];
    
    printPathsRec(root, paths, 0);
}

int getheight(node* root)
{
    if (root == NULL)
        return 0;
    
    int left = getheight(root->left);
    int right = getheight(root->right);
    
    return left>right?left+1:right+1;
}

void levelOrderRec(node* root, int level)
{
    if (root == NULL)
        return;
    
    if (level == 1)
        printf("%d ", root->data);
    else
    {
        levelOrderRec(root->left, level - 1);
        levelOrderRec(root->right, level - 1);
    }
    
}

void levelOrder(node* root)
{
    int height = getheight(root);
    
    for (int i = 0; i <= height; ++i)
        levelOrderRec(root, i);
}

/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  /* Print all root-to-leaf paths of the input tree */
  printPaths(root);
  
  levelOrder(root);
 
  return 0;
}