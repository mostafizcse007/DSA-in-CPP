#include <stdio.h>
int main()
{
    int num, count = 0;
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < num; i++)
    {
        count += arr[i];
    }
    printf("%.12lf\n", (double)count / num);
    return 0;
}