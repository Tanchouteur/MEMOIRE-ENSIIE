//
// Created by louis.tanchou on 09/10/2025.
//

#include <stdio.h>
#include <string.h>

void f1(char tab[])
{
    for (int i = 0; i < strlen(tab); i++)
    {
        printf("%c", tab[i]);
    }
}

void f2(char tab[])
{
    int i = 0;
    while (tab[i] != '\0')
    {
        printf("%c", tab[i]);
        i++;
    }
}
