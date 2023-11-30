#include <stdio.h>
int main()
{
    int arr[5], temp, i;
    printf("Enter a numbers\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\narray before shorting\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (arr[j] < arr[k])
            {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n");
    printf("array after shorting\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}