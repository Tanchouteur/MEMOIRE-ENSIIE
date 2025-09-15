//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>
int main()
{
    int r;
    double pi = 3.14;
    printf("Entrez la valeur de r : ");
    scanf("%d", &r);
    printf("La surface de la sphere est : %f \n", 4 * pi * r * r);
    printf("La volume de la sphere est : %f", 4 / 3 * pi * r * r * r);
    return 0;
}