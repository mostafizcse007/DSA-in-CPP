#include <stdio.h>
int main()
{
    int move;
    scanf("%d", &move);
    double move2 = (double)move / 5;
    if (move2 - (int)move2 != 0)
    {
        int move3 = (int)move2;
        printf("%d\n", move3 + 1);
    }
    else
    {
        int move4 = (int)move2;
        printf("%d\n", move4);
    }
    return 0;
}