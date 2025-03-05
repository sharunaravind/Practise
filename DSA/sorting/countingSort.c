#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Countingsort(int *arr,int n)
{
    int max=arr[0],temp = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    max++;
    int count[max];
    for(int i=0;i<max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]+=1;
    }
    for(int i=0;i<max;i++){
        if(count[i]==0) continue;
        while(count[i]-- > 0){
            arr[temp++]=i;
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
    int n = 20000000;
    int* arr = createArray(n);
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // NOLINT
    Countingsort(arr,n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    printf("Time: %.9f s\n", time_taken);
    return 0;

}
