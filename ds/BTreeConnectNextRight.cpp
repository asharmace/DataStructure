#include <cstdio>
#include <iostream>


using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node* nextRight;
};

node* newNode(int i)
{
    node* temp = new node();
    temp->data = i;
    temp->left = temp->right = temp->nextRight = NULL;
    
    return temp;
}

void connectNextRightRec(node* root)
{
    if (root == NULL)
        return;
        
    if (root->left != NULL)
        root->left->nextRight = root->right;
        
    if (root->right != NULL)
        root->right->nextRight = root->nextRight?root->nextRight->left:NULL;
        
    connectNextRightRec(root->left);
    connectNextRightRec(root->right);

}

void connect(node* root)
{
    root->nextRight = NULL;
    
    connectNextRightRec(root);
}


/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /
    3
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right  = newNode(5);
  root->right->left  = newNode(6);
 
  // Populates nextRight pointer in all nodes
  connect(root);
 
  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->right->data,
        root->left->right->nextRight? root->left->right->nextRight->data: -1);
 
  getchar();
  return 0;
}