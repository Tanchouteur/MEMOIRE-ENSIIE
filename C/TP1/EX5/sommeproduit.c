//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Entrez trois entiers : ");
    scanf("%d %d %d", &a, &b, &c);
    printf("La somme des trois entiers est : %d", a + b + c);
    printf("   Le produit des trois entiers est : %d", a * b * c);
    return 0;
}