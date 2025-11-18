#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int arr[num][2], count = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (arr[i][1] - arr[i][j] >= 2)
                count++;
        }
    }
    printf("%d\n", count);
    return 0;
}