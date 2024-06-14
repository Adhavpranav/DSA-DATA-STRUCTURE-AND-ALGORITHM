#include <stdio.h>
#define MAX 15
struct stack
{
    char a[MAX];
    int top;
} s;
void init()
{
    s.top = -1;
}
int isempty()
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (s.top == MAX - 1)
        return 1;
    else
        return 0;
}
void push(char c)
{
    if (isfull())
    {
        printf("\nSTACK IS FULL");
    }
    else
    {
        s.top++;
        s.a[s.top] = c;
    }
}
char pop()
{
    char val;
    if (isempty())
        printf("\nSTACK IS EMPTY");
    else
    {
        val = s.a[s.top];
        s.top--;
        return val;
    }
}
int main()
{
    char string[20];
    int i;
    printf("\nENTER A STRING:");
    gets(string);
    init();
    for (i = 0; string[i] != '\0'; i++)
    {
        push(string[i]);
    }
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != pop())
            break;
    }
    if (isempty())
        printf("\nSTRING IS PALINDROME");
    else
        printf("\nSTRING IS NOT PALINDROME");
}
