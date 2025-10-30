//
// Created by louis.tanchou on 30/10/2025.
//

#include <stdio.h>
#include <stdlib.h>

void minmax(int n, int* tab, int* min, int* max) {
    int mintemp = tab[0];
    int maxtemp = tab[0];
    for (int i = 0; i<n; i++)
    {
        if (tab[i]>maxtemp){
            maxtemp = tab[i];
        }
        if (tab[i]<mintemp){
            mintemp = tab[i];
        }
    }

    *min = mintemp;
    *max = maxtemp;
}

int main()
{
    int n = 4;
    int *tab = malloc(n*sizeof(int));
    for (int i = 0; i<n; i++)
    {
        tab[i] = i;
    }

    int *min = malloc(sizeof(int));
    int *max = malloc(sizeof(int));
    minmax(n, tab, min, max);

    printf("min : %d, max %d", *min, *max);

    free(tab);
    free(min);
    free(max);
}