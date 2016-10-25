#include <iostream>
#include <cstdio>
using namespace std;

const int ROW = 5;
const int COL = 5;

bool isSafe(int M[ROW][COL], int x, int y, bool visited[ROW][COL] )
{
    return (x >=0 && x < ROW && y >= 0 && y < COL && M[x][y] && !visited[x][y]);
}

void DFS(int M[ROW][COL], bool visited[ROW][COL],  int X[], int Y[], int size, int x, int y)
{
    visited[x][y] = true;

}

int countIslands(int M[ROW][COL])
{
    int count = 0;
    bool visisted[ROW][COL];
    for (int i = 0; i < ROW; ++i)
        for(int j = 0; j < COL; ++j)
            visited[i][j] = false;
    int X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int Y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int i = 0; i < ROW; ++i)
        for(int j = 0; j < COL; ++j)
        {
            if (M[i][j] && !visited[i][j]) 
            {
                DFS(M, visited, x, y, 8, i, j);
                count++;
            }
        }
    return count;
}


// Driver program to test above function
int main()
{
    int M[ROW][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIslands(M));
 
    return 0;
}