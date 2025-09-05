#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char key[] = "Q}|u`sfg~sf{}|a3";
    for (int j = 1;  j > -18; j--)
    {
        printf("%d: ", j);
        for (int i = 0; i < strlen(key); i++)
        {
            printf("%c ", key[i] ^= j);
        };
        printf("\n");
    }
}
