#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
    int valeur;
    Element *suivant;
};

typedef struct File File;
struct File {
    Element *sommet;
    Element *queue;
};

File* initialisationFile() {
    File *f = malloc(sizeof(*f));
    f->sommet = NULL;
    f->queue = NULL;
    return f;
}

void enfiler(File *f, int val) {
    Element *e = malloc(sizeof(*e));
    e->valeur = val;
    e->suivant = NULL;

    if (f->sommet == NULL)
        f->sommet = f->queue = e;
    else {
        f->queue->suivant = e;
        f->queue = e;
    }
}

int defiler(File *f) {
    if (f->sommet == NULL) return -1;
    Element *tmp = f->sommet;
    int v = tmp->valeur;
    f->sommet = tmp->suivant;
    if (f->sommet == NULL) f->queue = NULL;
    free(tmp);
    return v;
}

void afficherFile(File *f) {
    Element *tmp = f->sommet;
    printf("File : ");
    while (tmp != NULL) {
        printf("%d ", tmp->valeur);
        tmp = tmp->suivant;
    }
    printf("\n");
}

// nombre d'éléments dans une file
int tailleFile(File *f) {
    int c = 0;
    Element *tmp = f->sommet;
    while (tmp != NULL) {
        c++;
        tmp = tmp->suivant;
    }
    return c;
}

//testes si deux  files sont identiques
int filesIdentiques(File *f1, File *f2) {
    Element *e1 = f1->sommet;
    Element *e2 = f2->sommet;

    while (e1 != NULL && e2 != NULL) {
        if (e1->valeur != e2->valeur) return 0;
        e1 = e1->suivant;
        e2 = e2->suivant;
    }
    return (e1 == NULL && e2 == NULL);
}

int main() {
    File *f = initialisationFile();

    enfiler(f, 10);
    enfiler(f, 20);
    enfiler(f, 30);

    printf("Defiler : %d\n", defiler(f));

    afficherFile(f);
}
