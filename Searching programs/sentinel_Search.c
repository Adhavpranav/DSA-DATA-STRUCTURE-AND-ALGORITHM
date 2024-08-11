#include<stdio.h>

void accept(int array[],int limit,int *key)
{
    printf("\nENTER ELEMENTS OF AN ARRAY:");
    for(int i=0;i<limit;i++)
    scanf("%d",&array[i]);
    printf("\nENTER NUMBER FOR SEARCH:");
    scanf("%d",key);
}

int sentinal_Search(int array[],int limit,int key)
{
    array[limit]=key;
    int i=0;
    while(array[i]!=key)
    {
        i++;
    }
    return i==limit?-1:i;
}

int main()
{
    int array[100],limit,key;
    printf("\nENTER LIMIT:");
    scanf("%d",&limit);
    accept(array,limit,&key);
    int result=sentinal_Search(array,limit,key);
    if(result==-1)
    printf("\n%d IS NOT FOUND IN THE ARRAY.",key);
    else
    printf("\n%d IS FOUND AT %d POSITION IN THE ARRAY.",key,++result);
}
