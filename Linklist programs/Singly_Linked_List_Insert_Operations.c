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
        {
            head = newnode;
            temp = newnode;
        }
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
    struct node *temp = head;
    printf("\nOUTPUT:");
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}

struct node *insertbig(struct node *head, int num)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertmid(struct node *head, int num, int position)
{
    int i;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    for (temp = head, i = 1; i < (position - 1) && temp->next != NULL; i++, temp = temp->next)
        ;
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node *insertend(struct node *head, int num)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    for (temp = head; temp->next != NULL; temp = temp->next)
        ;
    temp->next = newnode;
    return head;
}

int main()
{
    int choice, num, position;
    struct node *head = NULL;
    do
    {
        printf("\n1:Create\n2:Display\n3:Insert Begining\n4:Insert Mid\n5:Insert End\n6:Delete Begining");
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
            printf("\nENTER NUMBER TO INSERT BIGIN:");
            scanf("%d", &num);
            head = insertbig(head, num);
            break;
        case 4:
            printf("\nENTER NUMBER TO INSERT MID:");
            scanf("%d", &num);
            printf("\nENTER POSITION TO BE INSERT DATA:");
            scanf("%d", &position);
            head = insertmid(head, num, position);
            break;
        case 5:
            printf("\nENTER NUMBER TO INSERT END:");
            scanf("%d", &num);
            head = insertend(head, num);
            break;
        default:
            printf("\nINVALID CHOICE:");
            break;
        }
    } while (choice >= 1 && choice <= 5);
}
