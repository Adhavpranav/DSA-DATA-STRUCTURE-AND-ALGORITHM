#include<stdio.h>
#include<stdlib.h>
    struct node
    {
        int data;
        struct node * next; 
    };

    struct node *create(struct node *head)
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
            newnode->next=NULL;
                if(head==NULL)
                {
                    head=newnode;
                    temp=newnode;
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
        struct node *temp=head;
        printf("\nOUTPUT:");
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }

    int main()
    {
        struct node* head=NULL;
        head=create(head);
        display(head);
    }
