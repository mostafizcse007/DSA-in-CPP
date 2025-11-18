#include <stdio.h>
#include <string.h>
int main(void)
{
    int word;
    scanf("%d", &word);
    char str[100];
    if (word >= 1 && word <= 100)
    {
        for (int i = 0; i < word; i++)
        {
            scanf("%s", str);
            int len = strlen(str);
            if (len <= 10)
                printf("%s\n", str);
            else
                printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
        }
    }
    return 0;
}