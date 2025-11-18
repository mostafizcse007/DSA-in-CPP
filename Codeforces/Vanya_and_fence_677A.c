#include <stdio.h>
int main()
{
    int num, height;
    scanf("%d%d", &num, &height);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = num;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] > height)
            count += 1;
    }
    printf("%d\n", count);
    return 0;
}