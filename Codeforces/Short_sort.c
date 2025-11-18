#include <stdio.h>
#include <string.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        char str1[1000], str2[1000], str3[1000] = "abc";
        scanf("%s", &str1);
        strcpy(str2, str1);
        strrev(str2);
        int value = strcmp(str2, str3);
        if (value == 0)
            printf("yes\n");
        else if (str1[0] == 'a')
            printf("yes\n");
        else if (str1[0] == 'b' && str1[1] == 'a')
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}