#include "out.h"

undefined main;
undefined __libc_csu_init;
undefined __libc_csu_fini;
undefined1 completed.6159;
undefined4 dtor_idx.6161;
undefined4 __JCR_END__;
undefined4 stdin;
undefined4 __CTOR_LIST__;

int _init(EVP_PKEY_CTX *ctx) {
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}

void FUN_08048330(void) {
  (*(code *)(undefined *)0x0)();
  return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int printf(char *__format,...) {
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
char * fgets(char *__s,int __n,FILE *__stream) {
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}

void __gmon_start__(void) {
  __gmon_start__();
  return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
void exit(int __status) {
                    // WARNING: Subroutine does not return
  exit(__status);
}

void __libc_start_main(void) {
  __libc_start_main();
  return;
}

void processEntry _start(undefined4 param_1,undefined4 param_2) {
  undefined1 auStack_4 [4];
  
  __libc_start_main(main,param_2,&stack0x00000004,__libc_csu_init,__libc_csu_fini,param_1,auStack_4)
  ;
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}

// WARNING: Removing unreachable block (ram,0x080483ea)
// WARNING: Removing unreachable block (ram,0x080483f0)

void __do_global_dtors_aux(void) {
  if (completed_6159 == '\0') {
    completed_6159 = '\x01';
  }
  return;
}

// WARNING: Removing unreachable block (ram,0x08048438)

void frame_dummy(void) {
  return;
}

void main(void) {
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  byte local_78 [100];
  uint local_14;
  
  bVar4 = 0;
  local_14 = 0;
  fgets((char *)local_78,100,stdin);
  local_14 = 0;
  do {
    uVar2 = 0xffffffff;
    pbVar3 = local_78;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + (uint)bVar4 * -2 + 1;
    } while (bVar1 != 0);
    if (~uVar2 - 1 <= local_14) {
      printf((char *)local_78);
                    // WARNING: Subroutine does not return
      exit(0);
    }
    if (('@' < (char)local_78[local_14]) && ((char)local_78[local_14] < '[')) {
      local_78[local_14] = local_78[local_14] ^ 0x20;
    }
    local_14 = local_14 + 1;
  } while( true );
}

// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx
// WARNING: Removing unreachable block (ram,0x08048550)
// WARNING: Removing unreachable block (ram,0x08048558)

void __libc_csu_init(void) {
  EVP_PKEY_CTX *in_stack_ffffffd4;
  
  _init(in_stack_ffffffd4);
  return;
}

void __libc_csu_fini(void) {
  return;
}

// WARNING: This is an inlined function
void __i686_get_pc_thunk_bx(void) {
  return;
}

void __do_global_ctors_aux(void) {
  code *pcVar1;
  int *piVar2;
  
  if (__CTOR_LIST__ != (code *)0xffffffff) {
    piVar2 = (int *)&__CTOR_LIST__;
    pcVar1 = __CTOR_LIST__;
    do {
      piVar2 = piVar2 + -1;
      (*pcVar1)();
      pcVar1 = (code *)*piVar2;
    } while (pcVar1 != (code *)0xffffffff);
  }
  return;
}

void _fini(void) {
  __do_global_dtors_aux();
  return;
}
