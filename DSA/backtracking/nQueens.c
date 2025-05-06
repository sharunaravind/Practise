#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void printArray(int* array,int n)
{
    for(int i=0;i<n;i++)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
}
void print2dArray(int** resultArray,int count,int n)
{
    for(int i=0;i<count+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",resultArray[i][j]);
        }
        printf("\n");
    }
}

void printCharArray(char*** finalResult,int count,int n)
{
    for(int i = 0;i<=count;i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%s\n", finalResult[i][j]);
        }
        printf("\n"); 
    }
}

void arrayToChar(int** resultArray,int count,int n,char*** finalResult)
{
    for(int i=0;i<=count;i++)
    {
        finalResult[i] = (char**)malloc(n*sizeof(char*));
        for(int j=0;j<n;j++)
        {
            finalResult[i][j]=(char*)malloc((n+1)*sizeof(char));
            for(int k=0;k<n;k++)
            {   
                if(resultArray[i][j]==k) finalResult[i][j][k]='Q';
                else finalResult[i][j][k]='.';
            }
            finalResult[i][j][n] = '\0';
        }
    }
}

void addArray(int* array,int n,int** resultArray,int count)
{
    resultArray[count]=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        resultArray[count][i]=array[i];
    }
}

bool Check(int* result,int row,int col)
{
    int x,y;
    for(int i=0;i<row;i++)
    {
        if(result[i]==col) return false;
        x = abs(i-row);
        y = abs(result[i]-col);
        if(x==y) return false;
    }
    return true;
}

void nQueen(int n,int result[n],int depth,int** resultArray,int* count)
{
    bool isChecked=false;
    for(int i=0;i<n;i++)
    {
        isChecked=false;
        isChecked = Check(result, depth, i);
        if(isChecked) 
        {
            result[depth]=i;
            if(depth<(n-1)) nQueen(n, result, depth+1,resultArray,count);
            else if(depth == n-1) break;
        }
    }
    if(isChecked && depth == n-1) 
    {
        (*count)++;
        addArray(result, n, resultArray, *count);
    }
    
}

int main()
{
    int n = 8;
    int result[n];
    int count=-1;
    int** resultArray = (int**)malloc(352*sizeof(int*));
    nQueen(n,result, 0,resultArray,&count);
    char*** finalResult = (char***)malloc(count*sizeof(char**));
    arrayToChar(resultArray, count, n, finalResult);
    print2dArray(resultArray, count, n);
    // printCharArray(finalResult, count, n);
}
