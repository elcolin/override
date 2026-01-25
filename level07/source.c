int32_t main(int32_t argc, char** argv, char** envp)
{
    char** argv_1 = argv;
    char** envp_1 = envp;
    void* gsbase;
    int32_t eax_2 = *(gsbase + 0x14);
    int32_t var_2c_1;
    __builtin_memset(&var_2c_1, 0, 0x18);
    void var_1bc;
    __builtin_memset(&var_1bc, 0, 0x190);
    int32_t var_1dc;
    size_t fp;
    
    while (*argv_1)
    {
        int32_t i = 0xffffffff;
        char* edi_1 = *argv_1;
        
        while (i)
        {
            bool cond:0_1 = 0 != *edi_1;
            edi_1 = &edi_1[1];
            i -= 1;
            
            if (!cond:0_1)
                break;
        }
        
        fp = ~i - 1;
        var_1dc = 0;
        memset(*argv_1, var_1dc, fp);
        argv_1 = &argv_1[1];
    }
    
    while (*envp_1)
    {
        int32_t i_1 = 0xffffffff;
        char* edi_2 = *envp_1;
        
        while (i_1)
        {
            bool cond:1_1 = 0 != *edi_2;
            edi_2 = &edi_2[1];
            i_1 -= 1;
            
            if (!cond:1_1)
                break;
        }
        
        fp = ~i_1 - 1;
        var_1dc = 0;
        memset(*envp_1, var_1dc, fp);
        envp_1 = &envp_1[1];
    }
    
    puts("----------------------------------------------------\n  Welcome to wil's crappy number "
    "storage service!   \n----------------------------------------------------\n Commands:                                          "
    "    store - store a number into the data storage    \n    read  - read a number from the data "
    "storage     \n    quit  ");
    
    while (true)
    {
        printf("Input command: ", var_1dc, fp);
        int32_t var_2c_2 = 1;
        fp = stdin;
        int32_t buf;
        fgets(&buf, 0x14, fp);
        int32_t i_2 = 0xffffffff;
        int32_t* edi_3 = &buf;
        
        while (i_2)
        {
            bool cond:6_1 = 0 != *edi_3;
            edi_3 += 1;
            i_2 -= 1;
            
            if (!cond:6_1)
                break;
        }
        
        bool c_1 = ~i_2 - 1 < 1;
        bool z_1 = ~i_2 == 2;
        *(&buf + ~i_2 - 2) = 0;
        int32_t i_3 = 5;
        int32_t* esi_1 = &buf;
        char* edi_4 = "store";
        
        while (i_3)
        {
            char temp1_1 = *esi_1;
            char temp2_1 = *edi_4;
            c_1 = temp1_1 < temp2_1;
            z_1 = temp1_1 == temp2_1;
            esi_1 += 1;
            edi_4 = &edi_4[1];
            i_3 -= 1;
            
            if (!z_1)
                break;
        }
        
        bool c_2 = false;
        bool z_2 = !((!z_1 && !c_1) - c_1);
        
        if (!z_2)
        {
            int32_t i_4 = 4;
            int32_t* esi_2 = &buf;
            char* edi_5 = "read";
            
            while (i_4)
            {
                char temp3_1 = *esi_2;
                char temp4_1 = *edi_5;
                c_2 = temp3_1 < temp4_1;
                z_2 = temp3_1 == temp4_1;
                esi_2 += 1;
                edi_5 = &edi_5[1];
                i_4 -= 1;
                
                if (!z_2)
                    break;
            }
            
            bool c_3 = false;
            bool z_3 = !((!z_2 && !c_2) - c_2);
            
            if (!z_3)
            {
                int32_t i_5 = 4;
                int32_t* esi_3 = &buf;
                char* edi_6 = "quit";
                
                while (i_5)
                {
                    char temp5_1 = *esi_3;
                    char temp6_1 = *edi_6;
                    c_3 = temp5_1 < temp6_1;
                    z_3 = temp5_1 == temp6_1;
                    esi_3 += 1;
                    edi_6 = &edi_6[1];
                    i_5 -= 1;
                    
                    if (!z_3)
                        break;
                }
                
                if (!((!z_3 && !c_3) - c_3))
                {
                    if (eax_2 == *(gsbase + 0x14))
                        return 0;
                    
                    __stack_chk_fail();
                    /* no return */
                }
            }
            else
            {
                read_number(&var_1bc);
                var_2c_2 = 0;
            }
        }
        else
            var_2c_2 = store_number(&var_1bc);
        
        if (!var_2c_2)
        {
            var_1dc = &buf;
            printf(" Completed %s command successfully\n", var_1dc);
        }
        else
        {
            var_1dc = &buf;
            printf(" Failed to do %s command\n", var_1dc);
        }
        
        __builtin_memset(&buf, 0, 0x14);
    }
}