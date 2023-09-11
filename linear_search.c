#include <stdio.h>
int main()
{
    int arr[5] = {1, 4, 3, 2, 5}, i, temp, userInput;
    printf("Enter a numbers\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Search a number\n");
    scanf("%d", &userInput);

    for (i = 0; i < 5; i++)
    {
        if (arr[i] == userInput)
        {
            printf("Number found \nNumber present in %d th position", i + 1);
            break;
        }
    }
    if (i == 5)
    {
        printf("Number not found");
    }

    return 0;
}