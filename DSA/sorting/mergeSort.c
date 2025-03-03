#include <stdio.h>
#include <stdlib.h>
// #include <linux/time.h>
#include <time.h>


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
            arrayTemp[count++]=arr[i++];
            // i++;
        }
        else 
        {
            arrayTemp[count++]=arr[j++];
            // j++;
        }
        // count++;
    }
    if(i==mid)
    {
        for(int a=j;a<high;a++)
        {
            arrayTemp[count++]=arr[a];
            // count++;
        }
    }
    else
    {
        for(int a=i;a<mid;a++)
        {
            arrayTemp[count++]=arr[a];
            // count++;
        }
    }
    count=0;
    for(int a = low;a<high;a++)
    {
        arr[a]=arrayTemp[count++];
        // count++;
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

int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) return NULL; 
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
        // printf("%d ",arr[i]);
    }
    return arr;
}

int main()
{
    int n = 2000000;
    int* array = createArray(n);
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // NOLINT
    mergeSort(0,n,array);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
    printf("Time: %.9f s\n", time_taken);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",array[i]);
    // }
    return 0;
}


