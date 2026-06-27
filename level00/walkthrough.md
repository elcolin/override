
on voit qu'on a un binaire level00

quand on recupere l'executable avec `scp -P 4545 level00@localhost:~/level00 dest/level00/bin`
et quand on le decompile avec ghidra par exemple, on observe que le programme utilise scanf et compare notre input 5276 (149c en hexa).
On va juste ecrire 5276 quand le programme nous demande un password.

```bash
./level00
5276

cd /home/users/level01
cat .pass
```