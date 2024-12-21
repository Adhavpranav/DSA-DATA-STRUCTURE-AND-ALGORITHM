#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
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

int getsize(struct node*head)
{
    struct node*temp;
    int counter=0;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        return counter;
    }
}

struct node*split(struct node*head)
{
    struct node*temp,*head2=NULL;
    int i;
    int counter=getsize(head);
    if(counter==0)
    {
        printf("\nLIST IS EMPTY & CANNOT BE SPLITED.!");
        return NULL;
    }
    else
    {
        if(counter<=1)
        {
            printf("\nLIST IS SO SMALL CANNOT BE SPLITED.!");
            return NULL;
        }
        else
        {
            i=0;
            temp=head;
            int middle=counter/2;
            for(i=0;i<middle-1;i++)
            {
                temp=temp->next;
            }
            head2=temp->next;
            temp->next=NULL;
            return head2;
        }
    }
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
    struct node*head=NULL,*head2=NULL;
    
    printf("\nCREATE LIST:");
    head=create(head);

    printf("\nORIGINAL LIST:");
    display(head);

    head2=split(head);
    printf("\nAFTER SPLIT:");
    printf("\nFIRST LIST:");
    display(head);

    printf("\nSECOND LIST:");
    display(head2);

}
