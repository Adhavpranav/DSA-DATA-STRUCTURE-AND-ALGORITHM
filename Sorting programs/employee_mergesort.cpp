#include<iostream>
#include<cstring>
using namespace std;
class emp
{
    public://pranav
    int eno,sal;
    char ename[20];
    void merge(emp ob [],int left,int mid,int right)
    {
        int i,j,k;
        int n1=mid-left+1;
        int n2=right-mid;
        emp ob1[n1];
        emp ob2[n2];
        for(i=0;i<n1;i++)
        ob1[i]=ob[left+i];
        for(j=0;j<n2;j++)
        ob2[j]=ob[mid+j+1];
        i=0;j=0,k=left;
        while(i<n1&&j<n2)
        {
            if(strcmp(ob1[i].ename,ob2[j].ename)<0)
            ob[k++]=ob1[i++];
            else
            ob[k++]=ob2[j++];
        }
        while(i<n1)
        ob[k++]=ob1[i++];
        while(j<n2)
        ob[k++]=ob2[j++];
    }

    void mergesort(emp ob [],int left ,int right)
   {
        int mid;
        if(left<right)
        {
            mid=(left+right)/2;
            mergesort(ob,left,mid);
            mergesort(ob,mid+1,right);
            merge(ob,left,mid,right);
        }
   }
};
int main()
{
    emp ob[100];
    FILE *f1;
    int i=0,n;
    f1=fopen("nothing.txt","r");
    if(f1==NULL)
    {
        cout<<"FILE IS NOT FOUND";
        exit(0);
    }
    while(!feof(f1))
    {
        fscanf(f1,"%d\t%s\t%d",&ob[i].eno,&ob[i].ename,&ob[i].sal);
        i++;
    }
    int limit=i;
    ob->mergesort(ob,0,limit-1);
    cout<<"SORTING RECORDS BY EMP NAMES:";
    for(i=0;i<limit;i++)
    cout<<endl<<ob[i].eno<<" "<<ob[i].ename<<" "<<ob[i].sal;
    return 0;
}
