#include <stdio.h>
#include <string.h>
int main()
{
    char str[5000];
    fgets(str, sizeof(str), stdin);
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] -= 32;
    }
    printf("%s", str);
    return 0;
}