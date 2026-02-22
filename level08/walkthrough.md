

quand on lance le programme, on dirait qu'il tente d'ouvrir un fichier qui a pour nom notre premier argument.

```bash
level08@OverRide:~$ ./level08 
Usage: ./level08 filename
ERROR: Failed to open (null)
level08@OverRide:~$ ./level08 test
ERROR: Failed to open test
```


Quand on regarde le code decompile, on se rend compte qu'il tente d'ouvrir le fichier a cet endroit:
```c
FILE* fp = fopen(argv[1], "r");
```

dans le code decompile on voit qu'il cherche a avoir acces a un dossier `backups`:

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

ce dossier est present dans le repertoire.

dans ce repertoire, on a pas les droits pour creer des fichiers, et c'est pour ca que le programme renvoie une erreur
donc on va chercher a reproduire cette architecture de dossier dans un repertoire ou on a des droits


