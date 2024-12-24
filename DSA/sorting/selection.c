#include <stdio.h>

void selectiionSort(int *arr,int n)
{
    //hello?
    int temp,pos=0,minIndex,min=arr[0];
    while(pos<n)
    {
        min=arr[pos];
        for(int i=pos;i<n;i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
                minIndex=i;
            }
        }
        printf("%d ",min);
        temp= arr[minIndex];
        arr[minIndex]=arr[pos];
        arr[pos]=temp;
        pos++;
    }

    
}
void main()
{
    int arr[]={12,78,32,5,4,54,4,24};
    int n=sizeof(arr)/sizeof(int);
    selectiionSort(arr,n);
    printf("\n");

}
