#include <stdio.h>
#include <string.h>
int main()
{
    char str[5000];
    int count_up = 0, count_low = 0;
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            count_low++;
        else
            count_up++;
    }
    if (count_low > count_up)
    {
        strlwr(str);
        printf("%s", str);
    }
    else if (count_low == count_up)
    {
        strlwr(str);
        printf("%s", str);
    }
    else
    {
        strupr(str);
        printf("%s", str);
    }
    return 0;
}