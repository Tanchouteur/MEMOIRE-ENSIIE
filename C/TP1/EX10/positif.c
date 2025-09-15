//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>
int main()
{
    int x;
    printf("Entrez un entier : ");
    scanf("%d", &x);
    if (x > 0)
    {
        printf("Le nombre est positif\n");
    }else if (x < 0)
    {
        printf("Le nombre est negatif\n");
    }else
    {
        printf("Le nombre est nul\n");
    }
}