#include <stdio.h>
#include <string.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        char str1[4], str2[4];
        scanf("%s", str1);
        scanf("%s", str2);
        char temp = str1[0];
        str1[0] = str2[0];
        str2[0] = temp;
        printf("%s %s\n", str1, str2);
    }
    return 0;
}