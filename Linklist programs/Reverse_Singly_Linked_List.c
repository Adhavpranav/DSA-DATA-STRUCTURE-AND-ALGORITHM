#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*create(struct node*head)
{
    int i,limit;
    struct node*newnode,*temp;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node*head)
{
    struct node*temp;
    printf("\nLINKED LIST IS:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}

struct node*reverse(struct node*head)
{
    struct node*prev=NULL,*temp=head,*temp1;
    while(temp!=NULL)
    {
        temp1=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp1;
    }
    return prev;
}

int main()
{
    struct node*head=NULL;
    head=create(head);
    display(head);
    head=reverse(head);
    display(head);
}
