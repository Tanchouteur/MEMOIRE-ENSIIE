//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>

int main()
{
    int m1, m2, d;
    double g = 6.67e-10;

    printf("Entrez la masse du premier objet (en kg) : ");
    scanf("%d", &m1);

    printf("Entrez la masse du second objet (en kg) : ");
    scanf("%d", &m2);

    printf("Entrez la distance entre les deux objets (en m) : ");
    scanf("%d", &d);

    double fg = g*m1*m2/(d*d);
    printf("La force de gravite entre les deux objets est de %.2e N\n", fg);
}