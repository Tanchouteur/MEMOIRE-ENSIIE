//
// Created by louis.tanchou on 15/09/2025.
//

#include <stdio.h>
int main()
{
    int x1, y1, x2, y2;
    printf("Entrez les coordonnée de deux point : ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("Point P1 : (%d, %d)\n", x1, y1 );
    printf("Point P2 : (%d, %d)\n", x2, y2 );
    printf("Le milieu est : (%d, %d)\n", (x1 + x2) / 2, (y1 + y2) / 2);
    return 0;
}