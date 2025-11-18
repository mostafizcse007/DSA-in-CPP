#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a + b >= 10 || b + c >= 10 || c + a >= 10)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}