#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int jump(int* arr,int n)
{
    int max=INT_MIN;
    int maxPos;
    // int i=0;
    int jump=0;
    int curr=0;
    int currSize=0;
    while(curr<n)
    {
        currSize=arr[curr];
        for (int i = curr+1; i <= curr+currSize; i++)
        {
            if((arr[i]+i)>=n) 
            {
                maxPos=n;
                break;  //if it can reach the end then we can stop
            }
            else if((arr[i]+i)>max){
                max=arr[i]+i;
                maxPos=i;
            }
        }
        jump++;
        curr=maxPos;
    }
    return jump;
}

void main()
{
    int array[] = {1,4,4};
    int n = sizeof(array)/sizeof(int);
    printf("%d\n",jump(array,n));
}