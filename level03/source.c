int32_t _init()
{
    if (__gmon_start__)
        __gmon_start__();
    
    frame_dummy();
    return __do_global_ctors_aux();
}

int32_t sub_8048470()
{
    int32_t var_4 = data_8049ff8;
    /* jump -> data_8049ffc */
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int32_t sub_8048486()
{
    /* tailcall */
    return sub_8048470(0);
}

int32_t fflush(FILE* fp)
{
    /* tailcall */
    return fflush(fp);
}

int32_t sub_8048496()
{
    /* tailcall */
    return sub_8048470(8);
}

int32_t getchar()
{
    /* tailcall */
    return getchar();
}

int32_t sub_80484a6()
{
    /* tailcall */
    return sub_8048470(0x10);
}

time_t time(time_t* arg1)
{
    /* tailcall */
    return time(arg1);
}

int32_t sub_80484b6()
{
    /* tailcall */
    return sub_8048470(0x18);
}

void __stack_chk_fail() __noreturn
{
    /* tailcall */
    return __stack_chk_fail();
}

int32_t sub_80484c6()
{
    /* tailcall */
    return sub_8048470(0x20);
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int32_t sub_80484d6()
{
    /* tailcall */
    return sub_8048470(0x28);
}

int32_t system(char const* line)
{
    /* tailcall */
    return system(line);
}

int32_t sub_80484e6()
{
    /* tailcall */
    return sub_8048470(0x30);
}

int32_t __gmon_start__()
{
    /* tailcall */
    return __gmon_start__();
}

int32_t sub_80484f6()
{
    /* tailcall */
    return sub_8048470(0x38);
}

void srand(uint32_t x)
{
    /* tailcall */
    return srand(x);
}

int32_t sub_8048506()
{
    /* tailcall */
    return sub_8048470(0x40);
}

void __libc_start_main(int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int32_t sub_8048516()
{
    /* tailcall */
    return sub_8048470(0x48);
}

int32_t rand()
{
    /* tailcall */
    return rand();
}

int32_t sub_8048526()
{
    /* tailcall */
    return sub_8048470(0x50);
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int32_t sub_8048536()
{
    /* tailcall */
    return sub_8048470(0x58);
}

void __convention("regparm") _start(int32_t arg1, void (* arg2)()) __noreturn
{
    int32_t stack_end = arg1;
    void ubp_av;
    __libc_start_main(main, __return_addr, &ubp_av, __libc_csu_init, __libc_csu_fini, arg2, 
        &stack_end);
    /* no return */
}

void __do_global_dtors_aux()
{
    if (completed.6159)
        return;
    
    for (uint32_t dtor_idx.6161_1 = dtor_idx.6161; dtor_idx.6161_1 < 0; 
        dtor_idx.6161_1 = dtor_idx.6161)
    {
        dtor_idx.6161 = dtor_idx.6161_1 + 1;
        __DTOR_LIST__[dtor_idx.6161_1 + 1]();
    }
    
    completed.6159 = 1;
}

int32_t frame_dummy()
{
    int32_t __JCR_END___1 = __JCR_END__;
    
    if (!__JCR_END___1)
        return __JCR_END___1;
    
    return 0;
}

int32_t clear_stdin()
{
    char var_d = 0;
    char i;
    
    do
    {
        i = getchar();
        
        if (i == 0xa)
            break;
    } while (i != 0xff);
    
    return i;
}

int32_t get_unum()
{
    int32_t result = 0;
    fflush(stdout);
    __isoc99_scanf("%u", &result);
    clear_stdin();
    return result;
}

void prog_timeout() __noreturn
{
    int32_t ebp;
    int32_t var_4 = ebp;
    syscall(sys_exit {1}, 1);
    /* no return */
}

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
    
    switch (ecx_1)
    {
        case 1:
        {
            return decrypt(ecx_1);
            break;
        }
        case 2:
        {
            return decrypt(ecx_1);
            break;
        }
        case 3:
        {
            return decrypt(ecx_1);
            break;
        }
        case 4:
        {
            return decrypt(ecx_1);
            break;
        }
        case 5:
        {
            return decrypt(ecx_1);
            break;
        }
        case 6:
        {
            return decrypt(ecx_1);
            break;
        }
        case 7:
        {
            return decrypt(ecx_1);
            break;
        }
        case 8:
        {
            return decrypt(ecx_1);
            break;
        }
        case 9:
        {
            return decrypt(ecx_1);
            break;
        }
        case 0x10:
        {
            return decrypt(ecx_1);
            break;
        }
        case 0x11:
        {
            return decrypt(ecx_1);
            break;
        }
        case 0x12:
        {
            return decrypt(ecx_1);
            break;
        }
        case 0x13:
        {
            return decrypt(ecx_1);
            break;
        }
        case 0x14:
        {
            return decrypt(ecx_1);
            break;
        }
        case 0x15:
        {
            return decrypt(ecx_1);
            break;
        }
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

void __libc_csu_init()
{
    _init();
}

void j___libc_csu_fini()
{
    /* tailcall */
    return __libc_csu_fini();
}

void __libc_csu_fini() __pure
{
    return;
}

int32_t __i686.get_pc_thunk.bx() __pure
{
    return;
}

int32_t __do_global_ctors_aux()
{
    return 0xffffffff;
}

int32_t _fini()
{
    return __do_global_dtors_aux();
}

