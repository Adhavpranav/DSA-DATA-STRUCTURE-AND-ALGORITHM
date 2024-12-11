#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,pow;
    struct node* next;
};

struct node*create(struct node*head)
{
    int limit,i;
    struct node* newnode,*temp;
    printf("\nENTER HOW MANY TERMS:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER COEF AND POWER:");
        scanf("%d%d",&newnode->coef,&newnode->pow);
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

void display(struct node* head)
{
    struct node* temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%dx^%d",temp->coef,temp->pow);
        if(temp->next!=NULL)
        printf("+");
    }
}

struct node*add(struct node*head1,struct node*head2)
{
    struct node*head=NULL;
    struct node*temp1=head1,*temp2=head2,*newnode,*temp=NULL;
    while(temp1!=NULL && temp2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
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
        if(temp1->pow>temp2->pow)
        {
            newnode->coef=temp1->coef;
            newnode->pow=temp1->pow;
            temp1=temp1->next;
        }
        else if(temp2->pow>temp1->pow)
        {
            newnode->coef=temp2->coef;
            newnode->pow=temp2->pow;
            temp2=temp2->next;
        }
        else
        {
            newnode->coef=temp1->coef+temp2->coef;
            newnode->pow=temp1->pow;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->coef=temp1->coef;
        newnode->pow=temp1->pow;
        temp->next=newnode;
        temp=newnode;
        temp1=temp1->next;
    }
     while(temp2!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->coef=temp2->coef;
        newnode->pow=temp2->pow;
        temp->next=newnode;
        temp2=temp2->next;
        temp=newnode;
    }
    return head;
}

int main()
{
    struct node*head1=NULL,*head2=NULL,*head=NULL;
    printf("\nENTER POLYNOMIAL FIRST:");
    head1=create(head1);
    printf("\nENTER POLYNOMIAL SECOND:");
    head2=create(head2);
    printf("\nADDITION OF POLYNOMIAL IS:");
    head=add(head1,head2);
    display(head);
    return 0;
}
