//
// Created by louis.tanchou on 20/11/2025.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned long long int ulli;

int pgcdrec(ulli a, ulli b, int i)
{

    if (a%i == 0 && b%i ==0)
    {
        return i;
    }else
    {
        return pgcdrec(a,b,i-1);
    }
}

int main(int argc, char *argv[])
{
    ulli a = (ulli) 2;
    ulli b = (ulli) 9000000000000000000;

    ulli min = a < b ? a : b;

    int result = pgcdrec(a,b,min);
    printf("PGCD recursif: %d\n", result);

    return 0;
}