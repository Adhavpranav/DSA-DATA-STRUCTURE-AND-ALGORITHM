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
            head = temp = newnode;
            newnode->next = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            newnode->next = head;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    printf("\nSINGLY CIRCULAR LINKED LIST:");
    do
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    struct node *head = NULL;
    head = create(head);
    display(head);
}
