#include <stdio.h>
int main()
{
    int tst;
    scanf("%d", &tst);
    for (int i = 1; i <= tst; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}