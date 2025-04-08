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
}
int main()
{
    int n=5;
    
    struct ListNode* head = NULL;
    insert(&head,5);
    insert(&head,6);
    insert(&head,7);
    insert(&head,8);
    insert(&head,9);

    display(head);
    printf("\n");

    return 0;
}