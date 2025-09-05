
int main()
{
    char *v0;  // [bp-0x20]
    struct struct_0 v1[4];  // [bp-0x8]

    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    v0 = &v1[0].field_0;
    __isoc99_scanf("%d");
    if (v1 != 5276)
    {
        puts("\nInvalid Password!");
        return 1;
    }
    puts("\nAuthenticated!");
    system("/bin/sh");
    return 0;
}