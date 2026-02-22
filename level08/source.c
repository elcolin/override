int32_t main(int32_t argc, char** argv, char** envp)
{
    void* fsbase;
    int64_t rax = *(fsbase + 0x28);
    char buf = 0xff;
    int32_t var_80 = 0xffffffff;
    
    if (argc != 2)
        printf("Usage: %s filename\n", *argv);
    
    FILE* fd = fopen("./backups/.log", "w");
    
    if (!fd)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
        /* no return */
    }
    
    log_wrapper(fd, "Starting back up: ", argv[1]);
    FILE* fp = fopen(argv[1], "r");
    
    if (!fp)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
        /* no return */
    }
    
    int64_t file;
    __builtin_strncpy(&file, "./backups/", 0xb);
    int64_t i = -1;
    int64_t* rdi_2 = &file;
    
    while (i)
    {
        bool cond:0_1 = 0 != *rdi_2;
        rdi_2 += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    strncat(&file, argv[1], 0x63 - (~i - 1));
    int32_t fd = open(&file, 0xc1, 0x1b0);
    
    if (fd < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
        /* no return */
    }
    
    while (true)
    {
        buf = fgetc(fp);
        
        if (buf == 0xff)
            break;
        
        write(fd, &buf, 1);
    }
    
    log_wrapper(fd, "Finished back up ", argv[1]);
    fclose(fp);
    close(fd);
    
    if (rax == *(fsbase + 0x28))
        return 0;
    
    __stack_chk_fail();
    /* no return */
}