#include <stdio.h>
#include <stdlib.h>

int longestIncreasingPath(int** arr, int n, int* matrixColSize) 
{
    int m=*matrixColSize; 
    int mem[n][m];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            mem[i][j]=0;
        }
    }

}

void singleLongest(int** arr,int n,int m,int mem[n][m])
{
    
}


void main()
{
    int n=3;
    int m=3;
    int **arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(m*sizeof(int));
        for(int j=0;j<m;j++)
        {
            scanf("%d",(*(arr+i)+j));
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}