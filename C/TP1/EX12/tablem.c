//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>

int main()
{
    int m;
    printf("Entrez un entier : ");
    scanf("%d", &m);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", m, i, m * i);
    }
}