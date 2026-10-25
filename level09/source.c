#include "out.h"


undefined __libc_csu_init;
undefined main;
undefined __libc_csu_fini;
undefined1 completed.6531;
undefined8 dtor_idx.6533;
pointer __dso_handle;
undefined stdin;

int _init(EVP_PKEY_CTX *ctx) {
  int iVar1;
  
  call_gmon_start();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}



void FUN_00100710(void) {
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * strncpy(char *__dest,char *__src,size_t __n) {
  char *pcVar1;
  
  pcVar1 = strncpy(__dest,__src,__n);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s) {
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int system(char *__command) {
  int iVar1;
  
  iVar1 = system(__command);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...) {
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



void __libc_start_main(void) {
  __libc_start_main();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream) {
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



void __cxa_finalize(void) {
  __cxa_finalize();
  return;
}



void processEntry _start(undefined8 param_1,undefined8 param_2) {
  undefined1 auStack_8 [8];
  
  __libc_start_main(main,param_2,&stack0x00000008,__libc_csu_init,__libc_csu_fini,param_1,auStack_8)
  ;
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void call_gmon_start(void) {
  __gmon_start__();
  return;
}



// WARNING: Removing unreachable block (ram,0x0010082b)
// WARNING: Removing unreachable block (ram,0x00100830)

void __do_global_dtors_aux(void) {
  if (completed_6531 == '\0') {
    __cxa_finalize(__dso_handle);
    completed_6531 = '\x01';
  }
  return;
}

void frame_dummy(void) {
  return;
}

void secret_backdoor(void) {
  char local_88 [128];
  
  fgets(local_88,0x80,_stdin);
  system(local_88);
  return;
}

void handle_msg(void) {
  undefined1 local_c8 [140];
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 0x8c;
  set_username(local_c8);
  set_msg(local_c8);
  puts(">: Msg sent!");
  return;
}

void set_msg(char *param_1) {
  long lVar1;
  char *pcVar2;
  char local_408 [1024];
  
  pcVar2 = local_408;
  for (lVar1 = 0x80; lVar1 != 0; lVar1 = lVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2[4] = '\0';
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    pcVar2 = pcVar2 + 8;
  }
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(local_408,0x400,_stdin);
  strncpy(param_1,local_408,(long)*(int *)(param_1 + 0xb4));
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void set_username(long param_1) {
  long lVar1;
  char *pcVar2;
  char local_98 [140];
  int local_c;
  
  pcVar2 = local_98;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2[4] = '\0';
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    pcVar2 = pcVar2 + 8;
  }
  puts(">: Enter your username");
  printf(">>: ");
  fgets(local_98,0x80,_stdin);
  for (local_c = 0; (local_c < 0x29 && (local_98[local_c] != '\0')); local_c = local_c + 1) {
    *(char *)(param_1 + 0x8c + (long)local_c) = local_98[local_c];
  }
  printf(">: Welcome, %s",param_1 + 0x8c);
  return;
}



undefined8 main(void) {
  puts(
      "--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------"
      );
  handle_msg();
  return 0;
}

void __libc_csu_init(EVP_PKEY_CTX *param_1) {
  _init(param_1);
  return;
}

void __libc_csu_fini(void) {
  return;
}

void __do_global_ctors_aux(void) {
  return;
}

void _fini(void) {
  __do_global_dtors_aux();
  return;
}
