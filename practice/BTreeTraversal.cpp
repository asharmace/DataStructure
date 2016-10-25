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

void printPreorder(node* root)
{
    if (root == NULL)
        return;
    
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(node* root)
{
    if (root == NULL)
        return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printInorder(node* root)
{
    if (root == NULL)
        return;
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int getHeight(node* root)
{
    if (root == NULL )
        return 0;

    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void printLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)    
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void printLevelOrder(node* root)
{
    int height = getHeight(root);
    for(int i = 1; i <= height; ++i)
        printLevel(root, i);

}

void printLevelOrderNR(node* root)
{
    deque<node*> Q;
    if (root == NULL)
        return;
        
    Q.push_back(root);
    
    while (!Q.empty())
    {
        root = Q.front();
        Q.pop_front();
        
        cout << root->data << " " ;
        
        if (root->left)
            Q.push_back(root->left);
        if(root->right)
            Q.push_back(root->right);
    } 
}

int diameter(node* root)
{
    if (root == NULL)
        return 0;
}


int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
     
     printf("\nLevel Order traversal of binary tree is \n");
     printLevelOrder(root);
     
     printf("\nLevel Order traversal of binary tree is \n");
     printLevelOrderNR(root);
     
     int dia = 0;
     int height = diameter(root, dia);
     printf("\nDiameter of the given binary tree is %d\n", dia);
     return 0;
}