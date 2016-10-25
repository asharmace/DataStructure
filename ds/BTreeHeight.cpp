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

void deleteNode(node* root)
{
    delete root;
    root = NULL;
}

int max(int i, int j)
{
    return i>j?i:j;
}
int maxDepth(node* root)
{
    if (root == NULL)
        return 0;
    
    int left, right;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    
    return max(left, right) + 1;
    
}

int size(node* root)
{
    if (root == NULL)
        return 0;
    
    return size(root->left) + size(root->right) + 1;
}

void deleteTree(node* root)
{
    if (root == NULL)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    printf("Deleting root with data = %d\n", root->data);
    deleteNode(root);
}

void inOrder(node* root)
{
    if (root == NULL)
        return;
    
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void mirror(node* root)
{
    if (root == NULL)
        return;
    
    mirror(root->left);
    mirror(root->right);
    
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    printf("Hight of tree is %d\n", maxDepth(root));
    printf("Size of the tree is %d\n", size(root)); 


    inOrder(root);
    printf("\n");
    mirror(root);
    inOrder(root);
    printf("\n");
    
    deleteTree(root);  
    root = NULL;
 
    printf("\nTree deleted ");
   
    return 0;
}