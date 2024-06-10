#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
struct stack
{
    int a[MAX];
    int top;
} s;
void init()
{
    s.top = -1;
}
int isfull()
{
    if (s.top == MAX - 1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
void push(int val)
{
    if (isfull())
        printf("\nstack is full");
    else
    {
        s.top++;
        s.a[s.top] = val;
    }
}
int pop()
{
    int val;
    if (isempty())
        printf("\nStack is empty");
    else
    {
        val = s.a[s.top];
        s.top--;
        return val;
    }
}
int main()
{
    char postfix[100], ch;
    int i, a, b, c, d, val1, val2, res;
    printf("\nEnter postfix string:");
    gets(postfix);
    printf("ENTER VALUES OF ABCD");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    init();
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isalpha(ch))
        {
            switch (ch)
            {
            case 'A':
                push(a);
                break;
            case 'B':
                push(b);
                break;
            case 'C':
                push(c);
                break;
            case 'D':
                push(d);
                break;
            }
        }
        else
        {
            val1 = pop();
            val2 = pop();
            switch (ch)
            {
            case '+':
                res = val2 + val1;
                break;
            case '-':
                res = val2 - val1;
                break;
            case '*':
                res = val2 * val1;
                break;
            case '/':
                res = val2 / val1;
                break;
            }
            push(res);
        }
    }
    printf("Result=%d", pop());
}