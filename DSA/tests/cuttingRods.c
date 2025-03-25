#include <limits.h>
#include <stdio.h>

int Max(int a,int b){
    if(a<b) return b;
    else return a;
}

int CutRod(int* p,int n)
{
    if(n==0) return 0;
    int q=INT_MIN+1;
    for(int i=1;i<n;i++)
    {
        q = Max(q,p[i]+CutRod(p,(n-i)));
    }
    return q;
}
int main()
{
    int p[]={1,5,8,9,10,17,19,21,26,30,36,39,45,51,63,69,73,78,84,92,101,1,5,8,9,10,17,19,21,26,30,36,39,45,51,63,69,73,78,84,92,101};
    // int q=INT_MIN;
    printf("%d\n",CutRod(p,2));
}