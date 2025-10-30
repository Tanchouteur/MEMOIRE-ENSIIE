//
// Created by louis.tanchou on 30/10/2025.
//

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float* loglist(int n)
{
    float* f = malloc(n*sizeof(float));

    for (int i=0; i<n;i++)
    {
        f[i] = log(i);
    }

    return f;
}

int main()
{
    const int n = 4;

    float *p = loglist(n);

    free(p);
}