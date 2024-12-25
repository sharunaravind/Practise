#include <stdio.h>
#include <stdlib.h>

int path;
void singleLongest(int** arr,int n,int m,int **mem,int x,int y)
{
   int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
   int newRow,newCol,check=0;
   for(int i=0;i<4;i++){
        newRow=x+dir[i][0];
        newCol=y+dir[i][1];
        if(newRow>=0 && newRow < n && newCol >=0 && newCol < m && arr[newRow][newCol]>arr[x][y]){
            check=1;
            if(mem[newRow][newCol]==0){
                singleLongest(arr,n,m,mem,newRow,newCol);
            }
            if(mem[x][y]<mem[newRow][newCol]+1){
                mem[x][y]=mem[newRow][newCol]+1;
                if(mem[x][y]>path){
                    path=mem[x][y];
                }
            }
        }
   }
   if(check==0){
    mem[x][y]=1;
    if(1>path){
        path=1;
    }
   }
}
int longestIncreasingPath(int** arr, int n, int* matrixColSize) {
    path =0;
    int m=*matrixColSize; 
    int **mem = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
    mem[i] = (int*)calloc(m, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mem[i][j]==0){
                singleLongest(arr,n,m,mem,i,j);
            }
        }
    }
    return path;
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
    longestIncreasingPath(arr,n,&m);
}