#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    node* left;
    node* right;
};

template <typename T>
node<T>* newNode(T data)
{
    node<T>* temp = new node<T>();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

template <typename T>
void postOrderTrav(node<T>* root)
{
    if (root == NULL)
        return;
    
    postOrderTrav(root->left);
    postOrderTrav(root->right);
    cout << root->data <<" ";
}

template <typename T>
int searchIndex(T* array, int start, int end, T data)
{
    for(int i = start; i < end; ++i)
        if (array[i] == data)
            return i;
}

template <typename T>
node<T>* buildTree(T* pre, T* in, int start, int end)
{
    static int preIndex = 0;
    if (start > end)
        return NULL;
    
    int inIndex = searchIndex(in, start, end, pre[preIndex]);
    
    node<T>* temp = newNode(pre[preIndex++]);
    
    if (start == end)
        return temp;
    
    temp->left = buildTree(pre, in, start, inIndex - 1);
    temp->right = buildTree(pre, in, inIndex + 1, end);
    
    return temp;
}



int main()
{
    int preOrder[] =  {15, 5, 3, 12, 10, 6, 7, 13, 16, 20, 18, 23};
    int inOrder[] =   {3, 5, 6, 7, 10, 12, 13, 15, 16, 18, 20, 23};
    int postOrder[] = {3, 7, 6, 10, 13, 12, 5, 18, 23, 20, 16, 15};
    
    int size = sizeof(preOrder)/ sizeof(preOrder[0]);
    node<int>* root = buildTree(preOrder, inOrder, 0, size);
    
    for (int i = 0; i < size; ++i)
        cout << postOrder[i] << " " ;
    
    cout << endl;
    
    postOrderTrav(root);
}