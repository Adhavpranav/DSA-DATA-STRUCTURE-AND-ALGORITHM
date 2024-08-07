#include<iostream>
using namespace std;

class Solution
{
    private:
    int array[100],limit;
    bool option;

    public:

    bool sorting_Option()
    {
        int choice;
        cout<<endl<<"1:ASCENDING ORDER SORT."<<endl<<"2:DESCENDING ORDER SORT."<<endl<<"ENTER YOUR CHOICE:";
        cin>>choice;
        if(choice!= 1 && choice!= 2)
        sorting_Option();
        else
        return choice==1?true:false;
    }

    void accept()
    {
        cout<<endl<<"ENTER ELEMENTS OF AN ARRAY:";
        for(int i=0;i<limit;i++)
        cin>>array[i];
    }

    void bubble_Sort()
    {
        bool option=sorting_Option();
        this->option=option;
        int pass,temp,i;
        for(pass=1;pass<limit;pass++)
        {
            for(i=0;i<limit-pass;i++)
            {
                    if(option==true)
                    {
                if(array[i]>array[i+1])
                {
                    swap(array[i],array[i+1]);
                }
                    }
                    else
                    {
                        if(array[i]<array[i+1])
                {
                    swap(array[i],array[i+1]);
                }
                    }
            }
        }
    }

    void display()
    {
        if(option==true)
        cout<<endl<<"ARRAY ELEMENTS IN ASCENDING ORDER:";
        else
        cout<<endl<<"ARRAY ELEMENTS IN DESCENDING ORDER:";
        for(int i=0;i<limit;i++)
        cout<<" "<<array[i];
    }

    Solution()
    {   
        cout<<endl<<"ENTER LIMIT:";
        cin>>limit;
        accept();
        bubble_Sort();
        display();
    }

};

int main()
{
    Solution ob;
}
