
main() demande un password (un entier)
Il appelle test(v1, 0x1337d00d) où v1 est le password entré
test() calcule ch - arg1 (soit 0x1337d00d - password)
Si le résultat est > 21, il appelle decrypt() avec un argument aléatoire
Sinon, il calcule une adresse et appelle decrypt() avec

Dans decrypt():

Il y a un tableau initialisé avec des valeurs
Il effectue un XOR sur chaque caractère avec tab[1] (0x67667360)
Il compare le résultat avec "Congratulations!"
Si ça correspond, il lance /bin/sh

On cherche le code qui donne `Congratulations!` apres le XOR shift.

En soustrayant 21 de la valeur hexadécimale `0x1337d00d` (valeur `ch`), j'obtiens `322424824` comme seuil d'entrée.

on peut tester 
```bash
"Q}|u`sfg~sf{}|a3" ^OR

```

On va utiliser un script pour ca.
Passer la cle 18 a decrypt.
0x1337d00d + 18


0x804885a
user input
no overflow

    test(v1, 322424845);
    a0 = v1
    a1 = 322424845

v0 = a1 - a0
v0 = 322424845 - v1