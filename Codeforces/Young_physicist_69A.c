#include <stdio.h>
int main()
{
    int row, count = 0;
    scanf("%d", &row);
    int arr[row][3], arr2[3];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        arr2[i] = sum;
    }
    for (int i = 0; i < 3; i++)
    {
        if (arr2[i] == 0)
            count++;
    }
    if (count == 3)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}