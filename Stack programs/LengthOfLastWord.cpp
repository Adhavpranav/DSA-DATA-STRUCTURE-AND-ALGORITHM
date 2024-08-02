#include <iostream>
#include<cstring>
#include <cctype>
#define MAX 20
using namespace std;

class Solution
{
    public:
    char last_Word[MAX];
    int top;

    Solution()
    {
        top=-1;
    }

    bool isempty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }

    bool isfull()
    {
        if(top==MAX-1)
        return true;
        else
        return false;
    }

    void pop()
    {
        if(isempty())
        cout<<"STACK IS EMPTY";
        else
        {
            top--;
        }
    }

    void push(char ch)
    {
        if(isfull())
        cout<<"STACK IS FULL";
        else
        {
        top++;
        last_Word[top]=ch;
        }
    }

    int lengthOfLastWord(string user_String)
    {
        int string_Length,counter=0;
        string_Length=user_String.length();
        for(int i=string_Length-1;i>=0;i--)
        {
            if(isspace(user_String[i]) && !isempty())
           {
                while(!isempty())
                {
                    counter++;
                    pop();
                }
                return counter; 
           }
            else if(!isspace(user_String[i]) && isalnum(user_String[i]))
            {
                push(user_String[i]);
            }   
        }
            while (!isempty())
            {
                counter++;
                pop();
            }
            return counter;
    }
};
int main()
{
    Solution ob;
    string user_String;
    cout<<"ENTER A STRING:";
    getline(cin, user_String);
    int length=ob.lengthOfLastWord(user_String);
    cout<<"LENGTH OF LAST WORD: "<<length;
}
