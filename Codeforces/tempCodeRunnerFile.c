#include <stdio.h>
#include <math.h>
int main()
{
    long long int num, count = 0;
    scanf("%lld", &num);
    for (int i = 1; i <= num; i++)
    {
        int power = pow(-1, i);
        power *= i;
        count += power;
    }
    printf("%lld\n", count);
    return 0;
}
