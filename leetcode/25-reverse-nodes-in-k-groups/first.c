#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

void insert(struct ListNode** head,int data){
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val=data;
    newnode->next=NULL;
    if(*head == NULL)
    {
        *head=newnode;
        return;
    }
    struct ListNode* temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}

void display(struct ListNode* head){
    if(head == NULL) return;
    struct ListNode *temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->val);
        if(temp->next!=NULL) printf("-->"); 
        temp=temp->next;
    }
    printf("\n");
}

void reverse(struct ListNode** head,int k){
    struct ListNode *curr=NULL,*next=*head,*nextnext;
    int count=0;
    while(next!=NULL && count<k)
    {
        nextnext=next->next;
        next->next=curr;
        curr=next;
        next=nextnext;
        count++;
    }
}

struct ListNode* check(struct ListNode* head,int k,struct ListNode** container){
    int count=1;
    struct ListNode* temp =head;
    while(temp->next!=NULL && count<k)
    {
        temp=temp->next;
        count++;
    }
    if(count==k) 
    {
        *container=temp->next;
        return temp;
    }
    else 
    {
        *container=head->next;
        return head;
    }
    
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    struct ListNode* temphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* final= temphead;
    temphead->next=head;
    struct ListNode *curr=head,*container=head,*tempFree;
    while(curr!=NULL)
    {
        curr=container;
        if(curr==NULL)
        {
            tempFree=final;
            final=final->next;
            free(tempFree);
            return final;
        }
        struct ListNode* returnValue = check(curr,k,&container);
        temphead->next=returnValue;
        if(curr == returnValue)
        {
            tempFree=final;
            final=final->next;
            free(tempFree);
            return final;
        }
        else 
        {
            
            reverse(&curr,k);
            temphead=curr;
        }

    }
    temphead=temphead->next;
    return temphead;
}


int main()
{
    int n=5;
    struct ListNode** array = (struct ListNode**)malloc(n*sizeof(struct ListNode*));
    for(int i=0;i<n;i++)
    {
        array[i]=(struct ListNode*)malloc(5*sizeof(struct ListNode));
    }

    struct ListNode* head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);


    display(reverseKGroup(head,3));

    return 0;
}