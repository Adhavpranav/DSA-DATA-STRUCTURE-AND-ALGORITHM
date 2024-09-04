#define MAX 6
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int a[MAX];
    int front,rear;
}*q;

int isfull()
{
    if(q->rear==MAX-1)
    return 1;
    else
    return 0;
}

int isempty()
{
    if(q->front==-1)
    return 1;
    else
    return 0;
}

void initq()
{
    q = (struct queue*) malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
}

void insert(int num)
{
    if(isfull())
    {
        printf("\nQUEUE IS OVERFLOW");
    }
    else
    {
        if(q->front==-1)
        {
            q->front=0;
        }
        q->rear=q->rear+1;
        q->a[q->rear]=num;
        printf("\nINSERT SUCCESSFULLY");
    }
}

void delete()
{
    int val;
    if(isempty())
    {
        printf("\nQUEUE IS UNDERFLOW");
    }
    else
    {
        val=q->a[q->front];
        q->front++;
        printf("\nDELETED VALUE %d",val);
    }
}

void display()
{
    int i;
    printf("\nELEMENTS OF QUEUE:");
    for(i=q->front;i<=q->rear;i++)
    {
        printf("\t%d",q->a[i]);
    }
}

int main()
{
    int ch,num;
    initq();
    do
    {
        printf("\n1:INSERT\n2:DISPLAY\n3:DELETE");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        printf("\nENTER NUMBER FOR INSERT:");
        scanf("%d",&num);
        insert(num);
        break;
        case 2:display();break;
        case 3:delete();break;
        default:printf("\nINVALID CHOICE");
            break;
        }
    }while(ch>=1&&ch<=3);
    free(q);
    return 0;
}
