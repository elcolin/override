int32_t main(int32_t argc, char** argv, char** envp)
{
    pid_t eax = fork();
    char buf[0x80];
    __builtin_memset(&buf, 0, 0x80);
    int32_t var_18 = 0;
    int32_t stat_loc = 0;
    
    if (eax)
    {
        while (true)
        {
            wait(&stat_loc);
            
            if (!(stat_loc & 0x7f) || ((stat_loc & 0x7f) + 1) >> 1 > 0)
            {
                puts("child is exiting...");
                break;
            }
            
            if (ptrace(PTRACE_PEEKUSER, eax, 0x2c, 0) != 0xb)
                continue;
            
            puts("no exec() for you");
            kill(eax, 9);
            break;
        }
    }
    else
    {
        prctl(1, 1);
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(&buf);
    }
    
    return 0;
}