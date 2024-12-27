#include <stdio.h>
#include <stdlib.h>

int binary(int *track,int *end,int n,int value)
{
    int start = 0,mid,ender=*end;
    while(start<=ender)
    {
        mid=(start+ender)/2;
        if(track[mid]==value )
        {
            return -2;
        }
        if(track[mid]>value && mid==0)
        {
            return mid;
        }
        else if(track[mid]>value && track[mid-1]<value)
        {
            return mid;
        }
        else if(track[mid]>value && track[mid-1]==value)
        {
            return -2;
        }
        else if(track[mid]>value && track[mid-1]>value)
        {
            ender=mid-1;
        }
        else if(track[mid]<=value)
        {
            start=mid+1;
        }
    }
    return -1;
}

void insert(int *track,int *end,int n,int value)
{
    if(*end==0)
    {
        if(value < track[*end])
        {
            track[*end]=value;
        }
        else if(value>track[*end])
        {
            (*end)++;
            track[*end]=value;
        }   
    }
    else if(*end!=0)
    {
        int position = binary(track,end,n,value);
        if(position == -1)
        {
            (*end)++;
            track[*end]=value;
        }
        else if(position != -2)
        {
            track[position]=value;
        }
    }
}

int lengthOfLIS(int* arr, int n) 
{
    int track[n];
    int end=0;
    track[0]=arr[0];
    for(int i=0;i<n;i++)
    {
        insert(track,&end,n,arr[i]);
    }
    return end+1;
    
}

void main()
{
    int arr[]={1,2,2,2};
    int n=sizeof(arr)/sizeof(int);
    lengthOfLIS(arr,n);
}