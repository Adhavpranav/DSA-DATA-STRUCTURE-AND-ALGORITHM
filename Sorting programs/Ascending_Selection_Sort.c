#include<stdio.h>

void accept(int array[],int limit)
{
    printf("\nENETR ELEMENTS OF ARRAY:");
    for(int i=0;i<limit;i++)
    scanf("%d",&array[i]);
}

void display(int array[],int limit)
{
    printf("\nSORTED ARRAY:");
    for(int i=0;i<limit;i++)
    printf("\t%d",array[i]);
}

void selection(int array[],int limit)
{
    int i,j,min,index;
    for(i=0;i<limit-1;i++)  
    {
        min=array[i];
        index=i;
        for(j=i+1;j<limit;j++)
        {
            if(array[j]<min)
            {
                min=array[j];
                index=j;
            }
        }
        array[index]=array[i];
        array[i]=min;
    }
}

int main()
{
    int array[100],limit;
    printf("\nENTER LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    selection(array,limit);
    display(array,limit);
}
