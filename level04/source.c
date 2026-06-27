#include "out.h"


undefined main;
undefined __libc_csu_init;
undefined __libc_csu_fini;
undefined1 completed.6159;
undefined4 dtor_idx.6161;
undefined DAT_08048900;
undefined4 stdout;
undefined prog_timeout;
pointer __DT_INIT_ARRAY;

int _init(EVP_PKEY_CTX *ctx)
{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}



void FUN_08048490(void)
{
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fflush(FILE *__stream)
{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * gets(char *__s)
{
  char *pcVar1;
  
  pcVar1 = gets(__s);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int getchar(void)
{
  int iVar1;
  
  iVar1 = getchar();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__sighandler_t signal(int __sig,__sighandler_t __handler)
{
  __sighandler_t p_Var1;
  
  p_Var1 = signal(__sig,__handler);
  return p_Var1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

uint alarm(uint __seconds)
{
  uint uVar1;
  
  uVar1 = alarm(__seconds);
  return uVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__pid_t wait(void *__stat_loc)
{
  __pid_t _Var1;
  
  _Var1 = wait(__stat_loc);
  return _Var1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)
{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



void __gmon_start__(void)
{
  __gmon_start__();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int kill(__pid_t __pid,int __sig)
{
  int iVar1;
  
  iVar1 = kill(__pid,__sig);
  return iVar1;
}



void __libc_start_main(void)
{
  __libc_start_main();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int prctl(int __option,...)
{
  int iVar1;
  
  iVar1 = prctl(__option);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__pid_t fork(void)
{
  __pid_t _Var1;
  
  _Var1 = fork();
  return _Var1;
}



void __isoc99_scanf(void)
{
  __isoc99_scanf();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

long ptrace(__ptrace_request __request,...)
{
  long lVar1;
  
  lVar1 = ptrace(__request);
  return lVar1;
}



void processEntry _start(undefined4 param_1,undefined4 param_2)
{
  undefined1 auStack_4 [4];
  
  __libc_start_main(main,param_2,&stack0x00000004,__libc_csu_init,__libc_csu_fini,param_1,auStack_4)
  ;
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x080485da)
// WARNING: Removing unreachable block (ram,0x080485e0)

void __do_global_dtors_aux(void)
{
  if (completed_6159 == '\0') {
    completed_6159 = '\x01';
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x0804861f)
// WARNING: Removing unreachable block (ram,0x08048628)

void frame_dummy(void)
{
  return;
}



void clear_stdin(void)
{
  int iVar1;
  
  do {
    iVar1 = getchar();
    if ((char)iVar1 == '\n') {
      return;
    }
  } while ((char)iVar1 != -1);
  return;
}



undefined4 get_unum(void)
{
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&DAT_08048900,local_10);
  clear_stdin();
  return local_10[0];
}


void prog_timeout(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x80);
  (*pcVar1)();
  return;
}

void enable_timeout_cons(void)

{
  signal(0xe,prog_timeout);
  alarm(0x3c);
  return;
}

undefined4 main(void)
{
  int iVar1;
  char *pcVar2;
  byte bVar3;
  uint local_a4;
  char local_a0 [128];
  uint local_20;
  uint local_1c;
  long local_18;
  int local_14;
  
  bVar3 = 0;
  local_14 = fork();
  pcVar2 = local_a0;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + ((uint)bVar3 * -2 + 1) * 4;
  }
  local_18 = 0;
  local_a4 = 0;
  if (local_14 == 0) {
    prctl(1,1);
    ptrace(PTRACE_TRACEME,0,0,0);
    puts("Give me some shellcode, k");
    gets(local_a0);
  }
  else {
    do {
      wait(&local_a4);
      local_20 = local_a4;
      if (((local_a4 & 0x7f) == 0) ||
         (local_1c = local_a4, '\0' < (char)(((byte)local_a4 & 0x7f) + 1) >> 1)) {
        puts("child is exiting...");
        return 0;
      }
      local_18 = ptrace(PTRACE_PEEKUSER,local_14,0x2c,0);
    } while (local_18 != 0xb);
    puts("no exec() for you");
    kill(local_14,9);
  }
  return 0;
}

// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

void __libc_csu_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  EVP_PKEY_CTX *in_stack_ffffffd4;
  
  _init(in_stack_ffffffd4);
  iVar1 = 0;
  do {
    (*(code *)(&__DT_INIT_ARRAY)[iVar1])(param_1,param_2,param_3);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 1);
  return;
}

void __libc_csu_fini(void)

{
  return;
}

// WARNING: This is an inlined function

void __i686_get_pc_thunk_bx(void)

{
  return;
}

// WARNING: Removing unreachable block (ram,0x080488c1)
// WARNING: Removing unreachable block (ram,0x080488c8)

void __do_global_ctors_aux(void)

{
  return;
}

void _fini(void)

{
  __do_global_dtors_aux();
  return;
}
