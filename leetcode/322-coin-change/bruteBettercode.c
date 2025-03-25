#include <limits.h>
#include <stdio.h>

int min(int a,int b){
    if(a>b) return b;
    return a;
}

int CountChange(int* coins,int n,int reminder)
{
    if(reminder==0) return 0;
    int check=1,count=INT_MAX,res;
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=reminder)
        {
            check=0;
            res=CountChange(coins,n,reminder-coins[i]);
            if(res!=-1) count=min(count,1+res);
        }
    }
    if(check==1) return -1;
    return count;
}

int main()
{
    int coins[] = {1,4,6};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amount =13;
    printf("%d\n",CountChange(coins, n, amount));
    return 0;
}