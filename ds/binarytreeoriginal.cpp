#include <iostream>
#include <sys/unistd.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    
    // node(): data(0), left(0), right(0){}
    node(int v): data(v), left(NULL), right(NULL){}
    ~node() 
    {
        if (left)  delete left;
        if (right) delete right;
    }
};

class BinaryTree
{
    private:
        node* root;
        void inOrder(node* root);
        void preOrder(node* root);
        void postOrder(node* root);

        void insert(node*& root, int val);
        void deleteAll(node*& root);
        
        int getHeight(node* root);
        void printLevelOrder(node* root);
        void printGivenLevel(node* root, int level);
        
    public:
        BinaryTree() { root = NULL;}
        ~BinaryTree() 
        {
            deleteAll(root);
            cout << "Deleted BinaryTree" << endl;
        }
    
        void insert(int val);
        
        int getHeight();
       

       
        void inOrder();
        void preOrder();
        void postOrder();
        void levelOrder();

};

int BinaryTree::getHeight()
{
    return getHeight(root);
}

void BinaryTree::insert(int val)
{
    insert(root, val);
}

void BinaryTree::insert(node*& root, int val)
{
    if (root == NULL)
    {
        node* temp = new node(val);
        root = temp;
        cout << "inserted " << val << endl;
        return;
    }
    
    if (root->data > val)
        insert(root->left, val);
    else
        insert(root->right, val);
}

void BinaryTree::deleteAll(node*& root)
{
    if (root == NULL)
        return;
    
    deleteAll(root->left);
    deleteAll(root->right);
    
    delete(root);
    root = NULL;
}

int BinaryTree::getHeight(node* root)
{
    if (root == NULL)
        return 0;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

void BinaryTree::inOrder()
{
    inOrder(root);
}

void BinaryTree::preOrder()
{
    preOrder(root);
}

void BinaryTree::postOrder()
{
    postOrder(root);
}

void BinaryTree::levelOrder()
{
    printLevelOrder(root);
}

        
void BinaryTree::preOrder(node* root)
{
    if (root == NULL)
        return;
    
    cout << root->data << "," ;
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree::inOrder(node* root)
{
    
    if (root == NULL)
        return;
    
    inOrder(root->left);
    cout << root->data << "," ;
    inOrder(root->right);
}

void BinaryTree::postOrder(node* root)
{
    if (root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "," ;
}

void BinaryTree::printLevelOrder(node* root)
{
  int h = getHeight(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}     
 
/* Print nodes at a given level */
void BinaryTree::printGivenLevel(node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    cout <<  root->data << ",";
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

int main()
{
    BinaryTree* b = new BinaryTree();
    int array[] = {5,3,10,4,6,9,11,2,8,13,7};
    int size = sizeof(array)/ sizeof(array[0]);
    for (int i = 0; i < size; ++i)
    {
        b->insert(array[i]);
    }
    b->inOrder();
    cout <<endl;
    b->preOrder();
    cout <<endl;
    b->postOrder();
    cout <<endl;
    cout << "height = " <<b->getHeight() <<endl;
    cout <<endl;
    b->levelOrder();
    cout <<endl;
    delete b;
}