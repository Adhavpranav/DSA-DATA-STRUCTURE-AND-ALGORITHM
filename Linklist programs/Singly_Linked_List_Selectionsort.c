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

struct node* selectionsort(struct node*head)
{
    struct node*index,*i,*j;
    int min;
    for(i=head;i->next!=NULL && i != NULL;i=i->next)
    {
        min=i->data;
        index=i;
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(j->data<min)
            {
                min=j->data;
                index=j;
            }
        }
        index->data=i->data;
        i->data=min;
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
    head=selectionsort(head);
    display(head);
}
