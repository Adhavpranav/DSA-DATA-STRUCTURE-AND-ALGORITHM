#include<stdio.h>

void display(int array[],int limit)
{
    int i;
    printf("\nSORTED ARRAY:");
    for(i=0;i<limit;i++)
    printf("\t%d",array[i]);
}

void accept(int array[],int limit)
{

    int i;
    printf("\nENTER ELEMENTS OF AN ARRAY:");
    for(i=0;i<limit;i++)
    scanf("%d",&array[i]);
}

void countsort(int array[],int limit,int max)
{
    int count[100]={0},b[100],i;
    for(i=0;i<limit;i++)
    {
        ++count[array[i]];
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=limit-1;i>=0;i--)
    {
        b[--count[array[i]]]=array[i];
    }
    for(i=0;i<limit;i++)
    array[i]=b[i];
}

int main()
{
    int array[100],limit,max,i;
    printf("\nENTER THE LIMIT: ");
    scanf("%d",&limit);
    accept(array,limit);
    max=array[0];
    for(i=1;i<limit;i++)
    if(array[i]>max)
    max=array[i];
    countsort(array,limit,max);
    display(array,limit);
}
