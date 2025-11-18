#include <stdio.h>
int main(void)
{
    int weight;
    scanf("%d", &weight);
    if (weight >= 1 && weight <= 100)
    {
        if (weight % 2 == 0)
        {
            if (weight == 2)
            {
                printf("NO\n");
            }
            else
                printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}