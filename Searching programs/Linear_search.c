#include<stdio.h>

int linear_Search(int array[],int limit,int *key)
{   
    int i;
    for(i=0;i<limit;i++)
    {
        if(array[i]==(*key))
        return ++i;
    }
        return -1;
}

void accept(int array[],int limit,int *key)
{
    printf("\nENTER ELEMENTS:");
    for(int i=0;i<limit;i++)
    scanf("%d",&array[i]);
    printf("\nENTER NUMBER TO FIND:");
    scanf("%d",key);
}

int main()
{
    int array[100],limit,key;
    printf("\nENTER LIMIT:");
    scanf("%d",&limit);
    accept(array,limit,&key);
    int result=linear_Search(array,limit,&key);
    if(result==-1)
    printf("\n%d IS NOT FOUND IN ARRAY.",key);
    else
    printf("\n%d IS FOUND AT %d POSITION IN ARRAY.",key,result);
}
