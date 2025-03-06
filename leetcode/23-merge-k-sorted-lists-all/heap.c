#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct heapNode{
    struct ListNode *start;
    int first;
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

void heapify(struct heapNode* array,int n,int i){
    int leftchild = (2*i)+1;
    int rightchild =(2*i)+2;
    int min=i;
    struct heapNode temp;
        if(rightchild<n && array[min].first>array[rightchild].first) min=rightchild;
        if(leftchild<n && array[min].first>array[leftchild].first) min=leftchild;

        if(min!=i)
        {
            temp=array[i];
            array[i]=array[min];
            array[min]= temp;
            heapify(array,n,min);
        }
}

struct ListNode* mergeKLists(struct ListNode** lists, int n) {
    struct heapNode heap[n];
    struct ListNode* final = NULL;
    for(int i=0;i<n;i++)
    {
        heap[i].start=lists[i];
        if(heap[i].start != NULL) heap[i].first=heap[i].start->val;
        else if(heap[i].start == NULL) heap[i].first = INT_MAX;
    }
    for(int i=((2*n)-1);i>=0;i--)
    {
        heapify(heap,n,i);
    }
    while(heap[0].first!=INT_MAX)
    {
        insert(&final,heap[0].first);
        if(heap[0].start->next==NULL) heap[0].first=INT_MAX;
        else{
            heap[0].start=heap[0].start->next;
            heap[0].first=heap[0].start->val;
        }
        heapify(heap,n,0);
    }
    return final;
}

int main()
{
    int n=10;
    struct ListNode** array = (struct ListNode**)malloc(n*sizeof(struct ListNode*));
    for(int i=0;i<n;i++)
    {
        array[i]=(struct ListNode*)malloc(5*sizeof(struct ListNode));
    }
    struct ListNode* head0 = NULL;
    insert(&head0, 5);
    insert(&head0, 15);
    insert(&head0, 25);
    insert(&head0, 35);

    struct ListNode* head1 = NULL;
    insert(&head1, 1);
    insert(&head1, 3);
    insert(&head1, 5);
    insert(&head1, 10);
    insert(&head1, 15);

    struct ListNode* head2 = NULL;
    insert(&head2, 12);
    insert(&head2, 20);
    insert(&head2, 30);
    insert(&head2, 50);
    insert(&head2, 70);
    insert(&head2, 90);

    struct ListNode* head3 = NULL;
    insert(&head3, 0);
    insert(&head3, 4);
    insert(&head3, 8);
    insert(&head3, 16);
    insert(&head3, 32);
    insert(&head3, 64);
    insert(&head3, 128);

    struct ListNode* head4 = NULL;
    insert(&head4, 2);
    insert(&head4, 4);
    insert(&head4, 6);
    insert(&head4, 8);
    insert(&head4, 10);
    insert(&head4, 20);
    insert(&head4, 40);

    struct ListNode* head5 = NULL;
    insert(&head5, 3);
    insert(&head5, 6);
    insert(&head5, 9);
    insert(&head5, 12);
    insert(&head5, 15);
    insert(&head5, 18);
    insert(&head5, 21);
    insert(&head5, 24);

    struct ListNode* head6 = NULL;
    insert(&head6, 7);
    insert(&head6, 14);
    insert(&head6, 21);
    insert(&head6, 28);
    insert(&head6, 35);

    struct ListNode* head7 = NULL;
    insert(&head7, 11);
    insert(&head7, 22);
    insert(&head7, 33);
    insert(&head7, 44);
    insert(&head7, 55);
    insert(&head7, 66);
    insert(&head7, 77);
    insert(&head7, 88);

    struct ListNode* head8 = NULL;
    insert(&head8, 9);
    insert(&head8, 18);
    insert(&head8, 27);
    insert(&head8, 36);
    insert(&head8, 45);

    struct ListNode* head9 = NULL;
    insert(&head9, 13);
    insert(&head9, 26);
    insert(&head9, 39);
    insert(&head9, 52);
    insert(&head9, 65);
    insert(&head9, 78);
    insert(&head9, 91);
    insert(&head9, 104);
    insert(&head9, 117);

    array[0] = head0;
    array[1] = head1;
    array[2] = head2;
    array[3] = head3;
    array[4] = head4;
    array[5] = head5;
    array[6] = head6;
    array[7] = head7;
    array[8] = head8;
    array[9] = head9;

    display(mergeKLists(array,n));

    return 0;
}