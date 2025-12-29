
Le programme demande un input,

quand on recupere l'executable avec `scp -P 4545 level00@localhost:~/level01 dest/level00`
et quand on le decompile avec ghidra par exemple, on observe que notre input est compare avec 5276.
On va juste ecrire 5276 comme entree utilisateur.

```bash
./level00
5276

cd /home/users/level01
cat .pass
```