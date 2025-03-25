#include <stdio.h>

int tempMin=-1;
void loopolo(int* coins,int quo,int n,int amt)
{
    if(tempMin!=-1 && quo>tempMin) return;
    int reminder;
    for(int i=0;i<n;i++){
        if(coins[i]<=amt){
            reminder=amt-coins[i];
            if(reminder!=0){
                loopolo(coins, quo+1, n, reminder);
            }
            else if((reminder==0 && tempMin==-1) || (reminder==0 && quo<tempMin)){
                tempMin=quo;
            }
        }
    }
}
int coinChange(int* coins, int n, int amt) 
{   
    if(amt==0) return 0;
    tempMin=-1;
    int quotient=1;
    loopolo(coins, quotient, n, amt);
    return tempMin;

}

int main()
{
    int coins[]={1,2,5};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amount =11;
    printf("%d\n",coinChange(coins, n, amount));
    return 0;
}