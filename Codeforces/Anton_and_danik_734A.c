#include <stdio.h>
#include <string.h>
int main()
{
    int num, count_a = 0, count_d = 0;
    scanf("%d", &num);
    char str[num + 1];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'A')
            count_a++;
        else
            count_d++;
    }
    if (count_a == count_d)
        printf("Friendship\n");
    else if (count_a > count_d)
        printf("Anton\n");
    else
        printf("Danik\n");
    return 0;
}