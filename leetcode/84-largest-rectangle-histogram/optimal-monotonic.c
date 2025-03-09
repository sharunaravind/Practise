#include <limits.h>
#include <stdio.h>

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

void initialise(int* arr,int n,int value)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=value;
    }
}

int largestRectangleArea(int* arr, int n) 
{
    int smaller_front[n];
    int popped,maxRect=INT_MIN,tempMax;
    int smaller_back[n];
    initialise(smaller_front,n,n-1);
    initialise(smaller_back, n,-1);
    int stackHeight[n],stackPos[n],top=-1;
    for(int i=0;i<n;i++)
    {
        if(top==-1 || arr[i]>=stackHeight[top]) 
        {
            stackHeight[++top]=arr[i];
            stackPos[top]=i;
        }
        else if(arr[i]<stackHeight[top])
        {
            while(top>=0 && stackHeight[top]>arr[i])
            {
                smaller_front[(stackPos[top])]=i;
                // printf("\n%d %d %d\n",stackPos[top],i,smaller_front[stackPos[top]]);
                top--;
            }
            stackHeight[++top]=arr[i];
            stackPos[top]=i;
        }
    }
    top=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(top==-1 || arr[i]>=stackHeight[top]) 
        {
            stackHeight[++top]=arr[i];
            stackPos[top]=i;
        }
        else if(arr[i]<stackHeight[top])
        {
            while(top>=0 && stackHeight[top]>arr[i])
            {
                smaller_back[(stackPos[top])]=i;
                top--;
            }
            stackHeight[++top]=arr[i];
            stackPos[top]=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        tempMax=(arr[i]*(smaller_front[i]-smaller_back[i]));
        maxRect=max(maxRect,tempMax);
    }
    return maxRect;
}


int main()
{
    int array[]={3, 5, 1, 7, 5, 9};
    int n = sizeof(array)/sizeof(array[0]);
    printf("%d\n",largestRectangleArea(array,n));
    return 0;
}