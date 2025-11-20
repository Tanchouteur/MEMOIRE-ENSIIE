//
// Created by louis.tanchou on 20/11/2025.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double logharithme(double x, int i, double l)
{
    if (x <= 0 || x>= 1)
    {
        exit(-1);
    }

    if ((pow(x,i))/i < 0.001)
    {
        return l;
    }else
    {
        return l + logharithme(x, i+1, (pow(x,i))/i);
    }
}

double lognonrecurcive(double x)
{
    if (x <= 0 || x>= 1)
    {
        exit(-1);
    }

    double l = 0.;
    int i = 1;
    while ((pow(x,i))/i >= 0.001)
    {
        l += (pow(x,i))/i;
        i++;
    }
    return l;
}

int main(int argc, char *argv[])
{
    double x = 0.5;
    double result = logharithme(x,1,0);
    printf("Logarithme recursif: %f\n", result);

    double result2 = lognonrecurcive(x);
    printf("Logarithme non recursif: %f\n", result2);

    return 0;
}