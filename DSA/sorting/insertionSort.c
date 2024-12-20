#include <stdio.h>

void insertionsort(int *arr,int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(temp<arr[j])
            {
                arr[j+1]=arr[j];
            }
            else if(temp>=arr[j])
            {
                arr[j+1]=temp;
                break;
            }
            if(j==0)
            {
                arr[0]=temp;
            }

        }
    }
}


void main()
{
    int arr[]={12,78,32,5,4,54,4,24};
    int n=sizeof(arr)/sizeof(int);
    insertionsort(arr,n);
    printf("\n");

}
