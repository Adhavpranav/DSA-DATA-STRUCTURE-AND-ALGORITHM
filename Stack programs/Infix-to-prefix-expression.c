#define MAX 100
#include <ctype.h>
#include <string.h>
#include <stdio.h>
struct stack
{
    char a[MAX];
    int top;
} s;
void init()
{
    s.top = -1;
}
char peek()
{
    char val = s.a[s.top];
    return val;
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
void push(char ch)
{
    if (isfull())
        printf("\nSTACK IS FULL:");
    else
    {
        s.top++;
        s.a[s.top] = ch;
    }
}
char pop()
{
    char ch;
    if (isempty())
        printf("\nSTACK IS EMPTY");
    else
    {
        ch = s.a[s.top];
        s.top--;
        return ch;
    }
}
int precedence(char ch)
{
    if (ch == '(')
        return 0;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '$' || ch == '^')
        return 3;
}
int main()
{
    int i, k = 0;
    char infix[100], ch, prefix[100];
    printf("ENTER INFIX EXPRESSION:");
    gets(infix);
    init();
    strrev(infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (isalpha(ch))
            prefix[k++] = ch;
        else if (ch == '(')
            push(ch);

        else if (ch == ')')
        {
            while ((ch = pop()) != '(')
            {
                prefix[k++] = ch;
            }
        }

        else
        {
            while ((precedence(peek()) >= precedence(ch)) && !isempty())
            {
                prefix[k++] = pop();
            }
            push(ch);
        }
    }
    while (!isempty())
    {
        prefix[k++] = pop();
    }
    prefix[k] = '\0';

    printf("\nPREFIX EXPRESSION:");
    strrev(prefix);
    printf("%s", prefix);
}
