#include<iostream>
using namespace std;

class solution
{
    private:
    int array[100],limit;
    
    public:
    solution()
    {
        cout<<"ENTER A LIMIT:";
        cin>>limit;
        cout<<endl<<"ENTER ELEMENTS OF AN ARRAY:";
        for(int i=0;i<limit;i++)
        cin>>array[i];
    }

    void selection_Sort()
    {
        int pass,max,index,i;
        for(pass=0;pass<limit;pass++)
        {
            max=array[pass];
            index=pass;
            for(i=pass+1;i<limit;i++)
            {
                if(array[i]>max)
                {
                    max=array[i];
                    index=i;
                }
            }
            array[index]=array[pass];
            array[pass]=max;
        }
    }

    void display()
    {
        cout<<endl<<"SORTED ARRAY ELEMENTS:";
        for(int i=0;i<limit;i++)
        cout<<" "<<array[i];
    }

};

int main()
{
    solution ob;
    ob.selection_Sort();
    ob.display();
}
