# TP1

Compiller avec gcc
```bash
cc -Wall -Wextra -std=c99 -o helloWorld helloWorld.c
```
compiler avec la lib math
ajouter `#include <math.h>` en haut de votre fichier.
— ajouter -lm `a la fin de la commande pour compiler avec gcc ; ce qui donne 
```bash
gcc -Wall -Wextra -std=c99 -o sortie file.c -lm
```