#include <stdlib.h>

struct stdyn {
    int *t; // pointer to dynamic array
    int size;
    int max;
};

typedef struct stdyn tdyn;

tdyn* init_tdyn() {
    tdyn *d = (tdyn *)malloc(sizeof(tdyn));

    d->size = 0;
    d->max = 1;
    d->t = (int *)malloc(d->max * sizeof(int));

    return d;
}

void insert_tdyn(tdyn *d, int val) {
    if (d->size == d->max) {
        d->max *= 2;
        d->t = (int *)realloc(d->t, d->max * sizeof(int));
    }
    d->t[d->size] = val;
    d->size++;
}