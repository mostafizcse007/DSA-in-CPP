#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        int response, check, max = 0;
        scanf("%d", &response);
        int arr_1[response][2];
        for (int j = 0; j < response; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                scanf("%d", &arr_1[j][k]);
            }
        }
        for (int j = 0; j < response; j++)
        {
            if (arr_1[j][0] <= 10)
            {
                if (arr_1[j][1] > max)
                {
                    max = arr_1[j][1];
                    check = j;
                }
            }
        }
        printf("%d\n", check + 1);
    }
    return 0;
}