#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// =======================
// STRUCTURE DU VECTEUR
// =======================
typedef struct {
    int n;        // dimension du vecteur
    double *val;  // tableau dynamique des coordonnées
} Vecteur;

Vecteur creer_vecteur(int n) {
    Vecteur v;
    v.n = n;
    v.val = calloc(n, sizeof(double)); // initialise à 0
    return v;
}

void augmenter_dimension(Vecteur *v, int nouvelle_dim) {
    if (nouvelle_dim <= v->n) return; // rien à faire
    v->val = realloc(v->val, nouvelle_dim * sizeof(double));
    for (int i = v->n; i < nouvelle_dim; i++)
        v->val[i] = 0.0;
    v->n = nouvelle_dim;
}

void modifier_coord(Vecteur *v, int i, double valeur) {
    if (i >= v->n)
        augmenter_dimension(v, i + 1);
    v->val[i] = valeur;
}

void afficher_vecteur(Vecteur v) {
    printf("(");
    for (int i = 0; i < v.n; i++) {
        printf("%.2f", v.val[i]);
        if (i < v.n - 1) printf(", ");
    }
    printf(")\n");
}

double norme(Vecteur v) {
    double somme = 0;
    for (int i = 0; i < v.n; i++)
        somme += v.val[i] * v.val[i];
    return sqrt(somme);
}

void normaliser(Vecteur *v) {
    double n = norme(*v);
    if (n == 0) return;
    for (int i = 0; i < v->n; i++)
        v->val[i] /= n;
}

Vecteur copier_vecteur(Vecteur v) {
    Vecteur copie = creer_vecteur(v.n);
    for (int i = 0; i < v.n; i++)
        copie.val[i] = v.val[i];
    return copie;
}

Vecteur somme(Vecteur v1, Vecteur v2) {
    int n = (v1.n > v2.n) ? v1.n : v2.n;
    Vecteur res = creer_vecteur(n);
    for (int i = 0; i < n; i++) {
        double a = (i < v1.n) ? v1.val[i] : 0;
        double b = (i < v2.n) ? v2.val[i] : 0;
        res.val[i] = a + b;
    }
    return res;
}

void somme_inplace(Vecteur *v1, Vecteur v2) {
    if (v2.n > v1->n)
        augmenter_dimension(v1, v2.n);
    for (int i = 0; i < v1->n; i++) {
        double b = (i < v2.n) ? v2.val[i] : 0;
        v1->val[i] += b;
    }
}

Vecteur produit_reel(Vecteur v, double a) {
    Vecteur res = creer_vecteur(v.n);
    for (int i = 0; i < v.n; i++)
        res.val[i] = v.val[i] * a;
    return res;
}

void produit_reel_inplace(Vecteur *v, double a) {
    for (int i = 0; i < v->n; i++)
        v->val[i] *= a;
}

double produit_scalaire(Vecteur v1, Vecteur v2) {
    int n = (v1.n > v2.n) ? v1.n : v2.n;
    double somme = 0;
    for (int i = 0; i < n; i++) {
        double a = (i < v1.n) ? v1.val[i] : 0;
        double b = (i < v2.n) ? v2.val[i] : 0;
        somme += a * b;
    }
    return somme;
}

void rotation2D(Vecteur *v, double alpha) {
    if (v->n < 2) return; // nécessite un vecteur 2D
    double x = v->val[0];
    double y = v->val[1];
    v->val[0] = x * cos(alpha) - y * sin(alpha);
    v->val[1] = x * sin(alpha) + y * cos(alpha);
}

// =======================
// STRUCTURE DE LA TORTUE
// =======================
typedef struct {
    Vecteur position;   // position (x, y)
    Vecteur direction;  // direction (dx, dy)
    bool stylo_pose;    // stylo en bas ?
} Tortue;

#define N 11  // taille de la grille (impair)
char grille[N][N];

void init_grille() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grille[i][j] = '.';
}

void afficher_grille(Tortue t) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if ((int)round(t.position.val[0]) == x && (int)round(t.position.val[1]) == y)
                printf(">");
            else
                printf("%c", grille[y][x]);
        }
        printf("\n");
    }
}

Tortue creer_tortue() {
    Tortue t;
    t.position = creer_vecteur(2);
    t.direction = creer_vecteur(2);

    modifier_coord(&t.position, 0, N / 2);
    modifier_coord(&t.position, 1, N / 2);
    modifier_coord(&t.direction, 0, 0);
    modifier_coord(&t.direction, 1, -1);

    t.stylo_pose = false;
    return t;
}

void draw(Tortue *t)
{
    if (t->stylo_pose) {
        int x = (int)round(t->position.val[0]);
        int y = (int)round(t->position.val[1]);
        if (x >= 0 && x < N && y >= 0 && y < N)
            grille[y][x] = 'X';
    }
}

void stylo_bas(Tortue *t) {
    t->stylo_pose = true;
    draw(t);
}

void stylo_haut(Tortue *t) {
    t->stylo_pose = false;
}

void tourner(Tortue *t, double angle_deg) {
    double angle_rad = angle_deg * M_PI / 180.0;
    rotation2D(&t->direction, angle_rad);
    normaliser(&t->direction);
}

void avancer(Tortue *t, int pas) {
    for (int i = 0; i < pas; i++) {
        draw(t);

        t->position.val[0] += t->direction.val[0];
        t->position.val[1] += t->direction.val[1];
    }
}

// =======================
// PROGRAMME PRINCIPAL
// =======================
int main() {
    init_grille();
    Tortue t = creer_tortue();

    afficher_grille(t);
    getchar();

    // Tourner à droite de 90°
    tourner(&t, 90);

    // Poser le stylo
    stylo_bas(&t);

    // Avancer de 3
    avancer(&t, 3);
    afficher_grille(t);
    getchar();

    // Tourner à gauche de 90°
    tourner(&t, -90);

    // Lever le stylo
    stylo_haut(&t);

    // Avancer de 2
    avancer(&t, 2);
    afficher_grille(t);
    getchar();

    // Tourner à gauche de 90°
    tourner(&t, -90);

    // Poser le stylo
    stylo_bas(&t);
    afficher_grille(t);
    getchar();

    return 0;
}
