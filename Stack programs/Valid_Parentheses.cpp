#include<iostream>
#include<string.h>
using namespace std;
#define MAX 20
class Solution
{
    public:
    char user_String[MAX],Array[MAX];
    int top,i=0;
    
    void init()
    {
        top=-1;
    }

    void accept()
    {
        cout<<"Enter a string:";
        cin>>user_String;
    }

    void pass()
    {
        for(i=0;i<strlen(user_String);i++)
        push(user_String[i]);
    } 

    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }

    bool isFull()
    {
        if(top==MAX-1)
        return true;
        else
        return false;
    }
    
    void pop()
    {
        if(isEmpty())
        cout<<"Stack is empty"<<endl;
        else
        {
            top--;
        }
    }

    bool open_Paranthesis(char c)
    {
            if (c == '{' || c == '(' || c == '[')
            return true;
            else
            return false;
    }

    bool close_Paranthesis(char c)
    {
            if (c == '}' || c == ')' || c == ']')
            return true;
            else
            return false;
    }

    bool matching_Parenthesis(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    void push(char c)
    {
        if(isFull())
        cout<<"Stack is full"<<endl;
        else
        {
            if(open_Paranthesis(c))
            {
                top++;
                Array[top]=c;
            }
            else if(close_Paranthesis(c))
            {
                if (!isEmpty() && matching_Parenthesis(Array[top], c))
                pop();
                else
                {
                cout<<"String does not have valid parentheses";
                exit(0);
                }
            }
        }
    }
};
int main()
{
    Solution ob;
    ob.init();
    ob.accept();   
    ob.pass();  
    if(ob.isEmpty())
    cout<<"String have valid parentheses";
    else
    cout<<"String does not have valid parentheses";
}
