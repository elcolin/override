
On va exploiter une vulnerabilite au niveau de `gets()`, cette fonction ne protege pas contre les overflow.

Le programme peut recevoir du shellcode mais va bloquer l'utilisation de `execve()` car le process parent tue l'enfant si il execute `execve()`.

char buf[0x80];  // 128 bytes à l'adresse ebp-0x88
int32_t var_18;  // 4 bytes
int32_t stat_loc; // 4 bytes

EBP // 4 bytes
EIP // 4 bytes

On va quand meme verifier l'offset.

On a `eip` = `0x41326641` quand on fait crash le programme avec un overflow:

```bash
run < <(python -c 'print "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag"')
```

`0x41326641` correspond a la sequence `Af2A`, qui correspond a un offset de 156 characteres.

