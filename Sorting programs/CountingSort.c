#include <stdio.h>
#include <stdlib.h>
void countsortarray(int *array, int limit, int k)
{
    int *b,*count,i;
    b=(int*)malloc(limit*sizeof(int));
    count=(int*)malloc((k+1)*sizeof(int));
    for (i = 0; i <= k; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < limit; i++)
    {
        ++count[array[i]];
    }
    for (i = 1; i <=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for (i=limit-1;i>=0;i--)
    {
        b[--count[array[i]]]=array[i];
    }
    for (i = 0; i < limit; i++)
    {
        array[i] = b[i];
    }
    free(b);
    free(count);
}

int main()
{
    int *array, limit, i, k;
    printf("ENTER LIMIT:");
    scanf(" %d", &limit);
    array = (int *)malloc(limit * sizeof(int));
    printf("ENTER ARRAY ELEMENTS:");
    for (i = 0; i < limit; i++)
    {
        scanf("%d", &array[i]);
    }
    k = array[0];
    for (i = 1; i < limit; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    countsortarray(array, limit, k);
    printf("\nSORTED ARRAY:");
    for (i = 0; i < limit; i++)
        printf("%d\t", array[i]);
    printf("\n");
    free(array);
    return 0;
}
