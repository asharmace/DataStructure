#include<stdio.h>

#define n 6 // n is the number of towers

int min(int a, int b){
    return a<=b ? a : b; 
}

void main(){

    int th[n]={1,6,2,4,7,3}; // th: tower height
    int mol[n],mor[n]; // mol: max on left, mor: max on right
    int max=0;
    int i = 0;
    
    for(i=0; i<n; i++)
    {
        if( th[i] >= max)
        {
            max = th[i];
            mol[i] = 0;
        }
        else
        {
            mol[i] = max;
        }
    }
	
    max = 0;

    for(i=n-1; i>=0; i--)
    {
        if( th[i] >= max)
        {
            max = th[i];
            mor[i] = 0;
        }
        else
        {
            mor[i] = max;
        }
    }
	
    int sumwater = 0;

    for( i=0; i<n; i++)
    {
        if(mol[i]!=0 && mor[i]!=0)
        {
            sumwater+= min(mol[i],mor[i]) - th[i];
        }
    }
    printf("Water accumalation is %d", sumwater);
}