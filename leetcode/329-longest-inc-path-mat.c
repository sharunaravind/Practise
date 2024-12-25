#include <stdio.h>
#include <stdlib.h>

void singleLongest(int** arr,int n,int m,int mem[n][m],int i,int j,int depth,int* path)
{
    int check=0;
     if(i+1<n && arr[i+1][j]>arr[i][j])
    {
        if(mem[i+1][j]==1)
        {
            check=1;
            singleLongest(arr,n,m,mem,i+1,j,depth+1,path);
            if((*path)-(depth-1)>mem[i][j])
            {
                mem[i][j]=(*path)-(depth-1);
            }
        }
        if(mem[i+1][j]>1)
        {
            if(mem[i+1][j]+1>mem[i][j])
            {
                mem[i][j]=mem[i+1][j]+1;
                if(mem[i+1][j]+depth>*path){
                *path=mem[i+1][j]+depth;}
            }
        }
    }
    if(j+1<m && arr[i][j+1]>arr[i][j])
    {
        if(mem[i][j+1]==1)
        {
            check=1;
            singleLongest(arr,n,m,mem,i,j+1,depth+1,path);
            if((*path)-(depth-1)>mem[i][j])
    {
        mem[i][j]=(*path)-(depth-1);
    }
        }
        if(mem[i][j+1]>1)
        {
            // printf("%d %d",mem[i][j],mem[i][j+1]);
            if(mem[i][j+1]+1>mem[i][j])
            {
                mem[i][j]=mem[i][j+1]+1;
                if(mem[i][j+1]+depth>*path){
                *path=mem[i][j+1]+depth;}
            }
        }
    }
    if(i-1>=0 && arr[i-1][j]>arr[i][j])
    {
        if(mem[i-1][j]==1)
        {
            check=1;
            singleLongest(arr,n,m,mem,i-1,j,depth+1,path);
            if((*path)-(depth-1)>mem[i][j])
    {
        mem[i][j]=(*path)-(depth-1);
    }
        }
        if(mem[i-1][j]>1)
        {
            if(mem[i-1][j]+1>mem[i][j])
            {
                mem[i][j]=mem[i-1][j]+1;
                if(mem[i-1][j]+depth>*path){
                *path=mem[i-1][j]+depth;}
            }
        }
    }
    if(j-1>=0 && arr[i][j-1]>arr[i][j])
    {
        if(mem[i][j-1]==1)
        {
            check=1;
            singleLongest(arr,n,m,mem,i,j-1,depth+1,path);
            if((*path)-(depth-1)>mem[i][j])
    {
        mem[i][j]=(*path)-(depth-1);
    }
        }
        if(mem[i][j-1]>1)
        {
            if(mem[i][j-1]+1>mem[i][j])
            {
                mem[i][j]=mem[i][j-1]+1;
                if( mem[i][j-1]+depth>*path){
                *path= mem[i][j-1]+depth;}
            }
        }
    }
    if(check==0)
    {
        // if(depth>*path)
        {
            *path=depth;
        }
    }
    // if((*path)-(depth-1)>mem[i][j])
    // {
    //     mem[i][j]=(*path)-(depth-1);
    // }
}

int longestIncreasingPath(int** arr, int n, int* matrixColSize) 
{
    int m=*matrixColSize; 
    int mem[n][m];
    int path=0,pathmax=0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            mem[i][j]=1;
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if(mem[i][j]==1)
            {
                path=0;
                singleLongest(arr,n,m,mem,i,j,1,&path);
            }
        }
    }
    // printf("%d\n",pathmax);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ",mem[i][j]);
            if(mem[i][j]>pathmax)
            {
                pathmax=mem[i][j];
            }
        }
        printf("\n");
    }
    return pathmax;

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