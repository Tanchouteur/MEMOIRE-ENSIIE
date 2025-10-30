//
// Created by louis.tanchou on 30/10/2025.
//

#include <stdio.h>
#include <stdlib.h>

int* initfin()
{
    int* temp = malloc(sizeof(int));
    *temp = 0;
    return temp;
}

void free2(void* p)
{
    free(p);
}