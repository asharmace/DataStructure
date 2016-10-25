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

int getHeight(node* root)
{
    if (root == NULL)
        return 0;
    
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    
    return left>right?left+1:right+1;
}

void printZigZagRec(node* root, int level, int lToR)
{
    if (root == NULL)
        return;
    
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        if (lToR)
        {
            printZigZagRec(root->left, level - 1, lToR);
            printZigZagRec(root->right, level - 1, lToR);
        }
        else
        {
            printZigZagRec(root->right, level - 1, lToR);
            printZigZagRec(root->left, level - 1, lToR);
        }
    }
}

void printZigZag(node* root)
{
    int height = getHeight(root);
    
    bool lToR = true;
    for(int i = 0; i <= height; ++i)
    {
        printZigZagRec(root, i, lToR);
        lToR = !lToR;
    }
    
}

int getLeafCount(node* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    return getLeafCount(root->left) + getLeafCount(root->right);
}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printZigZag(root);
    
    printf("\nLeaf count of the tree is %d", getLeafCount(root));
 
    return 0;
}