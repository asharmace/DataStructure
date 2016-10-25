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
        
    int left = getHeight(root->left) + 1;
    int right = getHeight(root->right) + 1;
    
    return left>right?left:right;
}

int getWidthRec(node* root, int level, int* width)
{
    if (root == NULL)
        return 0;
   
   if (level == 1)
        *width = *width + 1;

   getWidthRec(root->left, level - 1, width);
   getWidthRec(root->right, level - 1, width);
    
}

int getMaxWidth(node* root)
{
    int maxWidth = 0;
    int height = getHeight(root);
    for (int i = 0; i < height; ++i)
    {
        int width = 0;
        getWidthRec(root, i, &width);
        if(maxWidth < width)
            maxWidth = width;
    }
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
  root->right->left = newNode(9);    
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
  return 0;
}