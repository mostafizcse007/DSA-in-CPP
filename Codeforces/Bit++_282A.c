#include <stdio.h>
#include <string.h>

int main(void)
{
    int num, x = 0;
    scanf("%d", &num);

    char str[5]; // size increased to 5 to account for the newline character

    for (int i = 0; i < num; i++)
    {
        fgets(str, sizeof(str), stdin);

        // Remove the newline character
        if (str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = '\0';

        if (strcmp(str, "X++") == 0 || strcmp(str, "++X") == 0)
            x += 1;
        else if (strcmp(str, "X--") == 0 || strcmp(str, "--X") == 0)
            x -= 1;
    }

    printf("%d\n", x);
    return 0;
}
