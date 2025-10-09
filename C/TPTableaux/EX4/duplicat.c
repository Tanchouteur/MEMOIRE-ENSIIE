//
// Created by louis.tanchou on 09/10/2025.
//
#include <stdio.h>

void f1 (char c[], char s[], char t[])
{
    //Concatener s et t dans c
    int i = 0;
    while (s[i] != '\0')
    {
        c[i] = s[i];
        i++;
    }
    int j = 0;
    while (t[j] != '\0')
    {
        c[i] = t[j];
        i++;
        j++;
    }
}

void f2(char c[], char s[], int n)
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        j = 0;
        while (s[j] != '\0')
        {
            c[i * (j + 1) + j] = s[j];
            j++;
        }
        i++;
    }
}