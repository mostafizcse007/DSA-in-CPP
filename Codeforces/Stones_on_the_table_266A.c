#include <stdio.h>
#include <string.h>
int main()
{
    int num, count = 0, i;
    scanf("%d", &num);
    getchar();
    char str[num];
    gets(str);
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == str[i + 1])
            count++;
    }
    printf("%d\n", count);
    return 0;
}