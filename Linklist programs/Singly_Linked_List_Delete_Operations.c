#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *newnode, *temp;
    int limit, i;
    printf("\nENTER LIMIT:");
    scanf("%d", &limit);
    for (i = 0; i < limit; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    printf("\nLINKED LIST:");
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}

struct node *delend(struct node *head)
{
    struct node *temp, *temp1;
    for (temp = head; temp->next->next != NULL; temp = temp->next)
        ;
    temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
    return head;
}

struct node *delmid(struct node *head, int pos)
{
    struct node *temp, *temp1;
    int i;
    for (temp = head, i = 1; i < (pos - 1) && temp->next != NULL; i++, temp = temp->next)
        ;
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return head;
}

struct node *deletebeg(struct node *head)
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main()
{
    struct node *head = NULL;
    int pos, choice;
    do
    {
        printf("\n1:CREATE LINKEDLIST\n2:DISPLAY\n3:DELETE BEGINING\n4:DELETE MIDDLE\n5:DELETE END");
        printf("\nENTER CHOICE:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = deletebeg(head);
            break;
        case 4:
            printf("\nENTER POSITION TO DELETE VALUE:");
            scanf("%d", &pos);
            head = delmid(head, pos);
            break;
        case 5:
            head = delend(head);
            break;
        default:
            printf("\nINVALID CHOICE");
        }
    } while (choice >= 1 && choice <= 5);
}
