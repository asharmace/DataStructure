#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int data;
    node* left, *right;
};

node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void swapInt(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void correctBSTUtil(node* root, node** first, node** middle, node** last, node** prev)
{
    if (root)
    {
        correctBSTUtil(root->left, first, middle, last, prev);
        
        if (*prev && root->data < (*prev)->data)
        {
            if(!*first)
            {
                *first = *prev;
                *middle = root;
            }
            else
                *last = root;
        }
        *prev = root;
        
        correctBSTUtil(root->right, first, middle, last, prev);
    }
}

void correctBST(node* root)
{
    node* first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    
    correctBSTUtil(root, &first, &middle, &last, &prev);
    
    if (first && last)
        swapInt( &(first->data), &(last->data) );
    else if (first && middle)
        swapInt( &(first->data), &(middle->data) );
}

void printInorder(node* root)
{
    if (root == NULL ) return;
    
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}
/* Driver program to test above functions*/
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
 
    printf("Inorder Traversal of the original tree \n");
    printInorder(root);
 
    correctBST(root);
 
    printf("\nInorder Traversal of the fixed tree \n");
    printInorder(root);
 
    return 0;
}