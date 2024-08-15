#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* create(struct node* head)
{
    struct node *newnode,*temp;
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
            temp=head=newnode;
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
    struct node* temp=head;
    printf("\nSINGLY CIRCULAR LINKED LIST:");
    do
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

struct node* deletebig(struct node* head)
{
    struct node* temp1,*temp;
    for(temp=head;temp->next!=head;temp=temp->next);
    temp1=head;
    head=temp1->next;
    free(temp1);
    temp->next=head;
    return head;
}

struct node* deletemid(struct node* head,int position)
{
    struct node* temp,*temp1;
    int i;
    for(i=0,temp=head;i<(position-1)&&temp->next!=head;temp=temp->next,i++);
    temp1=temp->next; 
    temp->next=temp1->next;
    free(temp1);
    return head;
}

struct node* deleteend(struct node* head)
{
    struct node*temp,*temp1;
    for(temp=head;temp->next->next!=head;temp=temp->next);
    temp1=temp->next;
    free(temp1);
    temp->next=head;
    return head;
}

int main()
{
    struct node* head=NULL;
    int choice,position;
    do{
    printf("\n1:CREATE\n2:DISPLAY\n3:DELETE BEGINNING\n4:DELETE END\n5:DELETE MIDDLE");
    printf("\nENTER CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:head=create(head);break;
        case 2:display(head);break;
        case 3:head=deletebig(head);break;
        case 4:head=deleteend(head);break;
        case 5:printf("\nENTER POSITION TO DELETE VALUE AT THAT POSITION:");
                scanf("%d",&position);
                head=deletemid(head,position);break;
        default:printf("\nINVALID CHOICE");break;
    }
    }while(choice>=1&&choice<=5);
}
