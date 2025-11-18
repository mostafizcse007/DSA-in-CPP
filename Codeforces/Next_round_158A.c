#include <stdio.h>
int main()
{
    int num;
    int num2, count = 0;
    scanf("%d", &num);
    scanf("%d", &num2);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < num; i++)
    {
        if (arr[num2 - 1] == 0)
        {
            if (arr[i] > 0)
                count++;
        }
        else if (arr[i] >= arr[num2 - 1])
            count++;
    }
    printf("%d\n", count);
}