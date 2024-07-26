#include<iostream>
using namespace std;
class quickSort
{
    public:
int partition(int array[],int lb,int ub)
{
    int temp;
    int pivot=array[lb];
    int i=lb;
    int j=ub;

    while(i<j)
    {
        while(array[i]<=pivot && i<=ub-1)
        i++;
        while(array[j]>=pivot && j>=lb+1)
        j--;
        if(i<j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    temp=array[lb];
    array[lb]=array[j];
    array[j]=temp;
    return j;
}

void quicksort(int array[],int lb, int ub)
{
    int j;
    if(lb<ub)
    {
        j=partition(array,lb,ub);
        quicksort(array,lb,j-1);
        quicksort(array,j+1,ub);
    }
}
    };
int main()
{
    quickSort ob;
    int array[100],limit,i;
    cout<<"Enter limit:";
    cin>>limit;
    cout<<"Enter elements of array:";
    for(i=0;i<limit;i++)
    cin>>array[i];
    ob.quicksort(array,0,limit-1);
    cout<<"Sorted array:";
    for(i=0;i<limit;i++)
    cout<<" "<<array[i];
    return 0;
}
