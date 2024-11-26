#include<stdio.h>

void accept(int array[],int limit)
{
    int i;
    printf("\nENTER ARRAY ELEMENTS:");
    for(i=0;i<limit;i++)
    scanf("%d",&array[i]);
}

void display(int array[],int limit)
{
    int i;
    printf("\nSORTED ARRAY:");
    for(i=0;i<limit;i++)
    printf("\t%d",array[i]);
}

int partition(int array[],int lb,int ub)
{
    int temp,pivot=array[lb];
    int start=lb,end=ub;
    while(start<end)
    {
        while(array[start]<=pivot)
        {
            start++;
        }
        while(array[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            temp=array[start];
            array[start]=array[end];
            array[end]=temp;
        }
    }
    temp=array[lb];
    array[lb]=array[end];
    array[end]=temp;
    return end;
}

void quicksort(int array[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
    loc=partition(array,lb,ub);
    quicksort(array,lb,loc-1);
    quicksort(array,loc+1,ub);
    }
}

int main()
{
 int limit,array[100];
 printf("\nENTER A LIMIT:");
 scanf("%d",&limit);
 accept(array,limit);
 quicksort(array,0,limit-1);
 display(array,limit);   
}
