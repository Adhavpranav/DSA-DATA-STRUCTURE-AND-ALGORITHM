#include <stdio.h>
int main()
{
    int array[100], pass, i, t, n;
    printf("ENTER LIMIT:");
    scanf("%d", &n);
    printf("\nENTER ELEMENTS OF AN ARRAY:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\nELEMENTS OF AN UNSORTED ARRAY:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", array[i]);
    }
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (array[i] > array[i + 1])
            {
                t = array[i];
                array[i] = array[i + 1];
                array[i + 1] = t;
            }
        }
    }
    printf("\nELEMENTS OF AN SORTED ARRAY:");
    for (i = 0; i < n; i++)
        printf("\t%d", array[i]);
}
