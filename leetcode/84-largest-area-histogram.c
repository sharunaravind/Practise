#include <limits.h>
#include <stdio.h>

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int largestRectangleArea(int* arr, int n) 
{
    int stack[n];
    int top=-1,current,popped,count,tempSum=0,temp;
    int maxRect=INT_MIN;
    for(int i=0;i<n;i++)
    {   
        current=arr[i];
        if(top==-1 || stack[top]<current) stack[++top]=arr[i];
        else{
            count=0;
            while(top > -1 && stack[top]>current)
            {
                popped=stack[top--];
                ++count;
                maxRect=max(popped*count,maxRect);
            }
            ++count;
            maxRect=max(current*count,maxRect);
            for(int i=0;i<count;i++)
            {
                stack[++top]=current;
            }
        }
    }
    count=0;
    while(top>=0)
    {
        temp=stack[top--];
        count++;
        while(top>=0 && stack[top]==temp)
        {
            count++;
            top--;
        }
        maxRect=max(temp*count,maxRect);
    }
    // maxRect=max(tempSum,maxRect);
    return maxRect;
}


int main()
{
    int array[]={3, 5, 1, 7, 5, 9};
    int n = sizeof(array)/sizeof(n);
    printf("%d\n",largestRectangleArea(array,n));
    return 0;
}