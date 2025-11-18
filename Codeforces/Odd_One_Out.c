#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    int arr[test][3];
    for (int i = 0; i < test; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < test; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (arr[i][j] == arr[i][j + 1])
                printf("%d\n", arr[i][j + 2]);
            else if (arr[i][j] == arr[i][j + 2])
                printf("%d\n", arr[i][j + 1]);
            else if (arr[i][j + 2] == arr[i][j + 1])
                printf("%d\n", arr[i][j]);
        }
    }
    return 0;
}