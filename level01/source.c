int32_t _init()
{
    if (__gmon_start__)
        __gmon_start__();
    
    frame_dummy();
    return __do_global_ctors_aux();
}

int32_t sub_8048350()
{
    int32_t var_4 = data_8049ff8;
    /* jump -> data_8049ffc */
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int32_t sub_8048366()
{
    /* tailcall */
    return sub_8048350(0);
}

char* fgets(char* buf, int32_t n, FILE* fp)
{
    /* tailcall */
    return fgets(buf, n, fp);
}

int32_t sub_8048376()
{
    /* tailcall */
    return sub_8048350(8);
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int32_t sub_8048386()
{
    /* tailcall */
    return sub_8048350(0x10);
}

int32_t __gmon_start__()
{
    /* tailcall */
    return __gmon_start__();
}

int32_t sub_8048396()
{
    /* tailcall */
    return sub_8048350(0x18);
}

void __libc_start_main(int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int32_t sub_80483a6()
{
    /* tailcall */
    return sub_8048350(0x20);
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

int32_t verify_user_name()
{
    int32_t __saved_esi;
    bool c = &__saved_esi < 0x10; // -> useless
    bool z = &__saved_esi == 0x10; // -> useless
    puts("verifying username....\n");
    int32_t i = 7;
    char* esi = &a_user_name;
    char* edi = "dat_wil";
    
    while (i)
    {
        char temp1_1 = *esi;
        char temp2_1 = *edi;
        c = temp1_1 < temp2_1;
        z = temp1_1 == temp2_1;
        esi = &esi[1];
        edi = &edi[1];
        i -= 1;
        
        if (!z)
            break;
    }
    
    return (!z && !c) - c;
}

int32_t verify_user_pass(char* arg1)
{
    int32_t i = 5;
    char* esi = arg1;
    char* edi = "admin";
    bool c;
    bool z;
    
    while (i)
    {
        char temp0_1 = *esi;
        char temp1_1 = *edi;
        c = temp0_1 < temp1_1;
        z = temp0_1 == temp1_1;
        esi = &esi[1];
        edi = &edi[1];
        i -= 1;
        
        if (!z)
            break;
    }
    
    char* edx;
    edx = !z && !c;
    return edx - c;
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    void buf;
    __builtin_memset(&buf, 0, 0x40);
    int32_t var_14 = 0;
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(&a_user_name, 0x100, stdin);
    
    if (verify_user_name())
    {
        puts("nope, incorrect username...\n");
        return 1;
    }
    
    puts("Enter Password: ");
    fgets(&buf, 0x64, stdin);
    int32_t eax_2 = verify_user_pass(&buf);
    
    if (eax_2 && !eax_2)
        return 0;
    
    puts("nope, incorrect password...\n");
    return 1;
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
