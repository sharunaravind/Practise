#include <stdio.h>
#include <limits.h>

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void printgrid(int row,int col,int grid[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("\t%d",grid[i][j]);
        }
        printf("\n");
    }
}

void printpath(int row,int col,int grid[row][col],int x,int y,int count)
{
    int low = INT_MIN,newX,newY;
    int newRow,newCol;
    for(int i=0;i<4;i++)
    {
        newRow=x+dir[i][0];
        newCol=y+dir[i][1];
        if(newRow<0) 
        newRow=row-1;
        else if(newRow>row-1) 
        newRow=0;
        if(newCol<0) 
        newCol=col-1;
        else if(newCol>col-1) 
        newCol=0;
        if(grid[newRow][newCol] < 0 && grid[newRow][newCol] > low)
        {
            low=grid[newRow][newCol];
            newX=newRow;
            newY=newCol;
        }
    }
    printf("%d %d %d\n",count,newX,newY);
    if(grid[newX][newY]!=-1) printpath(row, col, grid, newX, newY, count+1);

}   

void solvegrid(int row,int col,int grid[row][col],int x,int y,int depth)
{
    // printgrid(row, col, grid);
    int newRow,newCol;
    grid[x][y]=depth;
    for(int i=0;i<4;i++)
    {
        newRow=x+dir[i][0];
        newCol=y+dir[i][1];
        if(newRow<0) 
        newRow=row-1;
        else if(newRow>row-1) 
        newRow=0;
        if(newCol<0) 
        newCol=col-1;
        else if(newCol>col-1) 
        newCol=0;
        // if(grid[newRow][newCol]==2)
        // {
        //     solvegrid(row, col, grid, newRow, newCol, depth-1);
        // }
        if(newRow>=0 && newRow<row && newCol>=0 && newCol<col)
        {
            if(grid[newRow][newCol]==0)
            {
                solvegrid(row, col, grid, newRow, newCol, depth-1);
            }
            else if(grid[newRow][newCol]<0 && (depth-1)>grid[newRow][newCol])
            {
                grid[newRow][newCol]=depth-1;
                solvegrid(row, col, grid, newRow, newCol, depth-1);
            }
        }
    }
}

int main()
{
    int row = 10;
    int col = 10;
    int grid[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==1) 
            {
                solvegrid(row,col,grid,i,j,-1);
                break;
            }
        }
    }
    printgrid(row, col, grid);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==2) 
            {
                printpath(row,col,grid,i,j,1);
                break;
            }
        }
    }
    
}