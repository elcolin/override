
username et message demande

```bash
./level09 Pablo
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: Wasaaaaa    
>: Welcome, Wasaaaaa
>: Msg @Unix-Dude

```


```c
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
```


fgets 128 dans un buffer de 40
    -> on peut ecraser la taille max du message copie (strncp)
    -> 

grace a strncpy on ecrase return eip avec l'adresse de secret_backdoor

```bash
    (gdb) info function secret_backdoor
    All functions matching regular expression "secret_backdoor":

    Non-debugging symbols:
    0x000000000000088c  secret_backdoor
```
