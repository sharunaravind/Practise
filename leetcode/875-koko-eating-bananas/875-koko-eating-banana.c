#include <stdio.h>
#include <stdlib.h>

int minEatingSpeed(int* arr, int n, int h) 
{
    int max = arr[0];
    int min = 1;
    int mid;
    int time;
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    while(min<=max){
        mid=(min+max)/2;
        time = 0;
        for(int i=0;i<n;i++) {
            time+=(arr[i]+(mid-1))/mid;
        }
        if(time > h){
            min = mid+1;
        }
        else max = mid-1;
    }
    return min;
}

void main()
{
    int arr[] = {30,11,23,4,20};
    int n = sizeof(arr)/sizeof(int);
    int h = 6;
    printf("%d\n",minEatingSpeed(arr,n,h));
}