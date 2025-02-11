#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool increasingTriplet(int* arr, int n) {
    int stack[3]={arr[0],0,0},Topyet=10000000,i,j=0,pos=0,check=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]>stack[pos])
        {
            pos++;
            stack[pos] = arr[i];
        }
        else if(arr[i]<stack[pos])
        {
            if(pos>=1 && stack[pos]<Topyet)
            {
                Topyet=stack[pos];
                check=1;
            }
            while (pos >-1 && stack[pos]>arr[i])
            {
                pos--;
            }
            pos++;
            stack[pos] = arr[i];
        }
        if(pos>=2 || (check==1 && arr[i]>Topyet) )
        {
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
