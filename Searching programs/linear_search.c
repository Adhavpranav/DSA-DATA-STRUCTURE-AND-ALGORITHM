#include <stdio.h>
int main()
{
    int limit, array[100], i, num;
    printf("ENTER LIMIT: ");
    scanf("%d", &limit);
    printf("\nENTER ARRAY ELEMENTS: ");
    for (i = 0; i < limit; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\nENTER NUMBER FOR SEARCH: ");
    scanf("%d", &num);
    for (i = 0; i < limit; i++)
    {
        if (array[i] == num)
        {
            break;
        }
    }
    if (i == limit)
    {
        printf("\nNUMBER IS NOT FOUND\n");
    }
    else
    {
        printf("\nNUMBER IS FOUND\n");
    }
    return 0;
}
