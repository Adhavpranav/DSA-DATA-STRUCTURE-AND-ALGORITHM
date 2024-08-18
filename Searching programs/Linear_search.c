#include<stdio.h>
int linear_search_count(int array[],int limit,int key)
{
    int count=0;
    for(int i=0;i<limit;i++)
    {
        if(array[i]==key)
        count++;
    }
    return count;
}

void accept(int array[],int limit)
{
    printf("\nENTER ELEMENTS OF AN ARRAY:");
    for(int i=0;i<limit;i++)
    scanf("%d",&array[i]);
}

void linear_search_Positions(int array[],int limit,int key)
{
    for(int i=0;i<limit;i++)
    {
    if(array[i]==key)
    printf("\t%d",i+1);
    }
}

int main()
{
    int limit,array[100],key;
    printf("\nENTER LIMIT OF ARRAY:");
    scanf("%d",&limit);
    accept(array,limit);
    printf("\nENTER NUMBER FOR SEARCH:");
    scanf("%d",&key);
    int count=linear_search_count(array,limit,key);
    if(count!=0)
    {
        printf("\nNUMBER IS FOUND.");
        printf("\nNUMBER OF OCCURENCES: %d",count);
        printf("\nPOSITIONS OF NUMBER WHERE IT IS FOUND:");
        linear_search_Positions(array,limit,key);   
    }
    else
    printf("\nNUMBER IS NOT FOUND.");
    return 0;
}
