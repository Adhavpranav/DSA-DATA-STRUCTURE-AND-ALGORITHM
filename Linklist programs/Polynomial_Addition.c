
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,pow;
	struct node *next;
};
struct node *create(struct node *head)
{
	int n,i;
	struct node *newnode,*temp;
	printf("Enter how many terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter coef and power:");
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
void disp(struct node *head)
{
	struct node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%dx^%d\t",temp->coef,temp->pow);
		if(temp->next!=NULL)
		  printf("+");
	}
}
void add(struct node *head1,struct node *head2,struct node *head3)
{
	struct node *temp1=head1,*temp2=head2,*temp3,*newnode;
	while(temp1!=NULL&&temp2!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->next=NULL;
		if(temp1->pow>temp2->pow)
		{
			newnode->coef=temp1->coef;
			newnode->pow=temp1->pow;
			temp1=temp1->next;
		}
		else if(temp1->pow<temp2->pow)
		{
			newnode->coef=temp2->coef;
			newnode->pow=temp2->pow;
			temp2=temp2->next;
		}
		else
		{
			newnode->coef=temp1->coef+temp2->coef;
			newnode->pow=temp2->pow;//or newnode->pow=temp1->pow
			temp1=temp1->next;
			temp2=temp2->next;
		}
		if(head3==NULL)
		{
			head3=temp3=newnode;
		}
		temp3->next=newnode;
		temp3=newnode;
	}
	while(temp1!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->next=NULL;
		newnode->coef=temp1->coef;
		newnode->pow=temp1->pow;
		temp1=temp1->next;
		temp3->next=newnode;
		temp3=newnode;
	}
	while(temp2!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->next=NULL;
		newnode->coef=temp2->coef;
		newnode->pow=temp2->pow;
		temp2=temp2->next;
		temp3->next=newnode;
		temp3=newnode;
	}
	disp(head3);
}
int main()
{
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	printf("Polynomial 1:");
	head1=create(head1);
	printf("Polynomial 2:");
	head2=create(head2);
	printf("\nPolynimial 1:");
	disp(head1);
	printf("\nPolynimial 2:");
	disp(head2);
	printf("\nAddition of Polynomial:");
    
	add(head1,head2,head3);
}
