#include <stdio.h>
#include <string.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int count = 0;
        char str[100], str2[100];
        scanf("%s", str);
        strcpy(str2, str);
        int len = strlen(str);
        int arr[26];
        for (int j = 0; j < 26; j++)
        {
            arr[j] = 0;
        }
        for (int j = 0; j < len; j++)
        {
            str[j] -= 97;
            arr[str[j]]++;
        }
        for (int j = 0; j < 26; j++)
        {
            if (arr[j] != 0)
                count++;
        }
        if (count == 1)
            printf("No\n");
        else
        {
            for (int j = 0; j < len - 1; j++)
            {
                if (str2[j] != str2[j + 1])
                {
                    char temp = str2[j];
                    str2[j] = str2[j + 1];
                    str2[j + 1] = temp;
                }
            }
            printf("Yes\n%s\n", str2);
        }
    }
    return 0;
}