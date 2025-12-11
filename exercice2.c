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

// Fonctions de base
Pile* initialisationPile() {
    Pile *p = malloc(sizeof(*p));
    p->sommet = NULL;
    return p;
}

void empiler(Pile *pile, int val) {
    Element *e = malloc(sizeof(*e));
    e->valeur = val;
    e->suivant = pile->sommet;
    pile->sommet = e;
}

int depiler(Pile *pile) {
    if (pile->sommet == NULL) return -1;
    Element *tmp = pile->sommet;
    int v = tmp->valeur;
    pile->sommet = tmp->suivant;
    free(tmp);
    return v;
}

// 1) Inverser une pile avec une autre pile
void inverserPile(Pile *p) {
    Pile *tmp = initialisationPile();
    while (p->sommet != NULL)
        empiler(tmp, depiler(p));
    *p = *tmp;
}

// 2) Parenthèses équilibrées
int parenthesesEquilibrees(char *c) {
    Pile *p = initialisationPile();
    int i = 0;

    while (c[i] != '\0') {
        if (c[i] == '(') empiler(p, '(');
        else if (c[i] == ')') {
            if (p->sommet == NULL) return 0;
            depiler(p);
        }
        i++;
    }
    return p->sommet == NULL;
}

// 3) Parenthèses mathématiques imbriquées
int mathEquilibre(char *c) {
    Pile *p = initialisationPile();
    int i = 0;

    while (c[i] != '\0') {
        char x = c[i];
        if (x=='(' || x=='{' || x=='[')
            empiler(p, x);

        else if (x==')' || x=='}' || x==']') {
            if (p->sommet == NULL) return 0;
            char y = depiler(p);

            if ((x==')'&&y!='(') ||
                (x=='}'&&y!='{') ||
                (x==']'&&y!='[')) return 0;
        }
        i++;
    }

    return p->sommet == NULL;
}

// 4) Convertir entier en binaire
void binaire(int n) {
    Pile *p = initialisationPile();
    while (n > 0) {
        empiler(p, n % 2);
        n /= 2;
    }
    while (p->sommet != NULL)
        printf("%d", depiler(p));
    printf("\n");
}

// 5) Inverser une chaîne
void inverserChaine(char *c) {
    Pile *p = initialisationPile();
    int i = 0;
    while (c[i] != '\0') {
        empiler(p, c[i]);
        i++;
    }
    while (p->sommet != NULL)
        printf("%c", depiler(p));
    printf("\n");
}

int main() {
    printf("Test binaire de 13 : ");
    binaire(13);

    printf("\nTest chaine \"malick\" : ");
    inverserChaine("malick");

    printf("\nParentheses ()() : %d\n", parenthesesEquilibrees("(()())"));
    printf("Imbrication {[()]} : %d\n", mathEquilibre("{[()]}"));

    return 0;
}
