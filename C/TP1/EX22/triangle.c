//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>

void row(int *i)
{
    for (int j = 0; j < *i-2; j++)
    {
        if (j == 0 || j == *i-2 - 1 || *i-2 == 0 )
        {
            printf("*");
        }else
        {
            printf(" ");
        }
    }
}

int main(int argc, char *argv[])
{
    int n;
    printf("Entrez les dimensions du triangle : ");
    scanf("%d", &n);
    int x = 2*n-1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < x-1; j++)
            {
                printf("*");
            }
        }else
        {
            row(&x);
            x = x-2;
        }
        printf("\n");
    }
    return 0;
}