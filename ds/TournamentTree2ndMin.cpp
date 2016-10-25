#include <iostream>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;
 
struct node
{
    int data;
     node* left, *right;
};

 node* newNode(int data)
{
    node* temp = new node();
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return(temp);
}

int get2ndMin(node* root)
{
    int secMin = numeric_limits<int>:: max();
    if (root == NULL ) return secMin;
    
    while(root->left != NULL && root->right != NULL)
    {
        if (root->left->data == root->data)
        {
            secMin = min(secMin, root->right->data);
            root = root->left;
        }
        else
        {
            secMin = min(secMin, root->left->data);
            root = root->right;
        }
        //cout << root->data << " " << secMin << endl;
    }
    
    return secMin;
}
 
int main()
{
    //                 1
    //             4       1
    //           4   7   3   1
    //          8 4 7 5 6 3 1 9
    node *root                = newNode(1);
    root->left                = newNode(4);
    root->right               = newNode(1);
    root->left->left          = newNode(4);
    root->left->right         = newNode(5);
    root->left->right->left   = newNode(7);
    root->left->right->right  = newNode(5);
    root->left->left->left    = newNode(8);
    root->left->left->right   = newNode(4);

    root->right->left         = newNode(3);
    root->right->right        = newNode(1);
    root->right->right->left  = newNode(1);
    root->right->right->right = newNode(9);
    root->right->left->left   = newNode(6);
    root->right->left->right  = newNode(3);
 
    cout << get2ndMin(root);
    return 0;
}