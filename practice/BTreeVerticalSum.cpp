#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

/* Driver program to test above functions*/

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
}

void printArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum +=  arr[i];
    cout << sum << endl;
}


void printVerticalSum(node* root, int path[], int pathLen)
{
    if (root == NULL)
        return;
        
    path[pathLen] = root->data;
    pathLen++;
    if (root->left == NULL && root->right == NULL)
        printArray(path, pathLen);

    printVerticalSum(root->left, path, pathLen);
    printVerticalSum(root->right, path, pathLen);
    
}



void printVerticalSum2(node* root, int sum)
{
    if (root == NULL)
        return;
        
    sum += root->data;
    if (root->left == NULL && root->right == NULL)
        cout << sum << endl;

    printVerticalSum2(root->left, sum);
    printVerticalSum2(root->right, sum);
    
}

int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
     root->right->left     = newNode(6);
     root->right->right   = newNode(7); 

     int path[200];
     int pathLen = 0;
     printVerticalSum(root, path, pathLen);
     cout << endl << endl << endl;
     printVerticalSum2(root, 0);
     return 0;
}