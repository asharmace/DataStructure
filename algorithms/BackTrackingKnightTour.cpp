#include <iostream>
#include <cstdio>
using namespace std;

static const int N = 8;

void printSolution(int soln[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for(int j = 0 ; j < N ; ++j)
            printf("%3d ", soln[i][j]);
            
        printf("\n");
    }
}

bool isSafe(int x, int y, int soln[N][N])
{
  // printf ("%2d %2d", x, y);
   return (x >= 0 && x < N && y >=0 && y < N && soln[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, int soln[N][N], int xmove[N], int ymove[N])
{
    if (movei == N*N) return true;
    
    int nextx, nexty, k;
    
    for(k = 0; k < N; ++k)
    {
        nextx = x + xmove[k];
        nexty = y + ymove[k];
        
        if( isSafe(nextx, nexty, soln))
        {
            soln[nextx][nexty] = movei;
            if (solveKTUtil(nextx, nexty, movei+1, soln, xmove, ymove))
                return true;
            else
                soln[nextx][nexty] = -1;
        }
    }
    return false;
}

bool solveKT()
{
    int soln[N][N];
    for (int i = 0; i < N; ++i)
        for(int j = 0 ; j < N ; ++j)
            soln[i][j] = -1;

    int xmove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int ymove[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    soln[0][0] = 0;
    if (solveKTUtil(0, 0, 1, soln, xmove, ymove) == false)
    {
        printf("No solution\n");
        return false;
    }
    else
        printSolution(soln);
        
    return true;
}

int main()
{
    solveKT();
}
