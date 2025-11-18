#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int arr[num], count = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == 1)
            count++;
    }
    if (count >= 1)
        printf("HARD\n");
    else
        printf("EASY\n");
    return 0;
}