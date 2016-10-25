#include <iostream>
using namespace std;

void printPostOrder(int in[], int pre[], int& preIndex, int start, int end)
{
    if (start > end) return;
    
    int inIndex, currIndex = preIndex;
    for (inIndex = start; inIndex != end; ++inIndex)
        if (pre[preIndex] == in[inIndex]) break;
        
    preIndex++;
    printPostOrder(in, pre, preIndex, start, inIndex -1);
    printPostOrder(in, pre, preIndex, inIndex+1, end);
    cout << pre[currIndex] << " ";
}

// Driver program to test above functions
int main()
{
   int in[] = {4, 2, 5, 1, 3, 6};
   int pre[] =  {1, 2, 4, 5, 3, 6};
   int n = sizeof(in)/sizeof(in[0]);
   int preIndex = 0;
   cout << "Postorder traversal " << endl;
   printPostOrder(in, pre, preIndex, 0, n-1);
   return 0;
}