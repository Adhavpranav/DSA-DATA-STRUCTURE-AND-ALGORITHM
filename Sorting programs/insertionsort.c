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

void insertionsort(int array[],int limit)
{
    int temp,i,j;
    for(i=1;i<limit;i++)
    {
        temp=array[i];
        j=i-1;
        while(j>=0 && array[j]>temp)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
}

int main()
{
    int limit,array[100];
    printf("ENTER LIMIT OF ARRAY:");
    scanf("%d",&limit);
    accept(array,limit);
    insertionsort(array,limit);
    display(array,limit);
    return 0;
}
