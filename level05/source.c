int32_t main(int32_t argc, char** argv, char** envp)
{
    int32_t var_14 = 0;
    char var_78[0x64];
    fgets(&var_78, 0x64, __bss_start);
    int32_t var_14_1 = 0;
    
    while (true)
    {
        int32_t i = 0xffffffff;
        char (* edi_1)[0x64] = &var_78;
        
        while (i)
        {
            bool cond:0_1 = 0 != *edi_1;
            edi_1 = &(*edi_1)[1];
            i -= 1;
            
            if (!cond:0_1)
                break;
        }
        
        if (var_14_1 >= ~i - 1)
            break;
        
        if (var_78[var_14_1] > 0x40 && var_78[var_14_1] <= 0x5a)
            var_78[var_14_1] ^= 0x20;
        
        var_14_1 += 1;
    }
    
    printf(&var_78);
    exit(0);
    /* no return */
}