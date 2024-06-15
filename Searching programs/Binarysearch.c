#include <stdio.h>
int main()
{
	int n, array[100], i, top, bottom, mid, num, flag = 0,pass,temp;
	printf("ENTER LIMIT:");
	scanf("%d", &n);
	printf("\nENTER ELEMENTS OF AN ARRAY:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	 for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n - pass; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp= array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
	printf("\nENTER NO FOR SEARCH:");
	scanf("%d", &num);
	top = 0;	
	bottom = n - 1;
	while (top <= bottom)
	{
		mid = (top + bottom) / 2;
		if (num == array[mid])
		{
			flag = 1;
			break;
		}
		if (num > array[mid])
		{
			top = mid + 1;
		}
		else
			bottom = mid - 1;
	}
	if (flag == 1)
		printf("\nNUMBER IS FOUND");
	else
		printf("\nNUMBER IS NOT FOUND");
	return 0;
}
