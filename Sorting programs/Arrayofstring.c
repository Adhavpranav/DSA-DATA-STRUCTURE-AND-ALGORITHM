#include <stdio.h>
#include <string.h>
int main()
{
    char name[10][10], temp[10];
    int i, pass, n;
    printf("ENTER LIMIT:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("ENTER NAMES:");
        scanf("%s", name[i]);
    }
    printf("\nUNSORTED ARRAY NAMES:");
    for (i = 0; i < n; i++)
    {
        printf("\t%s", name[i]);
    }
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (strcmp(name[i], name[i + 1]) > 0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[i + 1]);
                strcpy(name[i + 1], temp);
            }
        }
    }
    printf("\nSORTED ARRAY NAMES:");
    for (i = 0; i < n; i++)
    {
        printf("\t%s", name[i]);
    }
}
