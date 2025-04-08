#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};


void Loop(struct ListNode* head,int position)
{
    int count=-1;
    struct ListNode* temp = head,*loopStart;

    while(temp!=NULL && temp->next!=NULL)
    {
        count++;
        if(count==position) loopStart=temp;
        temp=temp->next;
    }
    if(count+1==position) loopStart=temp;
    temp->next=loopStart;
    return;
}

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

int detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return -1; 
    }

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           
        fast = fast->next->next;     
        
        if (slow == fast) {
           
            int index = 1;
            struct ListNode* entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
                index++;
            }
            return index; 
        }
    }

    return -1;
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
    insert(&head,12);
    insert(&head,13);
    Loop(head, 5);
    printf("%d ",detectCycle(head));
    printf("\n");

    return 0;
}