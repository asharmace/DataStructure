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
   
    return max(getHeight(root->left), getHeight(root->right))+1;
}



void printLevelOrderRec(node* root, int level)
{
    if (root == NULL)
        return;
    
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printLevelOrderRec(root->left, level - 1);
        printLevelOrderRec(root->right, level - 1);
    }
}

void printLevelOrder(node* root)
{
    int height = getHeight(root);
    
    for(int i = 0; i <= height; ++i)
    {
        printLevelOrderRec(root, i);
    }
    
}

node* mirror(node* root)
{
    if (root)
    {
        mirror(root->right);
        mirror(root->left);
        
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
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
    printLevelOrder(root);
    cout << endl;
    root = mirror(root);
    printLevelOrder(root);
    cout << endl;
 
    return 0;
}