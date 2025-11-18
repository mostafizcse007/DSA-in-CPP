#include <stdio.h>
#include <string.h>
int main()
{
    char str1[500];
    char str2[500];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    strlwr(str1);
    strlwr(str2);
    int check = strcmp(str1, str2);
    if (check == 1)
        printf("1\n");
    else if (check == 0)
        printf("0\n");
    else if (check == -1)
        printf("-1\n");
    return 0;
}