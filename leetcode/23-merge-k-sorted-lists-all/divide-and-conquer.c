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

struct ListNode* merge(struct ListNode** head1,struct ListNode** head2){
    if(*head1==NULL) return *head2;
    else if(*head2==NULL) return *head1;
    struct ListNode *temp1=*head1,*temp2=*head2,*top,*newHead;
    if(temp1->val > temp2->val){
        top=temp2;
        temp2=temp2->next;
    }
    else{
        top=temp1;
        temp1=temp1->next;
    }
    newHead=top;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->val<temp2->val){
            top->next=temp1;
            temp1=temp1->next;
        }
        else {
            top->next=temp2;
            temp2=temp2->next;
        }
        top=top->next;
    }
    if(temp1==NULL) top->next=temp2;
    else top->next=temp1;
    return newHead;
}

void helper(struct ListNode** arr,int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        helper(arr,start,mid);
        helper(arr,mid+1,end);

        struct ListNode* temp = merge(&arr[start],&arr[end]);
        arr[start]=temp;
        arr[end]=temp;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int n) {
    helper(lists,0,n-1);
    return lists[0];
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
    insert(&head,5);
    insert(&head,6);
    insert(&head,7);
    insert(&head,8);
    insert(&head,9);

    struct ListNode* head1 = NULL;
    insert(&head1,1);
    insert(&head1,2);
    insert(&head1,3);
    insert(&head1,4);
    insert(&head1,5);

    struct ListNode* head2 = NULL;
    insert(&head2,10);
    insert(&head2,20);
    insert(&head2,30);
    insert(&head2,40);
    insert(&head2,50);

    struct ListNode* head3 = NULL;
    insert(&head3,15);
    insert(&head3,25);
    insert(&head3,35);
    insert(&head3,45);
    insert(&head3,55);

    struct ListNode* head4 = NULL;
    insert(&head4,3);
    insert(&head4,6);
    insert(&head4,9);
    insert(&head4,12);
    insert(&head4,15);

    struct ListNode* head5 = NULL;
    insert(&head5,100);
    insert(&head5,200);
    insert(&head5,300);
    insert(&head5,400);
    insert(&head5,500);

    // display(merge(&head5,&head1));
    array[0]=head;
    array[1]=head1;
    array[2]=head2;
    array[3]=head3;
    array[4]=head5;

    display(mergeKLists(array,n));

    return 0;
}