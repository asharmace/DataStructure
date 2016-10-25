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



int getMaxWidthRec(node* root, int* curMax)
{
    if (root == NULL)
        return 0;

    int leftMax = 0, rightMax = 0;
    int left = getMaxWidthRec(root->left, &leftMax);
    int right = getMaxWidthRec(root->right, &rightMax);
    
    

}

int getMaxWidth(node* root)
{
    int maxWidth
    getMaxWidthRec(root, &maxWidth);
    return maxWidth;
}

/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);    
  root->right->right->left  = newNode(6);    
  root->right->right->right  = newNode(7);      
 
  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8 
              /  \
             6   7
  */ 
  printf("Maximum width is %d \n", getMaxWidth(root));  
  getchar();
  return 0;
}