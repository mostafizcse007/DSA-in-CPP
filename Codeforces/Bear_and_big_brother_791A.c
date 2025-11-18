#include <stdio.h>
int main()
{
    int limak, bob, count = 0;
    scanf("%d%d", &limak, &bob);
    while (1)
    {
        limak *= 3;
        bob *= 2;
        count++;
        if (limak > bob)
            break;
    }
    printf("%d\n", count);
    return 0;
}