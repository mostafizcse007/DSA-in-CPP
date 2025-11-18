#include <stdio.h>
int main()
{
    int k, n, w, sum = 0;
    scanf("%d%d%d", &k, &n, &w);
    for (int i = 1; i <= w; i++)
    {
        sum += k * i;
    }
    if (sum > n)
        printf("%d\n", sum - n);
    else if (sum == n)
        printf("0\n");
    else
        printf("0\n");
    return 0;
}