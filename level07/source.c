#include "out.h"


undefined main;
undefined __libc_csu_init;
undefined __libc_csu_fini;
undefined1 completed.6159;
undefined4 dtor_idx.6161;
undefined DAT_08048ad0;
undefined4 stdout;
undefined1 DAT_08048d61;
undefined1 DAT_08048d66;
undefined4 stdin;

int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}



void FUN_08048460(void)

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

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int getchar(void)

{
  int iVar1;
  
  iVar1 = getchar();
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
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



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



void __isoc99_scanf(void)

{
  __isoc99_scanf();
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



// WARNING: Removing unreachable block (ram,0x0804856a)
// WARNING: Removing unreachable block (ram,0x08048570)

void __do_global_dtors_aux(void)

{
  if (completed_6159 == '\0') {
    completed_6159 = '\x01';
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x080485af)
// WARNING: Removing unreachable block (ram,0x080485b8)

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
  __isoc99_scanf(&DAT_08048ad0,local_10);
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



undefined4 store_number(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  printf(" Number: ");
  uVar1 = get_unum();
  printf(" Index: ");
  uVar2 = get_unum();
  if ((uVar2 % 3 == 0) || (uVar1 >> 0x18 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    uVar3 = 1;
  }
  else {
    *(uint *)(uVar2 * 4 + param_1) = uVar1;
    uVar3 = 0;
  }
  return uVar3;
}



undefined4 read_number(int param_1)

{
  int iVar1;
  
  printf(" Index: ");
  iVar1 = get_unum();
  printf(" Number at data[%u] is %u\n",iVar1,*(undefined4 *)(iVar1 * 4 + param_1));
  return 0;
}



undefined4 main(undefined4 param_1,int *param_2,int *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  char *pcVar7;
  byte *pbVar8;
  int in_GS_OFFSET;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  int *local_1c8;
  int *local_1c4;
  undefined4 local_1bc [100];
  undefined4 local_2c;
  byte local_28 [20];
  int local_14;
  
  bVar12 = 0;
  local_1c4 = param_2;
  local_1c8 = param_3;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_28[8] = 0;
  local_28[9] = 0;
  local_28[10] = 0;
  local_28[0xb] = 0;
  local_28[0xc] = 0;
  local_28[0xd] = 0;
  local_28[0xe] = 0;
  local_28[0xf] = 0;
  local_28[0x10] = 0;
  local_28[0x11] = 0;
  local_28[0x12] = 0;
  local_28[0x13] = 0;
  puVar6 = local_1bc;
  for (iVar3 = 100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (; *local_1c4 != 0; local_1c4 = local_1c4 + 1) {
    uVar4 = 0xffffffff;
    pcVar7 = (char *)*local_1c4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + (uint)bVar12 * -2 + 1;
    } while (cVar1 != '\0');
    memset((void *)*local_1c4,0,~uVar4 - 1);
  }
  for (; *local_1c8 != 0; local_1c8 = local_1c8 + 1) {
    uVar4 = 0xffffffff;
    pcVar7 = (char *)*local_1c8;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + (uint)bVar12 * -2 + 1;
    } while (cVar1 != '\0');
    memset((void *)*local_1c8,0,~uVar4 - 1);
  }
  puts(
      "----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
      );
  do {
    printf("Input command: ");
    local_2c = 1;
    fgets((char *)local_28,0x14,stdin);
    uVar4 = 0xffffffff;
    pbVar5 = local_28;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar2 = *pbVar5;
      pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
    } while (bVar2 != 0);
    uVar4 = ~uVar4;
    bVar9 = uVar4 == 1;
    bVar11 = uVar4 == 2;
    *(undefined1 *)((int)&local_2c + uVar4 + 2) = 0;
    iVar3 = 5;
    pbVar5 = local_28;
    pbVar8 = (byte *)"store";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pbVar5 < *pbVar8;
      bVar11 = *pbVar5 == *pbVar8;
      pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    bVar10 = false;
    bVar9 = (!bVar9 && !bVar11) == bVar9;
    if (bVar9) {
      local_2c = store_number(local_1bc);
    }
    else {
      iVar3 = 4;
      pbVar5 = local_28;
      pbVar8 = &DAT_08048d61;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar10 = *pbVar5 < *pbVar8;
        bVar9 = *pbVar5 == *pbVar8;
        pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
        pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
      } while (bVar9);
      bVar11 = false;
      bVar9 = (!bVar10 && !bVar9) == bVar10;
      if (bVar9) {
        local_2c = read_number(local_1bc);
      }
      else {
        iVar3 = 4;
        pbVar5 = local_28;
        pbVar8 = &DAT_08048d66;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar11 = *pbVar5 < *pbVar8;
          bVar9 = *pbVar5 == *pbVar8;
          pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
          pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
        } while (bVar9);
        if ((!bVar11 && !bVar9) == bVar11) {
          if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
            return 0;
          }
                    // WARNING: Subroutine does not return
          __stack_chk_fail();
        }
      }
    }
    if (local_2c == 0) {
      printf(" Completed %s command successfully\n",local_28);
    }
    else {
      printf(" Failed to do %s command\n",local_28);
    }
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    local_28[4] = 0;
    local_28[5] = 0;
    local_28[6] = 0;
    local_28[7] = 0;
    local_28[8] = 0;
    local_28[9] = 0;
    local_28[10] = 0;
    local_28[0xb] = 0;
    local_28[0xc] = 0;
    local_28[0xd] = 0;
    local_28[0xe] = 0;
    local_28[0xf] = 0;
    local_28[0x10] = 0;
    local_28[0x11] = 0;
    local_28[0x12] = 0;
    local_28[0x13] = 0;
  } while( true );
}



// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx
// WARNING: Removing unreachable block (ram,0x08048a30)
// WARNING: Removing unreachable block (ram,0x08048a38)

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



// WARNING: Removing unreachable block (ram,0x08048a91)
// WARNING: Removing unreachable block (ram,0x08048a98)

void __do_global_ctors_aux(void)

{
  return;
}



void _fini(void)

{
  __do_global_dtors_aux();
  return;
}

