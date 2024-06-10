#include<stdio.h>
#define MAX 15
struct stack
{
   char a[MAX];
   int top;
}s;
void init()
{
    s.top=-1;
}
int isfull()
{
    if(s.top==MAX-1)
    return 1;
    else
    return 0;
}
int isempty()
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}
void push(char c)
{
    if(isfull())
    printf("\nSTACK IS FULL..!");
    else
    {
        s.top++;
        s.a[s.top]=c;
    }
}
void pop()
{
    char val;
    if(isempty())
    printf("\nSTACK IS EMPTY..!");
    else
    {
        val=s.a[s.top];
        s.top--;
    }
 }
 int main()
 {
    char s1[20];
    int i;
    printf("\nENTER INFIX EXPRESSION:");
    gets(s1);
    init();
    for(i=0;s1[i]!='\0';i++)
    {
        if(s1[i]=='(')
        push(s1[i]);
        if(s1[i]==')')
        pop();
    }
    if(isempty())
    printf("\nEXPRESSION IS FULLY PARENTHESIS.!");
    else
    printf("\nEXPRESSION IS NOT FULLY PARENTHESIS.!");
 }
