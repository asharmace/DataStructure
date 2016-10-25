#include <bits/stdc++.h>

using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

bool isLeaf(Node* root)
{
    return (root->left == NULL && root->right ==NULL);
}

int sumAndMultiplyLevelData(Node* root)
{
    if (root== NULL) return 0;
    int sum = 0;
    int result = 1;
    
    deque<Node*> Q;
    Q.push_back(root);
    Q.push_back(NULL);
    
    while(!Q.empty())
    {
        root = Q.front(); Q.pop_front();
    
        if (root == NULL)
        {
            if (sum != 0)
                result *= sum;
            if (!Q.empty())
                Q.push_back(NULL);
            
            sum = 0;
        }
        else
        {
            if (isLeaf(root))
                sum += root->data;
            else
            {
                if (root->left)
                    Q.push_back(root->left);
                if (root->right)
                    Q.push_back(root->right);
            }
        }
    }
    
    return result;
}
 
// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(10);
 
    cout << "Final product value = "
         << sumAndMultiplyLevelData(root) << endl;
 
    return 0;
}