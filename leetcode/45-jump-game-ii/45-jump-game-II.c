#include <stdio.h>
#include <limits.h>

int jump(int* arr,int n)
{
    if(n==1) return 0;
    int i=0,jump=0,maxReach,maxVal=INT_MIN,index,value = 0;
    while(i<n){   
        jump++;
        maxReach=i+arr[i];
        if(maxReach>=n-1) return jump;
        while(value<maxReach){
            value++;
            if((arr[value]+value)>=maxVal){
                maxVal=arr[value]+value;
                index=value;
            }
        }
        i=index;
    } 
    return jump;      
}

void main() //NOLINT
{
    int array[] = {2,3,0,1,4};
    int n = sizeof(array)/sizeof(int);
    printf("%d\n",jump(array,n));
}