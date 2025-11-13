#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 // taille du tableau 10x10

// ================================
// STRUCTURE DE BASE
// ================================
typedef struct stdyn {
    int ***t;   // pointeur vers un tableau d'états, chaque état est un tableau 10x10
    int size;   // nombre d'états valides (taille effective)
    int max;    // taille maximale allouée
    int current; // position actuelle dans l'historique (pour undo/redo)
} tdyn;

// ================================
// INITIALISATION
// ================================
tdyn init() {
    tdyn td;
    td.size = 0;
    td.max = 1;
    td.current = -1;
    td.t = malloc(td.max * sizeof(int **));
    if (!td.t) {
        perror("Erreur malloc");
        exit(EXIT_FAILURE);
    }
    return td;
}

// ================================
// ALLOCATION D'UN TABLEAU 10x10
// ================================
int **alloc_tableau() {
    int **tab = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        tab[i] = calloc(N, sizeof(int)); // initialise à 0
    }
    return tab;
}

// ================================
// COPIE D'UN TABLEAU 10x10
// ================================
int **copier_tableau(int **src) {
    int **dest = alloc_tableau();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dest[i][j] = src[i][j];
    return dest;
}

// ================================
// INSÉRER UN NOUVEL ÉTAT
// ================================
void insert(tdyn *td, int **tab) {
    // Si on a annulé puis qu’on fait un nouvel edit, on efface les états futurs
    if (td->current < td->size - 1) {
        for (int i = td->current + 1; i < td->size; i++) {
            for (int r = 0; r < N; r++) free(td->t[i][r]);
            free(td->t[i]);
        }
        td->size = td->current + 1;
    }

    // Agrandir le tableau si nécessaire
    if (td->size == td->max) {
        td->max *= 2;
        td->t = realloc(td->t, td->max * sizeof(int **));
    }

    td->t[td->size] = copier_tableau(tab);
    td->size++;
    td->current = td->size - 1;
}

// ================================
// AFFICHER LE DERNIER TABLEAU
// ================================
void print(tdyn td) {
    if (td.size == 0) {
        printf("(tableau vide)\n");
        return;
    }
    int **tab = td.t[td.current];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ================================
// MODIFIER UNE CASE ET SAUVER L'ÉTAT
// ================================
void edit(tdyn *td, int i, int j, int k) {
    int **nouveau;
    if (td->size == 0)
        nouveau = alloc_tableau();
    else
        nouveau = copier_tableau(td->t[td->current]);

    if (i >= 0 && i < N && j >= 0 && j < N)
        nouveau[i][j] = k;

    insert(td, nouveau);

    for (int r = 0; r < N; r++) free(nouveau[r]);
    free(nouveau);
}

// ================================
// DEMANDER À L'UTILISATEUR UNE MODIFICATION
// ================================
void ask(tdyn *td) {
    int i, j, k;
    printf("Entrez i, j, k : ");
    if (scanf("%d %d %d", &i, &j, &k) == 3) {
        edit(td, i, j, k);
    } else {
        printf("Entrée invalide.\n");
        while (getchar() != '\n'); // vider le buffer
    }
}

// ================================
// ANNULER LA DERNIÈRE ACTION (CTRL+Z)
// ================================
void ctrlz(tdyn *td) {
    if (td->current > 0)
        td->current--;
    else
        printf("Aucune action à annuler.\n");
}

// ================================
// REFAIRE LA DERNIÈRE ACTION ANNULÉE (CTRL+Y)
// ================================
void ctrly(tdyn *td) {
    if (td->current < td->size - 1)
        td->current++;
    else
        printf("Aucune action à refaire.\n");
}

// ================================
// BOUCLE PRINCIPALE
// ================================
void boucle() {
    tdyn td = init();
    char choix;

    printf("Commandes : [e]dit, [z] annuler, [y] refaire, [q] quitter\n");

    do {
        print(td);
        printf("Action ? ");
        scanf(" %c", &choix);

        switch (choix) {
            case 'e':
                ask(&td);
                break;
            case 'z':
                ctrlz(&td);
                break;
            case 'y':
                ctrly(&td);
                break;
            case 'q':
                printf("Fin du programme.\n");
                break;
            default:
                printf("Commande inconnue.\n");
        }

    } while (choix != 'q');

    // Libération mémoire
    for (int i = 0; i < td.size; i++) {
        for (int r = 0; r < N; r++)
            free(td.t[i][r]);
        free(td.t[i]);
    }
    free(td.t);
}

// ================================
// MAIN
// ================================
int main() {
    boucle();
    return 0;
}
