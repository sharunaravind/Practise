#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t n1,n2,n3;
    int x=0;
    int *pointer = &x;
    // fork();
    // fork();
    // printf("hello\n");
    n1=fork();
    if(n1==0)
    {
        for(int i=0;i<1000000000;i++);
        printf("1 billion count by child\n");
        
    }
    if(n1>0)
    {
        for(int i=0;i<1000000000;i++);
        printf("1 billion count by parent\n");
        fork();
        
    }
    // for(int i=0;i<2000000000;i++);
    // printf("2 billion printed");

    // if(n1<0) 
    // {
    //     printf("fork error no child created");
    //     exit(1);
    // }
    // else if(n1==0)
    // {
    //     (*pointer)++;
    //     printf("from child process %d %p\n",*pointer,pointer);
    // }
    // else if(n1>0)
    // {
    //     (*pointer)++;
    //     printf("from parent process %d %p\n",*pointer,pointer);
    // }
    return 1;
}