#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node*create(struct node*head)
{
    struct node*newnode,*temp;
    int i,limit;
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

struct node*bubblesort(struct node *head)
{
    struct node*pass,*i;
    int temp,flag=0;
    for(pass=head;pass!=NULL;pass=pass->next)
    {
        for(i=head;i->next!=NULL;i=i->next)
        {
            if(i->data>i->next->data)
            {
                temp=i->data;
                i->data=i->next->data;
                i->next->data=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
    return head;
}

void display(struct node*head)
{
    struct node*temp;
    printf("\nSINGLY LINKED LIST:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}
int main()
{
    struct node* head=NULL;
    head=create(head);
    display(head);
    head=bubblesort(head);
    display(head);
}
