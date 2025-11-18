#include <stdio.h>
int main()
{
    long long int num, count_2 = 0, count_3 = 0;
    scanf("%lld", &num);
    while (num != 0)
    {
        if (num % 10 == 4)
            count_2++;
        else if (num % 10 == 7)
            count_3++;
        num /= 10;
    }
    count_2 += count_3;
    if (count_2 == 7 || count_2 == 4)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}