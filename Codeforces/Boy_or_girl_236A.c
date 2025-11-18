#include <stdio.h>
#include <string.h>
int main()
{
    char str[5], temp[5];
    scanf("%s", str);
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (str[i] != str[j])
                temp[i] = str[i];
        }
    }
    printf("%s", temp);
    return 0;
}