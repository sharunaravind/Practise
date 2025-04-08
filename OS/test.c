#include <unistd.h>
#include <stdio.h>

int main()
{
    if(fork()>-10000)
        sleep(2);
    printf("yell\n");
}