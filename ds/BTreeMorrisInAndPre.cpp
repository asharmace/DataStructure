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

void preorder(node* root)
{
    if (root == NULL)
        return;
        
    printf("%d ", root->data);
    
    preorder(root->left);
    preorder(root->right);
}

void inOrder(node* root)
{
    if (root == NULL)
        return;
        
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void morrisTraversal(node* root)
{
    if (root == NULL)
        return;
        
    node* curr = root, *pre;
    
    while (curr)
    {
        if (curr->left == NULL)
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
                
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                printf("%d ", curr->data);
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
}

void morrisTraversalPreorder(node* root)
{
    if (root == NULL)
        return;
        
    node* curr = root, *pre;
    
    while(curr)
    {
        if (curr->left == NULL)
        {
            printf("%d ", curr->data);
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
                
            if (pre->right == NULL)
            {
                printf("%d ", curr->data);
                pre->right = curr;
                curr = curr->left;
            }
            else
            {   
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
}

/* Driver program to test above functions*/
int main()
{
    struct node* root = NULL;
 
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
 
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
 
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
 
    morrisTraversalPreorder(root);
 
    printf("\n");
    preorder(root);
    printf("\n");
 
 
    root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 

    inOrder(root);
    printf("\n");

    morrisTraversal(root);
    printf("\n");
 
    return 0;
}