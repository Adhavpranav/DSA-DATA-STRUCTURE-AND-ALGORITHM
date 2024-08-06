#include<iostream>
#include<cstring>
using namespace std;

class solution
{
    private:
    int limit;
    string city[20];

    public:
    solution()
    {
        cout<<"ENTER A LIMIT:";
        cin>>limit;
        cout<<endl<<"ENTER CITY NAMES:";
        for(int i=0;i<limit;i++)
        cin>>city[i];
    }

    void selection_Sort()
    {
        int pass,index,i;
        string max;
        for(pass=0;pass<limit;pass++)
        {
            max=city[pass];
            index=pass;
            for(i=pass+1;i<limit;i++)
            {
                if(city[i]>max)
                {
                    max=city[i];
                    index=i;
                }
            }
            city[index]=city[pass];
            city[pass]=max;
        }
    }

    void display()
    {
        cout<<endl<<"SORTED CITY NAMES:";
        for(int i=0;i<limit;i++)
        cout<<" "<<city[i];
    }

};

int main()
{
    solution ob;
    ob.selection_Sort();
    ob.display();
}
