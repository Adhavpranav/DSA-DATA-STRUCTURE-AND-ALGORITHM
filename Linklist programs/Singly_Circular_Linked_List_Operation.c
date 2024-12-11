#include<stdio.h>
#include<stdlib.h>
#define memory (struct node*)malloc(sizeof(struct node*))

struct node
{
    int data;
    struct node*next;
};

struct node*create(struct node*head)
{
    struct node*newnode,*temp;
    int limit,i;
    printf("ENTER LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=memory;
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        newnode->next=head;
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

void display(struct node*head)
{
    struct node*temp;
    printf("\nSINGLY CIRCULAR LINKED LIST:");
    for(temp=head;temp->next!=head;temp=temp->next)
    {
        printf("\t%d",temp->data);
    }
    printf("\t%d",temp->data);
}

int input()
{
    int num;
    printf("\nENTER A NUMBER:");
    scanf("%d",&num);
    return num;
}

struct node*insertbig(struct node*head)
{
    struct node*newnode,*temp;
    newnode=memory;
    printf("\nENTER NUMBER:");
    scanf("%d",&newnode->data);
    for(temp=head;temp->next!=head;temp=temp->next);
    newnode->next=head;
    head=newnode;
    temp->next=head;                       
    return head;
}

struct node* insertend(struct node*head,int num)
{
    struct node*temp,*newnode;
    newnode=memory;
    newnode->data=num;
    for(temp=head;temp->next!=head;temp=temp->next);
    temp->next=newnode;
    newnode->next=head;
    return head;
}

struct node* insertmid(struct node*head)
{
    struct node*newnode,*temp,*temp1;
    int pos,i;
    newnode=memory;
    printf("\nENTER POSITION TO INSERT:");
    scanf("%d",&pos);
    printf("\nENTER VALUE:");
    scanf("%d",&newnode->data);
    for(temp=head,i=0;i<(pos-1)&&temp->next!=head;temp=temp->next,i++);
    temp1=temp->next;
    newnode->next=temp1->next;
    temp->next=newnode;
    return head;
}

struct node*deletebig(struct node*head)
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
        return head;
    }
    struct node*temp,*temp1;
    temp1=head;
    for(temp=head;temp->next!=head;temp=temp->next);
    head=head->next;
    temp->next=head;
    free(temp1);
    return head;
}

struct node*deleteend(struct node*head)
{
    struct node*temp,*temp1;
    for(temp=head;temp->next->next!=head;temp=temp->next);
     temp1=temp->next;
    free(temp1);
    temp->next=head;
    return head;
}

struct node*deletemid(struct node*head)
{
    int pos,i;
    struct node* temp,*temp1;
    printf("\nENTER POSOTION TO DELETE:");
    scanf("%d",&pos);
    for(temp=head,i=0;i<(pos-1)&&temp->next!=NULL;temp=temp->next,i++);
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return head;
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
