#include <stdio.h>
#define MAX 5
struct stack
{
    int a[MAX];
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
void push(int num)
{
    if (isfull())
    {
        printf("\nSTACK IS FULL");
    }
    else
    {
        s.top++;
        s.a[s.top] = num;
        printf("\nPUSH SUCCESSFULLY");
    }
}
void pop()
{
    int val;
    if (isempty())
        printf("\nSTACK IS EMPTY");
    else
    {
        val = s.a[s.top];
        s.top--;
        printf("\nPOPED VALUE:%d", val);
    }
}
void disp()
{
    int i;
    for (i = s.top; i >= 0; i--)
    {
        printf("%d\n", s.a[i]);
    }
}
int main()
{
    int ch, num;
    init();
    do
    {
        printf("\n1.Push\n2.Pop\n3.Disp\n");
        printf("\nENTER CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nENTER NUMBER:");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
        default:
            printf("\nINVALID CHOICE");
            break;
        }
    } while (ch < 4&&ch>=1);
}
