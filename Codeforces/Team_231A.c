#include <stdio.h>
int main(void)
{
    int num;
    scanf("%d", &num);
    int arr[num][3];
    int count_2 = 0;
    if (num >= 1 && num <= 1000)
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 0; i < num; i++)
        {
            int count_1 = 0;
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 1)
                    count_1++;
            }
            if (count_1 >= 2)
                count_2++;
        }
        printf("%d\n", count_2);
    }
    return 0;
}