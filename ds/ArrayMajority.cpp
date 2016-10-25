#include <iostream>
#include <unordered_map>
using namespace std;

void printMajority(int a[], int n)
{
    unordered_map <int, int> uMap;
    bool found  =false;
    for (int i = 0; i < n; ++i)
    {
        uMap[a[i]]++;

        //cout << x.first << " " << x.second << endl;
        if (uMap[a[i]] > n / 2)
        {
            cout << "majority element = " << a[i] << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "majority not found" << endl;
}


/* Driver function to test above functions */
int main()
{
    int a[] = {1, 3, 3, 1, 2,3,3};
    printMajority(a, 7);
    return 0;
}