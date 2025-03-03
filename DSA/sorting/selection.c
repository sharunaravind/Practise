#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectiionSort(int *arr,int n)
{
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
        // printf("%d ",min);
        temp= arr[minIndex];
        arr[minIndex]=arr[pos];
        arr[pos]=temp;
        pos++;
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
    
    int n=100000;
    int* arr = createArray(n);
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // NOLINT
    selectiionSort(arr,n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    printf("Time: %.9f s\n", time_taken);
    return 0;

}
