
dans ce programme on nous demande un login et un mot de passe / nombre,
Le login doit faire + de 5 caracteres
Une fonction determine un serial number a partir de notre login
Notre password doit correspondre au serial qu'il on trouve a partir de notre login/

ce morceau la : `if(ptrace(0x0, 0x0, 0x1, 0x0) == -1)` protege contre gdb !
ptrace() retourne -1 si le programme est déjà tracé (par gdb par exemple)

On va quand meme utiliser gdb mais en essayant de skip l'instruction ptrace.
Apres, on pourra acceder a la valeur serial qui est comparee avec notre password.

```bash
(gdb) disas auth
...
0x08048791 <+73>:    jmp    0x8048877 <auth+303>
   0x08048796 <+78>:    movl   $0x0,0xc(%esp)
   0x0804879e <+86>:    movl   $0x1,0x8(%esp)
   0x080487a6 <+94>:    movl   $0x0,0x4(%esp)
   0x080487ae <+102>:   movl   $0x0,(%esp)
   0x080487b5 <+109>:   call   0x80485f0 <ptrace@plt>
   0x080487ba <+114>:   cmp    $0xffffffff,%eax
---Type <return> to continue, or q <return> to quit---r
   0x080487bd <+117>:   jne    0x80487ed <auth+165>
   0x080487bf <+119>:   movl   $0x8048a68,(%esp)
   0x080487c6 <+126>:   call   0x8048590 <puts@plt>
   0x080487cb <+131>:   movl   $0x8048a8c,(%esp)
   0x080487d2 <+138>:   call   0x8048590 <puts@plt>
   0x080487d7 <+143>:   movl   $0x8048ab0,(%esp)
   0x080487de <+150>:   call   0x8048590 <puts@plt>
   0x080487e3 <+155>:   mov    $0x1,%eax
   0x080487e8 <+160>:   jmp    0x8048877 <auth
...
   0x08048866 <+286>:   cmp    -0x10(%ebp),%eax
---Type <return> to continue, or q <return> to quit---
   0x08048869 <+289>:   je     0x8048872 <auth+298>
   0x0804886b <+291>:   mov    $0x1,%eax
   0x08048870 <+296>:   jmp    0x8048877 <auth+303>
   0x08048872 <+298>:   mov    $0x0,%eax
   0x08048877 <+303>:   leave  
   0x08048878 <+304>:   ret 
break *0x080487ba
run
...
set $eax = 0
break *0x08048866
continue
print *(int*)($ebp - 0x10)
$2 = 6233795
```

maintenant on a le mot de passe attendu pour le user pcheron

```bash
./level06
***********************************
*               level06           *
***********************************
-> Enter Login: pcheron
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6233795
Authenticated!
$ cd ..
$ cd level07
$ cat .pass
```

