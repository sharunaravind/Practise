#include <stdio.h>
#include <limits.h>

int partition(int* arr,int start,int end)
{
    int p1=start;
    int p2 = end;
    int pivot = arr[start];
    int temp;
    while(p1<p2)
    {   
        while(arr[p1]<pivot)
        {
            p1++;
        }
        while(arr[p2]>pivot)
        {
            p2--;
        }
        if(p1<p2){
            temp = arr[p1];
            arr[p1]=arr[p2];
            arr[p2]=temp;
        }
    }
    temp = arr[start];
    arr[start]=arr[p2];
    arr[p2]=temp;
    return p2;
}

void quickSort(int* arr,int start,int end)
{
    if(start<end)
    {
        int mid = partition(arr,start,end+1);
        quickSort(arr,start,mid-1);
        quickSort(arr,mid+1,end);
    }
}

void main()
{
    int array[] = {40,40,100,2,3,INT_MAX};
    int n = sizeof(array)/sizeof(int);
    quickSort(array,0,n-2);
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",array[i]);
    }

}