#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool increasingTriplet(int* arr, int n) {
    int bottomYet=10000000,topYet=100000000;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<bottomYet)
        {
            bottomYet=arr[i];
        }
        else if(arr[i]<topYet)
        {
            topYet=arr[i];
        }
        else{
            return true;
        }
    }
    return false;
}

void main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bool y = increasingTriplet(arr,n);
    printf("%d\n",y);
}
