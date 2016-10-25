#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    char data;
    node* left;
    node* right;
};

node* newNode(char c)
{
   node* temp = new node();
   temp->data = c;
   temp->left = temp->right = NULL;
   return temp;
}

void inOrder(node* root)
{
    if (root == NULL)
        return;
    
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

int search(char* in, int start, int end, char c)
{
    for (int i = start; i <= end; ++i)
        if (in[i] == c)
            return i;
}

node* buildTree(char* in, char* pre, int inStart, int inEnd)
{
    static int preIndex = 0;
    
    if (inStart > inEnd)
        return NULL;
        
    int inIndex = search(in, inStart, inEnd, pre[preIndex]);
    
    node* n = newNode(pre[preIndex++]);
    
    if (inStart == inEnd)
        return n;
        
    n->left = buildTree(in, pre, inStart, inIndex - 1);
    n->right = buildTree(in, pre, inIndex + 1, inEnd);
    
    return n;
}

/* Driver program to test above functions */
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  node *root = buildTree(in, pre, 0, len - 1);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
}