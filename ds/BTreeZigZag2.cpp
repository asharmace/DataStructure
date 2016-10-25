#include <cstdio>
#include <iostream>
#include <list>

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

void printZigZag(node* root)
{
    if (root == NULL) return;
    
    bool direction = true;
    
    list<node*> Q;
    Q.push_back(root);
    Q.push_back(NULL);
    
    while (!Q.empty())
    {
    
        node* temp = Q.front(); Q.pop_front();
        
        if (temp == NULL)
        {
            direction = !direction;
            if (!Q.empty()) Q.push_back(NULL);    
        }
        else
        {
            printf("%d ",temp->data);
            fflush(stdin);
            if (direction)
            {
                if (temp->left) Q.push_back(temp->left);
                if (temp->right) Q.push_back(temp->right);
            }
            else
            {
                if (temp->right) Q.push_back(temp->right);
                if (temp->left) Q.push_back(temp->left);
            }
        }
    }
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
    
    //printf("\nLeaf count of the tree is %d", getLeafCount(root));
 
    return 0;
}

