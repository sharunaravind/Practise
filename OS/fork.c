#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>


void Create(int count)
{
    if(count>0)
    {
        pid_t n1=fork();
        if(n1<0) 
        {
            printf("fork error no child created");
        }
        else if(n1==0)
        {
            printf("from child process %d \n",count);
        }
        else if(n1>0)
        {
            int status;
            // wait(&status);
            printf("from parent process %d \n",count);
        }
    }
}

void CreateRec(int count)
{
    if(count>0)
    {
        pid_t n1=fork();
        if(n1<0) 
        {
            printf("fork error no child created");
        }
        else if(n1==0)
        {
            printf("from child process %d \n",count);
            CreateRec(--count);
            exit(1);
        }
        else if(n1>0)
        {
            
            int status;
            // wait(&status);
            printf("from parent process %d \n",count);
        }
    }
}

int main()
{
    pid_t n1,n2,n3;
    int x=0;
    int option;
    printf("Options:\n1. single process\n2.two processes\n3.Order of execution\n4.recursive\n5.exec\n6.Normal memory\n7.Shared Memory\n");
    scanf("%d",&option);
    if(option==1)
    {
        for(int i=0;i<2000000000;i++);
        printf("2 billion counted");
    }
    else if(option==2)
    {
        n1=fork();
        if(n1==0)
        {
            for(int i=0;i<2000000000;i++);
            printf("2 billion count by child\n");
            
        }
        if(n1>0)
        {
            for(int i=0;i<2000000000;i++);
            printf("2 billion count by parent\n");
            exit(1);
        }
    }
    else if(option==3)
    {
        Create(1);
        Create(3);
        Create(2);

    }
    else if(option==4)
    {
        CreateRec(3);
    }
    else if(option==5)
    {
       n2=fork();
       int x=0;
        if (n2 == 0) 
        {
        execl("./add","add","5", "10", NULL);
        perror("exec failed"); 
        } 
        else 
        {  
            printf("Parent process continuing\n"); 
        }
    }
    else if(option==6)
    {
        int x=0;
        pid_t n1=fork();
        if(n1<0) 
        {
            printf("fork error no child created");
        }
        else if(n1==0)
        {
            int status;
            printf("from child process x is %d \n",++x);
            exit(1);
        }
        else if(n1>0)
        {
            printf("from parent process x is %d \n",++x);
            
        }

    }
    else if(option==7)
    {
        int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);  
        if (shmid == -1) {
            perror("shmget failed");
            exit(1);
        }

        int *x = (int *)shmat(shmid, NULL, 0);  
        if (x == (void *)-1) {
            perror("shmat failed");
            exit(1);
        }

        *x = 0;  

        pid_t pid = fork(),pid2;
        if (pid == 0) 
        {  
            (*x)++;  
            printf("1st incremented x: %d\n", *x);
            // shmdt(x);  
            // exit(0);

        } 
        else if (pid > 0) 
        { 
            // wait(NULL);  
            (*x)++;
            printf("2nd incremented x: %d\n", *x);
            // shmdt(x);  
            // shmctl(shmid, IPC_RMID, NULL);  
        }
        pid2=fork();
        if(pid2==0)
        {
            
            ((*x)++);
            printf("3rd increamented x: %d\n",*x);
        }
        if(pid2>0)
        {
            ((*x)--);
            printf("4th increamented x: %d\n",*x);
        }
        pid2=fork();
        if(pid2==0)
        {
            
            ((*x)++);
            printf("3rd increamented x: %d\n",*x);
        }
        if(pid2>0)
        {
            ((*x)--);
            printf("4th increamented x: %d\n",*x);
        }pid2=fork();
        if(pid2==0)
        {
            
            ((*x)++);
            printf("3rd increamented x: %d\n",*x);
        }
        if(pid2>0)
        {
            ((*x)--);
            printf("4th increamented x: %d\n",*x);
        }
        pid2=fork();
        if(pid2==0)
        {
            
            ((*x)++);
            printf("3rd increamented x: %d\n",*x);
        }
        if(pid2>0)
        {
            ((*x)--);
            printf("4th increamented x: %d\n",*x);
        }
        
        
    }

    return 1;
}