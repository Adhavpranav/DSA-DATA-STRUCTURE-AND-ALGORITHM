#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* create(struct node*head)
{
    struct node*newnode,*temp;
    int limit,i;
    printf("\nENTER LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node* head)
{
    struct node* temp;
    printf("\nLINKEDLIST:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}

int count(struct node* head)
{
    struct node* temp;
    int i;
    for(i=0,temp=head;temp->next!=NULL;temp=temp->next,i++);
    return i;
}

void reverselinkedlist(struct node* head)
{
    int limit=count(head);
    int pass,i;
    struct node* temp;
    printf("\nREVERSE LINKED LIST:");
    for(pass=0;pass<=limit;pass++)
    {
        for(temp=head,i=0;temp->next!=NULL &&i<limit-pass;i++,temp=temp->next);
        printf("\t%d",temp->data);
    }
}

int main()
{
    struct node*head=NULL;
    head=create(head);
    display(head);
    reverselinkedlist(head);
    return 0;
}
