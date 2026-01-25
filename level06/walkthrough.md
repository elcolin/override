
dans ce programme on nous demande un login et un mot de passe / nombre,

le login on voit qu'il doit faire + de 5 caracteres

ce morceau la : `if(ptrace(0x0, 0x0, 0x1, 0x0) == -1)` protege contre gdb !

ptrace() retourne -1 si le programme est déjà tracé (par gdb par exemple)

une fonction transforme le login en serial number (password)

soit on tente de reverse engineerer la methode de creation de serial number:

```c
var_2 = login[i] ^ var_1
var_3 = var_2 * 0x88233b2b >> 32
var_1 += var_2 - (((((var_2 - var_3) >> 1) + var_3) >> 0xa) * 0x539)

 if(serial == var_1)
```

soit on tente de changer la valeur de retour de ptrace().

-> spoiler, c'est ce qu'on fait

```bash
gdb ./level06
```
```
disas auth
...
0x080487b5 <+109>:	call   0x80485f0 <ptrace@plt>
0x080487ba <+114>:	cmp    $0xffffffff,%eax
...
break *0x080487ba
```
comme ca on met un breakpoint sur l'instruction juste apres ptrace !

On met aussi un breakpoint au niveau de la comparaison de `var_1` avec notre input.

```
0x08048866 <+286>:	cmp    -0x10(%ebp),%eax
0x08048869 <+289>:	je     0x8048872 <auth+298>
(gdb) break *0x08048866
```

maintenant on run,
on met un login genre pcheron (+ de 5 caracteres)
un serial dont on se fou

```bash
Breakpoint 1, 0x080487ba in auth ()
(gdb) set $eax=0
(gdb) c
Continuing.

Breakpoint 2, 0x08048866 in auth ()

(gdb) info registers eax
eax            0x7b	123

(gdb) x/wd $ebp-0x10
0xffffd6a8:	6233795

```

maintenant on sait que pour le login `pcheron` on sait que le serail correspondant est `6233795`

on lance maintenant le programme avec le meme login et notre nouveau serial (plus besoin de gdb).

