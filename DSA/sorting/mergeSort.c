#include <stdio.h>

void merge(int low,int mid,int high,int* arr)
{
    int i = low;
    int j = mid;
    int count=0;
    int arrayTemp[high-low+1];
    while(i<mid && j<high)
    {
        if(arr[i]<=arr[j])
        {
            arrayTemp[count]=arr[i];
            i++;
        }
        else 
        {
            arrayTemp[count]=arr[j];
            j++;
        }
        count++;
    }
    if(i==mid)
    {
        for(int a=j;a<high;a++)
        {
            arrayTemp[count]=arr[a];
            count++;
        }
    }
    else
    {
        for(int a=i;a<mid;a++)
        {
            arrayTemp[count]=arr[a];
            count++;
        }
    }
    count=0;
    for(int a = low;a<high;a++)
    {
        arr[a]=arrayTemp[count];
        count++;
    }
}

void mergeSort(int low,int high,int* arr)
{
    if(low<high-1)
    {
        int mid = low +( (high - low) / 2);
        mergeSort(low,mid,arr);
        mergeSort(mid,high,arr);
        merge(low,mid,high,arr);
    }
}

void main()
{
    int array[] = {9,5,6,3,4,2,1};
    int n = sizeof(array)/sizeof(int);
    mergeSort(0,n,array);
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }

}


