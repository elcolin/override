#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char key[] = "Q}|u`sfg~sf{}|a3";
    char res[] = "Congratulations!";
    char test;

    for (int j = 0;  j < 21; j++)
    {
        printf("%d: ", j);
        for (int i = 0; i < strlen(key); i++)
        {
            test = key[i] ^ j;
            //if (test == res[i])
            printf("%c", test);
        };
        printf("\n");
    }
    // printf("%d", 0x1337d00d)
    #define SRCH            0x1337d00d
    int i = 0;
    u_int32_t res2 = SRCH;
    while ((SRCH - res2) !=  0x0000012)
    {
        res2++;
    }
    printf("%x", res2);
}
