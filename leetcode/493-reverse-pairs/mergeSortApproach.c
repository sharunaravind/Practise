#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int totCount=0;
int countPair(int low,int mid,int high,int* arr)
{
    int i = low;
    int j = mid;
    int count=0;
    while(i<mid && j<high)
    {
        if(j<high && (long long)arr[i] > 2LL * arr[j])
        {
            count++;
            // temp=count;
            j++;
        }
        else 
        {
            i++;
            if(i<mid) count+=(j-mid);
        }
    }
    if(i==mid)
    {
        return count;
    }
    else
    {
        count*=(mid-i);
    }
    return count;
}

// int countPair(int low, int mid, int high, int* arr)
// {
//     int count = 0;
//     int j = mid;

//     for (int i = low; i < mid; i++) {
//         while (j < high && (long long)arr[i] > 2LL * arr[j]) {
//             j++;
//         }
//         count += (j - mid);
//     }

//     return count;
// }


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
        }
        else 
        {
            arrayTemp[count++]=arr[j++];
        }
    }
    if(i==mid)
    {
        for(int a=j;a<high;a++)
        {
            arrayTemp[count++]=arr[a];
        }
    }
    else
    {
        for(int a=i;a<mid;a++)
        {
            arrayTemp[count++]=arr[a];
        }
    }
    count=0;
    for(int a = low;a<high;a++)
    {
        arr[a]=arrayTemp[count++];
    }
}

void mergeSort(int low,int high,int* arr)
{
    if(low<high-1)
    {
        int mid = low +( (high - low) / 2);
        mergeSort(low,mid,arr);
        mergeSort(mid,high,arr);
        totCount+=countPair(low, mid, high, arr);
        merge(low,mid,high,arr);
    }
}

int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) return NULL; 
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
    return arr;
}

// int main()
// {
//     int n = 2000000;
//     int* array = createArray(n);
//     struct timespec start, end;
//     clock_gettime(CLOCK_MONOTONIC, &start); // NOLINT
//     mergeSort(0,n,array);
//     clock_gettime(CLOCK_MONOTONIC, &end);
//     double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
//     printf("Time: %.9f s\n", time_taken);
    
//     return 0;
// }

int main()
{
    int array[]={23,11,17,9,9,17,14,24,21,10,20,7,2,11,17,15,16,11,3,24,18,19,12,13,25,19,3,8,10,18,24,12,0,2,19,1,24,22,20,15,7,24,10,11,8,6,3,19,22,13,3,17,7,6,8,10,7,11,22,3,10,6,3,3,23,24,11,10,1,24,25,22,8,12,14,5,9,20,4,10,17,2,18,17,15,6,0,21,7,19,8,23,9,3,25,10,14,7,2,3,25,4,11,15,8,23,9,2,10,24,2,5,16,6,6,24,1,8,21,10,3,15,3,12,14,14,1,3,21,5,25,25,25,16,22,17,14,24,21,6,2,18,13,22,17,17,10,21,21,23,12,5,19,22,10,25,24,2,9,6,16,5,23,23,1,11,1,16,24,20,10,23,20,6,14,4,16,16,23,25,10,25,22,2,23,3,2,16,25,1,14,8,8,6,22,6,3,2,5,10,22,23,23,20,12,7,14,11,6,18,16,10,3,7,11,18,10,1,10,13,13,18,25,22,23,2,20,11,19,21,10,3,21,22,22,15,7,18,3,0,21,5,7,16,25,1,5,4,10,18,15,11,4,19,15,4,1,24,15,11,5,1,18,23,11,4,4,2,24,1,8,8,16,1,24,8,1,13,5,0,14,8,9,14,3,7,9,18,11,11,11,11,24,11,14,13,13,3,10,23,18,11,23,9,25,23,5,1,13,16,21,5,15,7,1,24,7,1,23,1,7,8,17,25,21,4,12,25,21,21,20,7,4,23,17,1,20,11,17,22,22,7,8,13,6,3,5,25,11,15,5,6,7,19,9,20,14,25,14,14,15,14,3,22,18,16,3,11,16,0,14,16,22,0,3,15,15,12,1,11,15,15,17,10,9,5,12,9,13,14,23,8,17,0,10,20,24,18,23,3,1,9,9,23,15,2,22,7,23,24,5,18,25,3,12,17,11,24,20,17,7,5,23,16,22,16,12,23,19,3,18,0,0,16,23,5,2,7,19,2,11,12,6,2,3,6,3,16,16,20,8,24,7,21,18,1,19,0,16,18,8,6,17,23,12,7,25,6,21,24,12,5,18,3,3,16,4,20,14,5,25,2,18,6,5,17,19,12,14,25,15,0,2,24,19,23,11,7,25,24,13,8,18,21,11,24,7,5,19,23,0,0,9,0,9,12,14,12,19,16,6,5,3,2,9,16,9,16,2,4,14,1,19,2,0,17,9,4,23,9,20,12,13,4,5,5,1,9,7,5,16,25,0,17,18,15,8,23,24,18,20,5,5,3,12,11,18,16,4,12,12,14,24,11,11,13,24,16,12,11,2,23,9,11,13,23,4,20,10,14,5,5,2,22,5,22,3,20,24,11,11,19,11,20,0,11,1,9,3,14,1,3,0,6,13,19,6,1,24,14,11,7,3,2,17,8,10,9,24,14,22,5,14,10,20,11,8,1,17,10,19,20,5,7,9,19,15,3,0,21,11,22,12,17,4,15,25,2,7,16,24,17,8,15,18,23,11,7,9,18,7,4,24,2,25,22,2,24,15,15,18,9,1,19,4,10,24,17,24,5,17,8,13,2,20,18,23,7,2,8,6,16,18,24,3,17,14,1,9,5,5,1,18,5,17,5,11,1,5,17,5,23,7,6,23,19,7,20,7,2,22,1,16,23,17,13,13,19,8,18,21,25,16,5,20,17,15,3,4,4,18,2,21,2,3,18,6,9,5,5,4,23,17,12,16,17,16,24,3,6,25,10,3,4,9,2,18,9,16,11,16,18,9,10,1,12,17,16,11,24,2,25,1,14,13,22,2,8,8,25,8,15,19,3,4,19,25,25,20,22,11,9,18,12,22,13,24,13,12,6,8,5,25,0,21,6,0,20,1,17,9,4,2,12,21,10,25,20,19,4,23,23,14,17,16,1,15,18,22,21,2,14,0,9,3,17,2,23,10,0,1,1,0,23,15,0,17,20,4,22,15,0,15,21,10,8,19,9,3,9,8,9,20,24,3,10,5,9,2,12,8,0,0,24,9,17,2,1,0,15,1,17,20,5,25,17,7,21,16,19,11,16,18,6,4,18,3,12,1,2,1,21,22,24,14,4,4,18,25,11,8,7,7,15,19,0,25,7,6,7,9,21,17,24,7,14,2,18,6,24,12,21,16,25,22,17,13,18,17,7,15,24,22,17,1,23,21,0,9,21,15,25,6,3,1,18,13,1,8,21,8,2,24,15,24,17,13,5,8,19,12,7,5,15,2,15,0,8,17,0};
    int n = sizeof(array)/sizeof(array[0]);
    mergeSort(0, n, array);
    printf("%d\n",totCount);

}
