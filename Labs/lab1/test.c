#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input1 = '\0';
    char input2 = '\0';
    char input3 = '\0';

    int ASCII1, ASCII2 = -1;

    while (input1 == '\0' || input2 == '\0')
    {
        printf("What range do you want to know the ASCII for (enter two chars): ");
        if (scanf("%c%c%c", &input1, &input2, &input3) != 3)
        {
            printf("Whoops! You need to give me two LETTERS!\n");
            exit(1);
        }
    }

    if((int)input2 <= 31)
    {
        printf("Whoops! You need to give me two LETTERS!\n");
        exit(1);
    }
    
    if((int)input3 != 10)
    {
        printf("Whoops! You need to give me two LETTERS!\n");
        exit(1);
    }

    if (input1 > input2)
    {
        ASCII1 = input2;
        ASCII2 = input1;
    }
    else
    {
        ASCII1 = input1;
        ASCII2 = input2;
    }

    for (int i = ASCII1; i <= ASCII2; ++i)
    {
        printf("%3c: %3d(0x%x)\n", i, i, i);
    }

    // for (i = 1; i <= max; ++i)
    // {
    //     printf("%5d!\n", i);
    // }
    printf("ALL DONE!\n");

    return 0;
}