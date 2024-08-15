#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* create(struct node *head)
{
    struct node* newnode,*temp;
    int limit,i;
    printf("\nENTER LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;
            newnode->next=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            newnode->next=head;
        }
    }
    return head;
}

void display(struct node* head)
{
    struct node* temp;
    temp=head;
    printf("\nSINGLY CIRCULAR LINKEDLIST:");
    do
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

struct node* insertbig(struct node* head,int num)
{
    struct node* newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    for(temp=head;temp->next!=head;temp=temp->next);
    newnode->next=head;
    head=newnode;
    temp->next=head;
    return head;
}

int insertvalue()
{
    int value;
    printf("\nENTER VALUE TO INSERT:");
    scanf("%d",&value);
    return value;
}

struct node* insertmid(struct node* head,int position,int value)
{
    struct node* newnode,*temp;
    int i;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    for(temp=head,i=0;i<(position-1)&&temp->next!=head;temp=temp->next,i++);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node* insertend(struct node* head,int value)
{
    struct node* newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    for(temp=head;temp->next!=head;temp=temp->next);
    temp->next=newnode;
    temp=newnode;
    newnode->next=head;
    return head;
}

int main()
{
    struct node * head=NULL;
    int choice,position;
    do{
    printf("\n1:CREATE\n2:DISPLAY\n3:INSERT BEGINING:\n4:INSERT MIDDLE\n5:INSERT END");
    printf("\nENTER CHOICE:");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=create(head);break;
            case 2:display(head);break;
            case 3:head=insertbig(head,insertvalue());break;
            case 4: printf("\nENTER POSITION TO INSERT VALUE:");
                    scanf("%d",&position);
                    head=insertmid(head,position,insertvalue());
                    break;
            case 5:head=insertend(head,insertvalue());break;
            default:printf("\nINVALID CHOICE");
        }
    }while(choice>=1&&choice<=5);
}
