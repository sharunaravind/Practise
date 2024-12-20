#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
void insertStart(struct node **head,int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    newnode->data=value;
    if(*head==NULL)
    {
        newnode->next=NULL;
        *head=newnode;
        return;
    }
    newnode->next=*head;
    *head=newnode;
    return;
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("empty listo");
        return;
    }
    struct node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
struct node* insertionSort(struct node **head)
{
    struct node *head2=NULL;
    if(*head==NULL)
    {
        printf("empty list");
        return head2;
    }
    struct node *temp,*temp2=head2;
    while((*head)!=NULL)
    {
        temp2=head2;
        temp = *head;
        *head=(*head)->next;
        if(temp2==NULL || temp2->data>temp->data)
        {
            temp->next=temp2;
            head2=temp;
        }
        else{
            while(temp2->next!=NULL && temp2->next->data<temp->data)
            {
                temp2=temp2->next;
            }
            temp->next=temp2->next;
            temp2->next=temp;
        }    
    }
    return head2;
}
void main()
{
    struct node *head = NULL;
    int ch=0;
    printf("Enter the numbers. Press (.) when you would like to stop\n");
    while(ch!='.')
    {
        ch=getc(stdin);
        printf("\t\t%d\n",ch);
        if(ch<=32)
        {
            continue;
        }
        else if(ch>=48 || ch<=57)
        {
            insertStart(&head,ch-48);
        }
        else if(ch=='.')
        {
            break;
        }

    }
    display(head);
    printf("\n");
    display(insertionSort(&head));
}