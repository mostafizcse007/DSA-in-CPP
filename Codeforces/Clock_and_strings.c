#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int a, b, c, d, count = 0;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        for (int j = a; j <= b; j++)
        {
            if (j == c || j == d)
            {
                count++;
            }
        }
        if (count == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}