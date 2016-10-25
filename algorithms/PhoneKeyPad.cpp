#include <bits/stdc++.h>
using namespace std;

const int ROWS = 4;
const int COLS = 3;

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void printAllPermutaions(char* s, int l, int r)
{
    if (l == r)
        printf("%s\n",s);
    else
    {
        for(int i = l; i <= r; ++i)
        {
            swap(s[l], s[i]);
            printAllPermutaions(s, l+1, r);
        }
    }
}

bool isSafe()

void printNumbers(int keypad[ROWS][COLS])
{
    int x[] = {-1, 0, 0, 1};
    int y[] = {0, -1, 1, 0};
    
    for(int i = 0; i < ROWS; ++i)
    {
        for(int j = 0; j < COLS; ++j)
        {
            
        }
    }
}


int main()
{
    int keypad[ROWS][COLS] = {{1,2,3}, {4,5,6}, {7,8,9},{-1,0,-1}};

    printNumbers(keypad);
    return 0;
}