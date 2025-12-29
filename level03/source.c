
int32_t decrypt(char arg1)
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t edi;
    int32_t var_8 = edi;
    int32_t esi;
    int32_t var_c = esi;
    void* gsbase;
    int32_t eax = *(gsbase + 0x14);
    int32_t var_21;
    __builtin_strncpy(&var_21, "Q}|u`sfg~sf{}|a3", 0x11);
    int32_t var_50 = 0;
    int32_t* esp_1 = &var_50;
    int32_t var_30 = 0xffffffff;
    int32_t i = 0xffffffff;
    int32_t* edi_1 = &var_21;
    
    while (i)
    {
        bool cond:0_1 = 0 != *edi_1;
        edi_1 += 1;
        i -= 1;
        
        if (!cond:0_1)
            break;
    }
    
    int32_t var_2c = 0;
    bool c_1;
    bool z_1;
    
    while (true)
    {
        c_1 = var_2c < ~i - 1;
        z_1 = var_2c == ~i - 1;
        
        if (!c_1)
            break;
        
        *(&var_21 + var_2c) ^= arg1;
        var_2c += 1;
    }
    
    int32_t i_1 = 0x11;
    int32_t* esi_1 = &var_21;
    char* edi_2 = "Congratulations!";
    
    while (i_1)
    {
        char temp1_1 = *esi_1;
        char temp2_1 = *edi_2;
        c_1 = temp1_1 < temp2_1;
        z_1 = temp1_1 == temp2_1;
        esi_1 += 1;
        edi_2 = &edi_2[1];
        i_1 -= 1;
        
        if (!z_1)
            break;
    }
    
    int32_t result;
    
    if ((!z_1 && !c_1) - c_1)
    {
        esp_1[1] = "\nInvalid Password";
        result = puts();
    }
    else
    {
        esp_1[1] = "/bin/sh";
        result = system();
    }
    
    if (eax != *(gsbase + 0x14))
    {
        __stack_chk_fail();
        /* no return */
    }
    
    esp_1[0x11];
    esp_1[0x12];
    esp_1[0x13];
    return result;
}

int32_t test(int32_t arg1, int32_t arg2)
{
    int32_t ecx_1 = arg2 - arg1;
    if (ecx_1 < 21) {
        return decrypt(ecx_1);
    }    
    return decrypt(rand());
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    int32_t __saved_ebp_1;
    int32_t __saved_ebp = __saved_ebp_1;
    int32_t entry_eax;
    int32_t var_34 = entry_eax;
    int32_t* esp_1 = &var_34;
    *esp_1;
    esp_1[1] = 0;
    esp_1[1] = time();
    srand();
    esp_1[1] = "***********************************";
    puts();
    esp_1[1] = "*\t\tlevel03\t\t**";
    puts();
    esp_1[1] = "***********************************";
    puts();
    esp_1[1] = "Password:";
    printf();
    esp_1[2] = &esp_1[8];
    esp_1[1] = &data_8048a85;
    __isoc99_scanf();
    int32_t eax_2 = esp_1[8];
    esp_1[2] = 0x1337d00d;
    esp_1[1] = eax_2;
    test();
    return 0;
}
