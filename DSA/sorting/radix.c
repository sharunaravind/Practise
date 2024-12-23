#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
                printf("%d ",temp->data);
                temp=temp->next;
            }
        }
    }
    printf("\n");
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

void main()
{
    struct bucket *buckets[10];
    for(int i=0;i<10;i++)
    {   
        buckets[i]=(struct bucket*)malloc(sizeof(struct bucket));
        buckets[i]->head=NULL;
        buckets[i]->tail=NULL;
    }
    int arr[]={12,43,54,401,43,1,3,94,16};
    int n=sizeof(arr)/sizeof(int);
    int exp;
    //this should not be three but the number of digits in the largest number in the array
    for(int i=0;i<3;i++)
    {
        exp=pow(10,i);
        inBucket(arr,n,buckets,exp);
        outBucket(arr,n,buckets);
        purge(buckets);
    }
    
    printf("\n");
}