//
// Created by louis.tanchou on 30/10/2025.
//

#include <stdio.h>

void echange(int *a, int *b, int *c) {
    int temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;
}