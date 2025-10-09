//
// Created by louis.tanchou on 09/10/2025.
//

#include <stdio.h>
#include <stdlib.h>

int isInTab(int *tab, int size, int m) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == m) {
            return 1;
        }
    }
    return 0;
}