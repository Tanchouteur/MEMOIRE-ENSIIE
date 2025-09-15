//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x;
    printf("Entrez un entier : ");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {

        printf("\n");
        for (int j = 0; j < x; j++)
        {
            if (j == 0 || j == x - 1 || i == 0 || i == x - 1)
            {
                printf("*");
            }else
            {
                printf(" ");
            }
        }
    }
    return 0;
}