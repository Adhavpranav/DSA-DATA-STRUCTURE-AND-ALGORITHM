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

struct node*mergelist(struct node*head1,struct node*head2)
{
    struct node*head=NULL,*newnode;
    struct node*temp=NULL,*temp1,*temp2;
    temp1=head1;
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        if(temp1->data<=temp2->data)
        {
            newnode->data=temp1->data;
            temp1=temp1->next;
        }
        else
        {
            newnode->data=temp2->data;
            temp2=temp2->next;
        }
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
    while(temp1!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->data=temp1->data;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->data=temp2->data;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp2=temp2->next;
    }
    return head;
}

void display(struct node*head)
{
    struct node*temp;
    if(head==NULL)
    {
        printf("\tLIST IS EMPTY..!");
        return;
    }
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
}

struct node*sortlist(struct node*head)
{
    struct node*pass,*i;
    int temp;
    for(pass=head;pass!=NULL;pass=pass->next)
    {
        for(i=head;i->next!=NULL;i=i->next)
        {
            if(i->data>i->next->data)
            {
                temp=i->data;
                i->data=i->next->data;
                i->next->data=temp;
            }
        }
    }
    return head;
}

int main()
{
    struct node*head=NULL,*head1=NULL,*head2=NULL;
    printf("\nFOR FIRST LINKED LIST:");
    head1=create(head1);
 
    printf("\nFOR SECOND LINKED LIST:");
    head2=create(head2);

    head1=sortlist(head1);
    head2=sortlist(head2);

    printf("\nFIRST LIST SORTED ELEMENTS ARE:");
    display(head1);
    printf("\nSECOND LIST SORTED ELEMENTS ARE:");
    display(head2);

    head=mergelist(head1,head2);

    printf("\nMERGED LINKED LIST:");
    display(head);
    return 0;
}
