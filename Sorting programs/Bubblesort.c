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
    int pass,i,temp;
    for(pass=0;pass<n-1;pass++)
    {
        for(i=0;i<n-pass-1;i++)
        {
            if(array[i]>array[i+1])
            {
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
    printf("\nELEMENTS OF AN SORTED ARRAY:");
    for (i = 0; i < n; i++)
        printf("\t%d", array[i]);
}
