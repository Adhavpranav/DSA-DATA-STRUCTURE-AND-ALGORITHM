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

void merge(int array[],int left,int mid,int right)
{
   int i,j,k=0,temp[20];
   i=left;
   j=mid+1;
   while(i<=mid && j<=right)
   {
        if(array[i]<array[j])
        {
            temp[k++]=array[i++];
        }
        else
        {
            temp[k++]=array[j++];
        }
   }
   while(i<=mid)
   {
            temp[k++]=array[i++];
   }
   while(j<=right)
   {
            temp[k++]=array[j++];
   }
   for(i=left,k=0;i<=right;i++,k++)
   {
    array[i]=temp[k];
   }
}

void mergesort(int array[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergesort(array,left,mid);
        mergesort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}

int main()
{
    int array[100],limit,i;
    printf("\nENTER LIMIT:");
    scanf("%d",&limit);
    accept(array,limit);
    mergesort(array,0,limit-1);
    display(array,limit);
}
