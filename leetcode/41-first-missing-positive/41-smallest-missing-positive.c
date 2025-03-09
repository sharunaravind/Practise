#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* arr, int n) {
    int max=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max && arr[i]<=n)
        {
            max=arr[i];
        }
    }
    int hashArray[max];
    for(int i=0;i<max;i++)
    {
        hashArray[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0 && arr[i]<=n)
        {
            hashArray[arr[i]-1]=1;
        }
    }
    int missing;
    int i;
    for(i=0;i<max;i++)
    {
        if(hashArray[i]==0)
        {
            return i+1;
        }
    }
    return i+1;
    
}
void main()
{
    int nums[]={2,1};
    int n=sizeof(nums)/sizeof(int);
    printf("%d", firstMissingPositive(nums,n));
}
   