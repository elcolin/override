#include "out.h"


undefined main;
undefined __libc_csu_init;
undefined __libc_csu_fini;
undefined1 completed.6159;
undefined4 dtor_idx.6161;
undefined1 a_user_name;
undefined4 stdin;

int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}



void FUN_08048350(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
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



void __libc_start_main(void)

{
  __libc_start_main();
  return;
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



// WARNING: Removing unreachable block (ram,0x0804840a)
// WARNING: Removing unreachable block (ram,0x08048410)

void __do_global_dtors_aux(void)

{
  if (completed_6159 == '\0') {
    completed_6159 = '\x01';
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x0804844f)
// WARNING: Removing unreachable block (ram,0x08048458)

void frame_dummy(void)

{
  return;
}



int verify_user_name(void)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte bVar6;
  
  bVar6 = 0;
  uVar4 = &stack0xfffffff4 < (undefined1 *)0x10;
  uVar5 = &stack0x00000000 == (undefined1 *)0x1c;
  puts("verifying username....\n");
  iVar1 = 7;
  pbVar2 = &a_user_name;
  pbVar3 = (byte *)"dat_wil";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    uVar4 = *pbVar2 < *pbVar3;
    uVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + (uint)bVar6 * -2 + 1;
    pbVar3 = pbVar3 + (uint)bVar6 * -2 + 1;
  } while ((bool)uVar5);
  return (int)(char)((!(bool)uVar4 && !(bool)uVar5) - uVar4);
}



int verify_user_pass(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  iVar1 = 5;
  pbVar2 = (byte *)"admin";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    in_CF = *param_1 < *pbVar2;
    in_ZF = *param_1 == *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  } while ((bool)in_ZF);
  return (int)(char)((!(bool)in_CF && !(bool)in_ZF) - in_CF);
}

undefined4 main(void)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char local_54 [64];
  int local_14;
  
  pcVar3 = local_54;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  local_14 = 0;
  puts("********* ADMIN LOGIN PROMPT *********");
  printf("Enter Username: ");
  fgets(&a_user_name,0x100,stdin);
  local_14 = verify_user_name();
  if (local_14 == 0) {
    puts("Enter Password: ");
    fgets(local_54,100,stdin);
    local_14 = verify_user_pass(local_54);
    if ((local_14 == 0) || (local_14 != 0)) {
      puts("nope, incorrect password...\n");
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    puts("nope, incorrect username...\n");
    uVar1 = 1;
  }
  return uVar1;
}

// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx
// WARNING: Removing unreachable block (ram,0x080485f0)
// WARNING: Removing unreachable block (ram,0x080485f8)

void __libc_csu_init(void)

{
  EVP_PKEY_CTX *in_stack_ffffffd4;
  
  _init(in_stack_ffffffd4);
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



// WARNING: Removing unreachable block (ram,0x08048651)
// WARNING: Removing unreachable block (ram,0x08048658)

void __do_global_ctors_aux(void)

{
  return;
}



void _fini(void)

{
  __do_global_dtors_aux();
  return;
}



