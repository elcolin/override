
Dans cet exercice, le code du binaire nous demande un password et le converti en entier.
Ce nombre est ensuite passe a la fonction test() avec comme autre argument `0x1337d00d` (322424845)

test() calcule 0x1337d00d - our_input
si le resultat est superieur a 21 alors il appele decrypt avec notre input sinon il appelle decrypt avec un argument aleatoire.

decrypt initialise une chaine chiffre et effectue un XOR shift sur chaque caractere
```c
__builtin_strncpy(&var_21, "Q}|u`sfg~sf{}|a3", 0x11);
...
*(&var_21 + var_2c) ^= arg1;
```

Le resultat est ensuite compare avec `Congratulations!`

On va donc reverse ces transformations pour trouver le bon input

En soustrayant 21 de la valeur hexadécimale `0x1337d00d` (valeur `ch`), j'obtiens `322424824` comme seuil d'entrée.

on doit maintenant trouver quel j qui permet d'obternir `Congratulations!` quand on l'aditionne a chaque caractere de "Q}|u`sfg~sf{}|a3"
et qu'on le xor shift avec le caractere obtenu, on fait un script pour ca.

On obtient
```bash
15: ^rszo|ihq|itrsn<
16: Amlepcvwncvkmlq#
17: @lmdqbwvobwjlmp"
18: Congratulations!
19: Bnofs`utm`uhnor 
20: Eihatgrsjgroihu'
```
C'est donc 18 qui permet d'obtenir le mot de passe, on soustrait donc 18 a 322424845 -> 322424827

```bash
level03@OverRide:~$ ./level03 
***********************************
*               level03         **
***********************************
Password:322424827
$ cd ../level04
$ cat .pass
```
