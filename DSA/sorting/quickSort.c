#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int partition(int* arr,int start,int end)
{
    int p1=start;
    int p2 = end+1;
    int pivot = arr[start];
    int temp;
    while(p1<p2)
    {   

        while(arr[++p1]<pivot);
        while(arr[--p2]>pivot);
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
        int mid = partition(arr,start,end);
        quickSort(arr,start,mid-1);
        quickSort(arr,mid+1,end);
    }
}

int* createArray(int size) {
    int* arr = (int*)malloc((size * sizeof(int))+1);
    if (!arr) return NULL; 
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
        // printf("%d ",arr[i]);
    }
    printf("\n\n");
    return arr;
}

void main()
{
    
    int n = 2000000;
    // int n = 100;
    int* array = createArray(n);
    array[n]=INT_MAX;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    quickSort(array,0,n-2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
    // {
    // for(int i=0;i<n-1;i++)
    // {
    //     printf("%d ",array[i]);
    // }
    // printf("\n");
    // }   
    printf("Time: %.9f s\n", time_taken);
    
}