#include <stdio.h>
#include <stdlib.h>

int** pointeursType(int n, int *l)
{
    int *paire      = malloc((n+1)*sizeof(int));
    int *impaire    = malloc((n+1)*sizeof(int));

    int **p = malloc(2*sizeof(int*));

    for (int i=0;i<n;i++)
    {
        if (l[i]%2 == 0) //Paire
        {
            paire[++paire[0]]=l[i];
        }else            //Impaire
        {
            impaire[++impaire[0]]=l[i];
        }
    }

    realloc(paire, (paire[0]+1)*sizeof(int));
    realloc(impaire, (impaire[0]+1)*sizeof(int));

    p[0] = paire;
    p[1] = impaire;
    return p;
}

void printTabInt(int n, int *tab)
{
    printf("Tableau taille %d\n", n);
    for (int i=0; i<n;i++)
    {
        printf("tab[%d] = %d\n" ,i, tab[i]);
    }
    printf("\n");
}

int main()
{
    int n = 6;
    int *l = malloc(n*sizeof(int));
    for (int i = 0; i<n; i++) // Tableau {0,1,...,n}
    {
        l[i] = i;
    }

    int ** p = pointeursType(n, l);

    printTabInt(p[0][0], p[0]);
    printTabInt(p[1][0], p[1]);

    free(p);
    free(l);
}
