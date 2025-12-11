#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
    int valeur;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile {
    Element *sommet;
};

// Création pile
Pile* initialisationPile() {
    Pile *p = malloc(sizeof(*p));
    p->sommet = NULL;
    return p;
}

// Empiler
void empiler(Pile *pile, int val) {
    Element *e = malloc(sizeof(*e));
    e->valeur = val;
    e->suivant = pile->sommet;
    pile->sommet = e;
}

// Depiler
int depiler(Pile *pile) {
    if (pile->sommet == NULL) return -1;
    Element *tmp = pile->sommet;
    int v = tmp->valeur;
    pile->sommet = tmp->suivant;
    free(tmp);
    return v;
}

// Afficher
void afficherPile(Pile *pile) {
    Element *tmp = pile->sommet;
    printf("Pile : ");
    while (tmp != NULL) {
        printf("%d ", tmp->valeur);
        tmp = tmp->suivant;
    }
    printf("\n");
}

// Taille pile
int taillePile(Pile *pile) {
    int c = 0;
    Element *tmp = pile->sommet;
    while (tmp != NULL) {
        c++;
        tmp = tmp->suivant;
    }
    return c;
}

// Comparer deux piles
int pilesIdentiques(Pile *p1, Pile *p2) {
    Element *e1 = p1->sommet;
    Element *e2 = p2->sommet;

    while (e1 != NULL && e2 != NULL) {
        if (e1->valeur != e2->valeur) return 0;
        e1 = e1->suivant;
        e2 = e2->suivant;
    }
    return (e1 == NULL && e2 == NULL);
}

int main() {
    Pile *p = initialisationPile();
    int choix, x;

    do {
        printf("\n1- Empiler\n2- Depiler\n3- Quitter\n");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Entrer valeur : ");
            scanf("%d", &x);
            empiler(p, x);
        }
        else if (choix == 2) {
            printf("Depilé : %d\n", depiler(p));
        }

    } while (choix != 3);

    afficherPile(p);
    return 0;
}
