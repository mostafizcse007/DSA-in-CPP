#include <stdio.h>
int main()
{
    long long int test;
    scanf("%lld", &test);
    for (long long int i = 0; i < test; i++)
    {
        long long int a, b = 1;
        scanf("%lld", &a);
        a -= 1;
        long long int count = 0;
        while (a > b)
        {
            a--;
            b++;
            count++;
        }
        printf("%lld\n", count);
    }
    return 0;
}