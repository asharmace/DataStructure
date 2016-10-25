#include <iostream>
#include <cstdio>

using namespace std;
 
struct node
{
    int data;
     node* left, *right;
};

/* Helper function that allocates a new node with the given data.*/
 node* newNode(int data)
{
    node* temp = new node();
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return(temp);
}

node* lca(node* root, int a, int b)
{
    if (root)
    {
        if (root->data > a && root->data > b)
            return lca(root->left, a, b);
        if (root->data < a && root->data < b)
            return lca (root->right, a, b);
    }
    return root;
}
 
/* Driver program to test mirror() */
int main()
{
    // Let us con the BST shown in the above figure
     node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
     node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    getchar();
    return 0;
}