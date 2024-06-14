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
void disp()
{
    int i;
    for (i = s.top; i >= 0; i--)
    {
        printf(" %c", s.a[i]);
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
    printf("\nREVERSE STRING:");
    disp();
}
