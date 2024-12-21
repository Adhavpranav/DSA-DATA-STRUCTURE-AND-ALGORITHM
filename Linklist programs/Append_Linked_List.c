#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node*create(struct node*head)
{
    if(head!=NULL)
    {
        printf("\nLIST ALREADY EXITS.!");
        return head;
    }
    struct node*newnode,*temp;
    int limit,i;
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

struct node* append(struct node*head)
{
    if(head==NULL)
    {
        printf("\nORIGINAL LIST IS ALREADY EMPTY. WE CANNOT APPEND PLZ CREATE LIST FIRST.!");
        return head;
    }
    struct node*newnode,*temp;
    int num;
    printf("\nENTER A NUMBER TO APPEND:");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    temp=newnode;
    return head;
}

void display(struct node*head)
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY CANNOT DISPLAY.!");
        return;
    }
    struct node*temp;
    printf("\nLINKED LIST:");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}

int main()
{
    struct node*head=NULL;
    int choice;
    do
    {
        printf("\n1:CREATE\n2:DISPLAY\n3:APPEND NODE\n4:EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=create(head);
                   break;
            case 2:display(head);
                   break;
            case 3:head=append(head);
                   break;
            case 4:printf("\nEXITS SUCCESSFULY.!");
                    return 0;
            default:printf("\nINVALID CHOICE:");
        }
    }while(choice!=4);
}
