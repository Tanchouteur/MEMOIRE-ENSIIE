//
// Created by louis.tanchou on 20/11/2025.
//

#include <stdio.h>
#include <stdlib.h>

int dichotomic(int min, int max, int* tab, int value)
{
    if (max<=min || tab==NULL) {
        return -1;
    }
    if (tab[max] == value)
    {
        return max;
    }


    if (tab[(min+max)/2] == value) { // Condition d'arret
        return (min+max)/2;

    } else if (tab[(min+max)/2] < value) {
        return dichotomic((min+max)/2 + 1, max, tab, value);
    } else {
        return dichotomic(min, (min+max)/2 - 1, tab, value);
    }
}

int main() {
    int tab[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int value = 1;
    int result = dichotomic(0, 9, tab, value);
    if (result != -1) {
        printf("Value %d found at index %d\n", value, result);
    } else {
        printf("Value %d not found in the array\n", value);
    }
    return 0;
}