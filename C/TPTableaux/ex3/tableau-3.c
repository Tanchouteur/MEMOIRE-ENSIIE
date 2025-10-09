//
// Created by louis.tanchou on 09/10/2025.
//
#include <stdio.h>

int isInTab(int *tab, int size, int m) {
    int a = 0;
    int b = size - 1;
    int mid = 0;

    while (a <= b){
        mid = (a + b) / 2;
        if (tab[mid] == m){
            return 1;
        }else if (tab[mid] < m){
            a = mid + 1;
        }else {
            b = mid - 1;
        }
    }
    return 0;
}

void replaceInvertedTab(int tab[], int tab2[],int size)
{
    for (int i = size-1; i >= 0; i--)
    {
        tab2[size-1-i] = tab[i];
    }
}

void invertTab(int tab[],int size)
{
    for (int i = (size-1)/2; i >= 0; i--)
    {
        int temp = tab[size - 1 - i];
        tab[size-1-i] = tab[i];
        tab[i] = temp;
    }
}

void f (int x) {
    x = 1;
}

void g ( int t []) {
    t [0] = 1;
}

int main ( void ) {
    int x = 3;
    f ( x ) ;
    int t [1];
    t [0] = 3;
    g ( t ) ;
    printf ( " %d \n " , x ) ;
    printf ( " %d \n " , t [0]) ;

    int tab [] = {1, 3, 5, 7, 9};
    int tab2 [] = {1, 3, 5, 7, 9};

    int size = 5;
    int m = 5;
    if (isInTab(tab, size, m)) {
        printf("%d is in the table.\n", m);
    } else
    {
        printf("%d is not in the table.\n", m);
    }

    invertTab(tab, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
}