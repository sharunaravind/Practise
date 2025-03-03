#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() //NOLINT
{
    int n = 100000;
    int* arr = createArray(n);
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // NOLINT
    insertionsort(arr,n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    printf("Time: %.9f s\n", time_taken);
    return 0;

}
