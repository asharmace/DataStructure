#include <iostream>
using namespace std;

void printPreOrder(int in[],int inStart,int inEnd, int post[],int postStart,int postEnd)
{
    if(inStart > inEnd || postStart > postEnd)
        return ; 
    cout << post[postEnd] << " ";
    int inIndex=0;
    
    for(inIndex=inStart; inIndex<= inEnd; ++inIndex)
        if(in[inIndex]==post[postEnd])
            break;

    printPreOrder(in, inStart, inIndex-1, post, postStart, postStart+inIndex-(inStart+1));
    printPreOrder(in, inIndex+1, inEnd, post, postStart+inIndex-inStart, postEnd-1);
}


// Driver program to test above functions
int main()
{
   int in[] = {4, 2, 5, 1, 3, 6};
   //int pre[] =  {1, 2, 4, 5, 3, 6};
   int post[] = { 4, 5, 2, 6, 3, 1};
   int n = sizeof(in)/sizeof(in[0]);
   cout << "PreOrder traversal " << endl;
   printPreOrder(in, 0, n-1, post, 0, n-1);
   return 0;
}