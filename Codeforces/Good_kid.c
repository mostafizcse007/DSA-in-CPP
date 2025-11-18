#include <stdio.h>
#include <limits.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int num, min = INT_MAX, location = 0;
        scanf("%d", &num);
        int arr[num];
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &arr[j]);
        }
        for (int j = 0; j < num; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                location = j;
            }
        }
        min += 1;
        arr[location] = min;
        int product = 1;
        for (int j = 0; j < num; j++)
        {
            product *= arr[j];
        }
        printf("%d\n", product);
    }
    return 0;
}