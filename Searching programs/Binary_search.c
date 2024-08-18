#include<stdio.h>
void accept(int array[],int limit)
{
    printf("\nENTER ELEMENTS OF AN ARRAY:");
    for(int i=0;i<limit;i++)
    scanf("%d",&array[i]);
}

int binary_search(int array[],int limit,int key)
{
    int top,mid,bottom;
    top=0;
    bottom=limit-1;
    while(top<=bottom)
    {
    mid=(top+bottom)/2;
    if(array[mid]==key)
    return mid;
    else if(array[mid]<key)
    top=mid+1;
    else
    bottom=mid-1;
    }
    return -1;
}

int main()
{
    int array[100],limit,key;
    printf("ENTER LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    printf("\nENTER NUMBER FOR SEARCH:");
    scanf("%d",&key);
    int result=binary_search(array,limit,key);
    if(result!=-1)
    printf("\nNUMBER IS FOUND AT %d POSITION",result);
    else
    printf("\nNUMBER IS NOT FOUND");
    return 0;
}
