#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct bucket{
    struct node *head;
    struct node *tail;
};

struct node{
    int data;
    struct node *next;
};

void insertList(struct bucket *bucket,int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(bucket->head==NULL)
    {
        bucket->head=newnode;
        bucket->tail=newnode;
        return;
    }
    bucket->tail->next=newnode;
    bucket->tail=bucket->tail->next;
    return;
}

void inBucket(int *arr,int n,struct bucket **buckets,int exp)
{
    int position;
    for(int i=0;i<n;i++)
    {
        position=(arr[i]/exp)%10;
        insertList(*(buckets+position),arr[i]);
    }
}

void outBucket(int *arr,int n,struct bucket **buckets)
{
    int count=0;
    for(int i=0;i<10;i++)
    {
        if(buckets[i]->head!=NULL)
        {
            struct node *temp=buckets[i]->head;
            while(temp!=NULL)
            {
                arr[count]=temp->data;
                count++;
                // printf("%d ",temp->data);
                temp=temp->next;
            }
        }
    }
    // printf("\n"); //this printf is for gap between each iteration like digit place wise
}

void purge(struct bucket **buckets)
{
    for(int i=0;i<10;i++)
    {
        if(buckets[i]->head!=NULL)
        {
            struct node *temp=buckets[i]->head;
            struct node *tempcurr;
            while(temp!=NULL)
            {
                tempcurr=temp;
                temp=temp->next;
                free(tempcurr);
            }
            buckets[i]->head=NULL;
            buckets[i]->tail=NULL;
        }
    }
}

int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) return NULL; 
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        // printf("%d ",arr[i]);
    }
    return arr;
}

int main()
{
    struct bucket *buckets[10];
    for(int i=0;i<10;i++)
    {   
        buckets[i]=(struct bucket*)malloc(sizeof(struct bucket));
        buckets[i]->head=NULL;
        buckets[i]->tail=NULL;
    }
    int n=2000000;
    int* arr = createArray(n);
    int exp=1;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    //this should not be three but the number of digits in the largest number in the array
    for(int i=0;i<3;i++)
    {
        // exp = pow(10,i);
        inBucket(arr,n,buckets,exp);
        outBucket(arr,n,buckets);
        purge(buckets);
        exp *=10;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) +  ((end.tv_nsec - start.tv_nsec) / 1.0e9);
    printf("Time: %.9f s\n", time_taken);
    return 0;
    // printf("\n");
}