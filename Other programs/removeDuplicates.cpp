#include<iostream>
using namespace std;

class Solution
{
    private:
    int limit,sorted_Array[100];
    public:
    void bubble_Sort()
    {
        int pass,i,temp;
        for(pass=1;pass<limit;pass++)
        {
            for(i=0;i<limit-pass;i++)
            {
                if(sorted_Array[i]>sorted_Array[i+1])
                {
                    temp=sorted_Array[i];
                    sorted_Array[i]=sorted_Array[i+1];
                    sorted_Array[i+1]=temp;
                }
            }
        }
    }

    void display()
    {
        for(int i=0;i<limit;i++)
        {
            cout<<sorted_Array[i]<<" ";
        }
    }

    void removeDuplicates()
    {
        for(int i=0;i<limit;i++)
        {
           for(int j=i+1;j<limit;j++)
           {
            if(sorted_Array[i]==sorted_Array[j])
            {
                for(int k=j;k<limit-1;k++)
                {
                    sorted_Array[k]=sorted_Array[k+1];
                }
                limit--;
                j--;
            }
           }
        }
    }

    Solution()
    {
        cout<<"ENTER ARRAY LIMIT:";
        cin>>limit;
        cout<<"ENTER ARRAY ELEMENTS:";
        for(int i=0;i<limit;i++)
        {
            cin>>sorted_Array[i];
        }
        bubble_Sort();
        removeDuplicates();
        display();
    }
};

int main()
{
    Solution ob;
    return 0;
}
