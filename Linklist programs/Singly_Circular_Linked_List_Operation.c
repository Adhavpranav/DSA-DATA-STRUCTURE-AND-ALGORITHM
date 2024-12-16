#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*create(struct node*head)
{
    struct node*newnode,*temp;
    int i,limit;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    if(limit<=0)
    {
        printf("\nINVALID LIMIT:");
        return head;
    }
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER A VALUE:");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;
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


int getsize(struct node*head)
{
    int count=0;
    struct node*temp=head;
    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);
    return count;
}

int validation_of_position(struct node*head,int pos)
{
    if(pos>getsize(head)||pos<0)
    {
    printf("\nPOSITION ARE OUT OF BOUND PLZ SELECT A VALID POSITION.!");
    return 0;
    }
    else
    return 1;
}

int validation_of_not_null(struct node*head)
{
    if(head==NULL)
    {
    printf("\nLINKED LIST IS EMPTY CANNOT PERFORM OPERATIONS PLZ CREATE LIST FIRST.!");
    return 0;
    }
    else
    return 1;
}

void display(struct node*head)
{
        struct node*temp=head;
        printf("\nLINKED LIST IS:");
        do
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }while(temp!=head);
}

int search_by_value(struct node*head,int num)
{
    struct node*temp;
    int index=0;
    temp=head;
    do
    {
        index++;
        if(temp->data==num)
        return index;
        temp=temp->next;
    }while(temp!=head);
    return -1;
}

struct node*insertbeg(struct node*head,int num)
{
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    for(temp=head;temp->next!=head;temp=temp->next);
    newnode->next=head;
    head=newnode;
    temp->next=head;
    return head;
}

struct node*insertlast(struct node*head,int num)
{
        struct node*temp,*newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        for(temp=head;temp->next!=head;temp=temp->next);
        temp->next=newnode;
        newnode->next=head;
        return head;
}

struct node*insertmid(struct node*head,int num,int pos)
{
    struct node*newnode,*temp,*temp1;
    int i;
    if(pos==0)
    {
        head=insertbeg(head,num);
        return head;
    }
    if(pos==getsize(head))
    {
        head=insertlast(head,num);
        return head;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    for(temp=head,i=0;i<(pos-1)&& temp->next!=head;temp=temp->next,i++);
    temp1=temp->next;
    newnode->next=temp1;
    temp->next=newnode;
    return head;
}

struct node*deletebeg(struct node*head)
{
        if(head->next==head)
         {
            free(head);
            return NULL;  
         }
        else
        {
            struct node*temp,*temp1;
            temp1=head;
            for(temp=head;temp->next!=head;temp=temp->next);
            head=head->next;
            free(temp1);
            temp->next=head;
            return head;
        }
}
        
struct node *deleteend(struct node *head)
{
        if(head->next==head)
        {
            head=deletebeg(head);
            return head;
        }
        struct node *temp,*temp1;
        for(temp=head;temp->next->next!=head;temp=temp->next);
        temp1=temp->next;
        free(temp1);
        temp->next=head;
        return head;
}

struct node*deletemid(struct node*head,int pos)
{
   int i;
    struct node*temp,*temp1;
    if(pos==0)
    {
        head=deletebeg(head);
        return head;
    }
        for(temp=head,i=0;temp->next!=head && i<(pos-1);temp=temp->next,i++);
        if(temp->next==head)
        {
            head=deleteend(head);
            return head;
        }
        else
        {
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        return head;
        }
}

struct node*deletebyvalue(struct node*head,int num)
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY UNABLE TO DELETE");
        return head;
    }
    else
    {
        struct node*temp,*temp1;
        if(head->data==num)
        {
            head=deletebeg(head);
            return head;
        }
        else
        {
            for(temp=head;temp->next!=head;temp=temp->next)
            {
                if(temp->next->data==num)
                {
                    temp1=temp->next;
                    temp->next=temp1->next;
                    free(temp1);
                    return head;
                }
            }
            printf("\nNUMBER IS NOT FOUND");
            return head;
        }
    }
}



int input()
{
    int num;
    printf("\nENTER A NUMBER:");
    scanf("%d",&num);
    return num;
}

int main()
{
    int choice,position,result;
    struct node*head=NULL;
    do
    {
        printf("\n1:CREATE\n2:DISPLAY\n3:SEARCH_BY_VALUE\n4:INSERT_BEGINING\n5:INSERT_MIDDLE\n6:INSERT_LAST\n7:DELETE_BEGINING\n8:DELETE_MIDDLE\n9:DELETE_END\n10:DELETE_BY_VALUE\n11:EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
           if(choice==1)
            {
                if(head==NULL)
                head=create(head);
                else
                printf("\nLIST ALREADY EXITS.!");
            }
            else if(validation_of_not_null(head))
            {
                switch(choice)
                {
            case 2: display(head);
                    break;
            case 3: result=search_by_value(head,input());
                    if(result==-1)
                    printf("\nNUMBER IS NOT FOUND");
                    else
                    printf("\nNUMBER IS FOUND AT POSITION %d",result);
                    break;
            case 4: head=insertbeg(head,input());
                    break;
            case 5: printf("\nENTER A POSITION TO INSERT A VALUE IN THAT PERTICULAR VALUE:");
                    scanf("%d",&position);
                        if(validation_of_position(head,position))
                        {
                            head=insertmid(head,input(),position);
                        }
                    break;
            case 6: head=insertlast(head,input());
                    break;
            case 7 :head=deletebeg(head);
                    break;
            case 8: printf("\nENTER POSITION TO DELETE THAT PERTICULAR VALUE:");
                    scanf("%d",&position);
                        if(validation_of_position(head,position))
                        {
                            head=deletemid(head,position);
                        }
                    break;  
            case 9: head=deleteend(head);
                    break;
            case 10:head=deletebyvalue(head,input());
                    break;
            case 11:printf("\nEXIT SUCC!");
                    return 0;
            default:printf("\nINVALID CHOICE");
                break;
            }
        }    
    } while(choice!=11);
    
}
