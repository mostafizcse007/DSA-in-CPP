#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1000], str2[1000];
    scanf("%s", str1);
    scanf("%s", str2);
    strrev(str1);
    int value = strcmp(str1, str2);
    if (value == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}