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
    int i,limit;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER A VALUE:");
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
    struct node*temp=head;
    printf("\nLINKED LIST:");
    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
}

int input()
{
    int num;
    printf("\nENTER A NUMBER:");
    scanf("%d",&num);
    return num;
}

int search(struct node*head,int num)
{
    struct node*temp=head;
    int index=0;
    while(temp!=NULL)
    {
        index++;
        if(temp->data==num)
        return index;
        temp=temp->next;
    }
    return -1;
}

struct node*insert_begining(struct node*head,int num)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));  
    newnode->data=num; 
    newnode->next=head;
    head=newnode;
    return head;
}

struct node*insert_middle(struct node*head,int num)
{
    struct node*temp,*temp1,*newnode;
    int pos,i;
    printf("\nENTER POSITION:");
    scanf("%d",&pos);
    if(pos<0)
    {
        printf("\nINVALID POSITION");
        return head;
    }
    if(pos==0)
    {
        head=insert_begining(head,num);
    }
    else
    {
    for(temp=head,i=0;temp->next!=NULL && i<(pos-1);temp=temp->next,i++);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    temp1=temp->next;
    newnode->next=temp1;
    temp->next=newnode;
    return head;
    }
}

struct node*insert_end(struct node*head,int num)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
        return head;
    }
    else
    {
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=newnode;
    newnode->next=NULL;
    return head;
    }
}

struct node*delete_begining(struct node*head)
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
        return head;
    }
    struct node*temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct node*delete_middle(struct node*head)
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
        return head;
    }
    int pos,i;
    struct node*temp,*temp1;
    printf("\nENTER POSITION:");
    scanf("%d",&pos);
    for(temp=head,i=0;temp->next!=NULL &&i<(pos-1);temp=temp->next,i++);
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return head;
}

struct node*delete_end(struct node*head)
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
        return head;
    }
    struct node*temp,*temp1;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp1=temp->next;
    free(temp1);
    temp->next=NULL;
    return head;
}

struct node*sort(struct node*head)
{
    struct node*pass,*i;
    int temp;
    for(pass=head;pass->next!=NULL;pass=pass->next)
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

struct node*reverse(struct node*head)
{
    struct node* prev=NULL,*temp,*temp1;
    temp=head;
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
    struct node*head=NULL,*head1=NULL,*head2=NULL;
    int choice,result;
    do
    {
        printf("\n1:CREATE\n2:DISPLAY\n3:SEARCH\n4:INSERT_BEGINING\n5:INSERT_MIDDLE\n6:INSERT_END\n7:DELETE_BEGINING\n8:DELETE_MIDDLE\n9:DELETE_END\n10:SORT\n11:REVERSE\n12:EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:head=create(head);break;
        case 2:display(head);break;
        case 3:result=search(head,input());
                if(result==-1)
                printf("\nNUMBER IS NOT FOUND");
                else
                printf("\nNUMBER IS FOUND AT %d POSITION",result);
                break;
        case 4:head=insert_begining(head,input());break;
        case 5:head=insert_middle(head,input());break;
        case 6:head=insert_end(head,input());break;
        case 7:head=delete_begining(head);break;
        case 8:head=delete_middle(head);break;
        case 9:head=delete_end(head);break;
        case 10:head=sort(head);break;
        case 11:head=reverse(head);break;
        default:printf("\nINVALID CHOICE");
        }
    }while(choice!=12);
}
